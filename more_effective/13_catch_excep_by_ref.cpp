// g++ 13_catch_excep_by_ref.cpp -o test -std=c++11 && ./test

// by pointer
// For this to work, programmers must define exception objects in a way
// that guarantees the objects exist after control leaves the functions
// throwing pointers to them. Global and static objects work fine, but it’s
// easy for programmers to forget the constraint.

// pointer to new heap
// impossible to know to delete or not

// 4 standard exceptions are all objects
// bad_alloc
// bad_cast
// bad_typeid
// bad_exception

// by value
// copied twice
// slicing problem

// by reference
// if you catch by reference, you sidestep questions about object deletion that
// leave you damned if you do
// and damned if you don't;
// you avoid slicing exception objects;
// you retain the ability to catch standard exceptions; and you limit the number
// of times exception objects need to be copied.

#include <iostream>
#include <exception>

class exception
{       // as above, this is a
public: // standard exception class
    virtual const char *what() const throw()
    {
        return "exception";
    };
    // returns a brief descrip.
    // of the exception (see
    // Item 14 for info about
}; // the "throw()" at the
// end of the declaration)
class runtime_error : // also from the standard
                      public exception
{
public:
    virtual const char *what() const throw()
    {
        return "runtime_error";
    };
};                       // C++ exception hierarchy
class Validation_error : // this is a class added by
                         public runtime_error
{ // a client
public:
    virtual const char *what() const throw()
    {
        return "Validation_error";
    };
}; // in class exception above

void someFunction() // may throw a validation
{                   // exception
    if (1)
    {
        throw Validation_error();
    }
}

void doSomething()
{
    try
    {
        someFunction(); // may throw a validation
    }                   // exception
    // catch (exception &ex)
    catch (const exception &ex)
    { // here we catch by reference
        // instead of by value
        std::cerr << ex.what(); // now calls
        // Validation_error::what(),
        // not exception::what()
    }
}

int main()
{
    doSomething();
    std::cout << std::endl;
    return 0;
}
