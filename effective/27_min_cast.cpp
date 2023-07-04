// g++ 27_min_cast.cpp -o 27_min_cast && ./27_min_cast

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// example of conversion constructor
class Widget
{
public:
    explicit Widget(int size) : size(size) {}

private:
    int size;
};

void doSomeWork(const Widget &w){
    // cout << "doSomeWork" << endl;
};

// example of multiple inheritance
class Base
{
public:
    virtual ~Base() {}

private:
    int a;
};
class Base2
{
public:
    virtual ~Base2() {}

private:
    int c;
};
// derive from both
class Derived : public Base, public Base2
{
private:
    int b;
};

// example of inheritance
class Window
{ // base class
public:
    virtual void onResize() {} // base onResize impl
};
class SpecialWindow : public Window
{
public:
    virtual void onResize()
    {
        Window::onResize(); // call Window::onResize
                            // on *this
    }
};

int main()
{
    // examples of casts
    {
        // old style
        doSomeWork(Widget(15)); // create Widget from int
        // constructor
        doSomeWork((Widget)15); // create Widget from int
        Widget w(15);
        doSomeWork(w);
        // with function-style cast
        doSomeWork(static_cast<Widget>(15)); // create Widget from int
                                             // with C++-style cast

        string s("hello");
        string s2(3, '*');
    }

    {
        // conversion and comparison between pointers to base and derived
        Derived d;
        Base *bp = &d;    // upcast
        assert(bp == &d); // may be false
    }

    {

        // const_cast
        const string s = "hello";
        string *ps = const_cast<string *>(&s);
        *ps = "world";
        assert(s == "world");
    }
}
