// g++ inheritence.cpp -o inheritence && ./inheritence

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void foo()
    {
        std::cout << "Base::foo()" << std::endl;
    }
    void foo_user()
    {
        foo();
    }
    void base_foo_user()
    {
        Base::foo();
    }

private:
    int x;
};

class Derived : public Base
{
public:
    void foo() override
    {
        std::cout << "Derived::foo()" << std::endl;
    }

private:
    int y;
};

int main()
{
    Base b;
    Derived d;
    Base *pb = &d;

    // virtual function call through reference
    pb->foo();

    // base function calling virtual function
    pb->foo_user();
    pb->base_foo_user();

    return 0;
}
