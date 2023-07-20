// g++ stack_unwind.cpp -o stack_unwind && ./stack_unwind

// In C++, stack unwinding is the process of destroying objects that were created
//  on the stack between the start of a try block and the point where an exception is
//   thrown. When an exception is thrown, control passes from the try block to the
//   first catch block that can handle the exception. During this process, all
//    automatic variables that are in scope between the throw and catch statements
//    are destroyed in a process that is known as stack unwinding .

#include <iostream>
#include <stdexcept>

struct A
{
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

struct Announce
{
    Announce(const char *s) : s(s) { std::cout << s << std::endl; }
    ~Announce() { std::cout << "~" << s << std::endl; }
    const char *s;
};

void func(int x)
{
    char *pleak = new char[1024]; // might be lost => memory leak
    std::string s("hello world"); // will be properly destructed
    A a;                          // will be properly destructed
    Announce ann("func");         // will be properly destructed

    if (x)
    {
        throw std::runtime_error("boom");
    }

    Announce ann2("after throw");
    delete[] pleak; // will only get here if x == 0. if x!=0, throw exception
}

int main()
{
    try
    {
        Announce ann("in try in main");
        func(10);
        Announce ann2("after func in main");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
