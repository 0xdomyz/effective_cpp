// g++ strong_type.cpp -o strong_type && ./strong_type

// Strong typing is a feature of some programming languages that enforces
// strict type checking at compile time. This means that variables and
// expressions must have a specific type, and cannot be used in ways that
// are not allowed by that type. For example, in C++, you cannot add a
// string to an integer without first converting one of them to the
// appropriate type.

#include <iostream>
#include <string>

int main()
{
    int x = 42;
    std::string s = "hello";

    // This line will not compile, because you cannot add an integer and a
    // string together.
    // std::cout << x + s << std::endl;

    // This line will compile, because we are converting the integer to a
    // string before concatenating it with the other string.
    std::cout << s + std::to_string(x) << std::endl;

    return 0;
}