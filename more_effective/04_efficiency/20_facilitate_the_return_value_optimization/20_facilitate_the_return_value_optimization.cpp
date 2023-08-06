// g++ 20_facilitate_the_return_value_optimization.cpp -o 20_facilitate_the_return_value_optimization && ./20_facilitate_the_return_value_optimization

// clang++ foo.cpp -std=c++11 && ./a.out
// clang++ foo.cpp -std=c++11 -fno-elide-constructors && ./a.out

#include <iostream>
class Foo
{
public:
    Foo()
    {
        std::cout << "ctor called!" << std::endl;
    }
    ~Foo()
    {
        std::cout << "dtor called!" << std::endl;
    }
    Foo(const Foo &other)
    {
        std::cout << "copy ctor called!" << std::endl;
    }
    Foo(Foo &&other)
    {
        std::cout << "move ctor called!" << std::endl;
    }
};

Foo funcRVO()
{
    return Foo();
}
int main()
{
    std::cout << "------ RVO ------" << std::endl;
    Foo foo1 = funcRVO();
    std::cout << "-----------------" << std::endl;
    return 0;
}
