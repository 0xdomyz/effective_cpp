// g++ 27_min_cast2.cpp -o 27_min_cast2 && ./27_min_cast2

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

using namespace std;

class Window
{
public:
    virtual void blink() {} // default impl is no-op;
                            // see Item 34 for why
};                          // a default impl may be
// a bad idea
class SpecialWindow : public Window
{
public:
    virtual void blink() {} // in this class, blink
                            // does something
};

int main()
{
    {
        // dynamic_cast
        typedef std::vector<Window *> VPW;
        VPW winPtrs; // container holds
                     // (ptrs to) all possible
                     // Window types
        for (VPW::iterator iter = winPtrs.begin();
             iter != winPtrs.end();
             ++iter)
        {
            SpecialWindow *psw = dynamic_cast<SpecialWindow *>(*iter);
            if (psw) // if *iter is a SpecialWindow
                psw->blink();
        }
    }

    {
        typedef std::vector<std::shared_ptr<SpecialWindow>> VPSW;
        VPSW winPtrs;
        for (VPSW::iterator iter = winPtrs.begin(); // better code: uses
             iter != winPtrs.end();                 // no dynamic_cast
             ++iter)
            (*iter)->blink();
    }

    {
        typedef std::vector<std::shared_ptr<Window>> VPW;
        VPW winPtrs; // container holds
                     // (ptrs to) all possible
                     // Window types
        for (VPW::iterator iter = winPtrs.begin();
             iter != winPtrs.end();
             ++iter) // note lack of
            (*iter)
                ->blink(); // dynamic_cast
    }

    {
        // cast from int to double
        int x = 0;
        double d = static_cast<double>(x);
        assert(d == 0);

        double d2 = double(x); // same effect as
                               // static_cast<double>(x)
        assert(d2 == 0);
    }

    {
        // cast from double to int
        double d = 0.0;
        int x = static_cast<int>(d);
        assert(x == 0);
    }

    {
        // cast to be const
        int x = 0;
        const int cx = static_cast<const int>(x);
        assert(cx == 0);
    }

    {
        // double to string without using static_cast
        double d = 0.0;
        string s = to_string(d);
        cout << s << endl;

        int x = 0;
        string s2 = to_string(x);
        cout << s2 << endl;

        cout << d << endl; // d still has type double
    }
}
