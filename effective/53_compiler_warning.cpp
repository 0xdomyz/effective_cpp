// g++ 53_compiler_warning.cpp -o 53_compiler_warning && ./53_compiler_warning

// warning: 'virtual void D::f()' was hidden [-Woverloaded-virtual]
// g++ 53_compiler_warning.cpp -o 53_compiler_warning -Woverloaded-virtual && ./53_compiler_warning

#include <iostream>

using namespace std;

class B
{
public:
    virtual void f() const
    {
        cout << "B::f()" << endl;
    };
};

class D : public B
{
public:
    virtual void f()
    {
        cout << "D::f()" << endl;
    };
};

int main()
{
    D d;
    B &b = d;
    b.f();
}
