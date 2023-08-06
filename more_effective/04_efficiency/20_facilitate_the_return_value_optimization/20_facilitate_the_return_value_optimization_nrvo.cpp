#include <iostream>

// RVO (Return Value Optimization) happens when the compiler optimizes a function
// that returns an object by constructing the object directly in the caller's stack
// frame, instead of creating a temporary object and then copying it to the caller's
// stack frame. RVO is allowed to happen in the following situations:

// - When a function returns a named object by value, and the object is constructed
//   in the return statement.
// - When a function returns a temporary object that is constructed in the return
//   statement.

// RVO is not allowed to happen in the following situations:

// - When a function returns a named object by value, and the object is constructed
//   in a different statement than the return statement.
// - When a function returns a reference to a local object.
// - When a function returns a pointer to a local object.
// - When a function returns a pointer or reference to a temporary object that is
//   destroyed at the end of the statement.

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

Foo funcNRVO()
{
    Foo foo;
    return foo;
}
int main()
{
    std::cout << "------ NRVO ------" << std::endl;
    Foo foo1 = funcNRVO();
    std::cout << "-----------------" << std::endl;
    return 0;
}