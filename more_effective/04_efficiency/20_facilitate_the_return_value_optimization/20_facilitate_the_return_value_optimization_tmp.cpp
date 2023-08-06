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

void func(Foo f)
{
    std::cout << "func called!" << std::endl;
}
int main()
{
    std::cout << "-----------------" << std::endl;
    func(Foo());
    std::cout << "-----------------" << std::endl;
    return 0;
}
