// g++ 02_cpp_casts.cpp -o cpp_casts && ./cpp_casts

// what the new casts lack in
// beauty they make up for in precision of meaning and easy recognizability.
// Programs that use the new casts are easier to parse (both for
// humans and for tools), and they allow compilers to diagnose casting
// errors that would otherwise go undetected.

#include <iostream>
#include <cassert>

using namespace std;

int main()
{

    {
        // static_cast has basically the same power and meaning as the general-purpose
        // C-style cast, but it is more specific about what it does
        int firstNumber, secondNumber;
        firstNumber = 5;
        secondNumber = 2;
        double result = ((double)firstNumber) / secondNumber;
        assert(result == 2.5);
        {
            double result = static_cast<double>(firstNumber) / secondNumber;
            assert(result == 2.5);
        }
    }
}
