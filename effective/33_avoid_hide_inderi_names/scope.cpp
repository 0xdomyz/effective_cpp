// g++ scope.cpp -o scope && ./scope

#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    virtual void mf1() = 0;
    virtual void mf2()
    {
        cout << "Base::mf2()" << endl;
    };
    void mf3()
    {
        cout << "Base::mf3()" << endl;
    };
};

class Derived : public Base
{
public:
    virtual void mf1()
    {
        cout << "Derived::mf1()" << endl;
    };
    void mf4()
    {
        cout << "Derived::mf4()" << endl;
    };
};

int main()
{
    Derived d;
    d.mf1();
    d.mf2();
    d.mf3();
    d.mf4();

    // object of abstract class type "Base" is not allowed:
    // Base b;

    return 0;
}
