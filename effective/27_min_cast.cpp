// g++ 27_min_cast.cpp -o 27_min_cast && ./27_min_cast

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main()
{

    {
        // examples of casts

        // old style

        // const_cast
        const string s = "hello";
        string *ps = const_cast<string *>(&s);
        *ps = "world";
        assert(s == "world");

        // dynamic_cast

        // reinterpret_cast

        // static_cast
    }
}