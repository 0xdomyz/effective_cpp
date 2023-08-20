// g++ 07_distinguish_bw_when_creating_objects.cpp -o 07_distinguish_bw_when_creating_objects && ./07_distinguish_bw_when_creating_objects

// • Braced initialization is the most widely usable initialization syntax, it prevents
// narrowing conversions, and it’s immune to C++’s most vexing parse.
// • During constructor overload resolution, braced initializers are matched to
// std::initializer_list parameters if at all possible, even if other construc‐
// tors offer seemingly better matches.
// • An example of where the choice between parentheses and braces can make a
// significant difference is creating a std::vector<numeric type> with two
// arguments.
// • Choosing between parentheses and braces for object creation inside templates
// can be challenging.

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    {
        std::vector<int> v1(10, 20); // use non-std::initializer_list
                                     // ctor: create 10-element
        // std::vector, all elements have
        // value of 20
        std::vector<int> v2{10, 20}; // use std::initializer_list ctor:
                                     // create 2-element std::vector,
        // element values are 10 and 20

        assert(v1.size() == 10);
        assert(v2.size() == 2);
    }
}
