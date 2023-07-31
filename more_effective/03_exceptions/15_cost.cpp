// g++ 15_cost.cpp -o 15_1 -std=c++11 && ./15_1

// The Costs of Exception Handling To handle exceptions at runtime:

// identify and carry out object destruction.
// try catch block and exception specifications.
// runtime exception specifications comparision.

// some points:

// You pay for the space used by the data
// structures needed to keep track of which objects are fully constructed
// (see Item 10), and you pay for the time needed to keep these data
// structures up to date.

// libraries that eschew exceptions, provided
// they can guarantee that exceptions thrown from client code never
// propagate into the library. This is a difficult guarantee to make, as it
// precludes client redefinitions of library-declared virtual functions; it
// also rules out client-defined callback functions

// an exception specification generally incurs about the same cost as a try block

// Compared to a normal function return, returning from a
// function by throwing an exception may be as much as three orders of
// magnitude slower.

// what to do:

// compile without support for exceptions when that is feasible
// limit try blocks and exception specifications to honestly need them;
// throw exceptions only under conditions that are truly exceptional

#include <iostream>

using namespace std;

int main()
{
    try
    {
        throw 1;
    }
    catch (int e)
    {
        cout << "int exception" << endl;
    }
    catch (...)
    {
        cout << "other exception" << endl;
    }
    return 0;
}