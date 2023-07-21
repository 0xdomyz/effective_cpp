// g++ 12_throw_excep_differ.cpp -o test -std=c++11 && ./test

// There are thus three primary ways in which passing an object to a
// function or using that object to invoke a virtual function differs from
// throwing the object as an exception.

// First, exception objects are always
// copied; when caught by value, they are copied twice. Objects passed to
// function parameters need not be copied at all.

// Second, objects thrown
// as exceptions are subject to fewer forms of type conversion than are
// objects passed to functions.

// Finally, catch clauses are examined in
// the order in which they appear in the source code, and the first one
// that can succeed is selected for execution. When an object is used to
// invoke a virtual function, the function selected is the one that provides
// the best match for the type of the object, even if it’s not the first one
// listed in the source code.

#include <iostream>
#include <exception>

using namespace std;

// Widget class with anounncing constructor and destructor, copy, assign
class Widget
{
    friend ostream &operator<<(ostream &s, Widget &w)
    {
        cout << "ostream &operator<<(ostream &s, Widget &w)" << endl;
        return s;
    };

public:
    Widget()
    {
        cout << "Widget()" << endl;
    }; // default constructor
    Widget(const Widget &rhs)
    {
        cout << "Widget(const Widget &rhs)" << endl;
    }; // copy constructor
    Widget &operator=(const Widget &rhs)
    {
        cout << "Widget &operator=(const Widget &rhs)" << endl;
        return *this;
    }; // copy assignment operator
    ~Widget()
    {
        cout << "~Widget()" << endl;
    }; // destructor
    // ...
};

class SpecialWidget : public Widget
{
};

// function to read the value of a Widget from a stream
void passAndThrowWidget()
{
    static Widget localWidget; // this is now static; it
                               // will exist until the
                               // end of the program

    cout << localWidget; // pass localWidget to operator>>
    throw localWidget;   // throw localWidget as an exception
    // a copy
    // of localWidget will be made, and it is the copy that is passed to the
    // catch clause. This must be the case, because localWidget will go out
    // of scope once control leaves passAndThrowWidget, and when local
    // Widget goes out of scope, its destructor will be calle

    // typically much slower than passing an object to a function
}

int main()
{

    cout << "------------------------" << endl;
    {
        try
        {
            passAndThrowWidget();
        }
        catch (SpecialWidget w)
        {
            // This copy constructor is the
            // one in the class corresponding to the object’s static type,
            cout << "catch (SpecialWidget w)" << endl;
        }
        catch (Widget &w)
        {
            cout << "catch (Widget &w)" << endl;
        }
    }

    cout << "------------------------" << endl;

    // prefer throw over throw a particular object

    // catch (Widget &w) // catch Widget exceptions
    // {
    //     ...           // handle the exception
    //         throw;    // rethrow the exception so it
    // }                 // continues to propagate
    // catch (Widget &w) // catch Widget exceptions
    // {
    //     ...          // handle the exception
    //         throw w; // propagate a copy of the
    // }                // caught exception

    {
        // When throwing an exception, then, we expect to construct (and later destruct)
        // one more copy of
        // the thrown object than if we passed the same object to a function
        try
        {
            passAndThrowWidget();
        }
        catch (Widget w)
        {
            cout << "catch (Widget w)" << endl;
        }
    }

    cout << "------------------------" << endl;

    {
        try
        {
            passAndThrowWidget();
        }
        // catch (Widget &w)
        // {
        //     cout << "catch (Widget &w)" << endl;
        // }
        catch (const Widget &w)
        {
            cout << "catch (const Widget &w)" << endl;
        }
    }
    cout << "------------------------" << endl;

    {
        // no type conversion
        try
        {
            int i = 1;
            throw i;
        }
        catch (double d)
        {
            cout << "catch (double d)" << endl;
        }
        catch (int i)
        {
            cout << "catch (int i)" << endl;
        }
    }
    cout << "------------------------" << endl;

    {
        // inheritance bassed type conversion
        try
        {
            throw domain_error("domain_error");
        }
        catch (logic_error &e)
        {
            cout << "catch (logic_error &e)" << endl;
        }
        catch (domain_error &e)
        {
            cout << "catch (domain_error &e)" << endl;
        }

        // catch (runtime_error) ... // can catch errors of type
        // catch (runtime_error&) ... // runtime_error,
        // catch (const runtime_error&) ... // range_error, or
        // overflow_error
        // catch (runtime_error*) ... // can catch errors of type
        // catch (const runtime_error*) ... // runtime_error*,
        // range_error*, or
        // overflow_error*
    }

    // catch (const void *)... // catches any exception
    // that’s a pointer

    // always tried in order
    // try
    // {
    //     ...
    // }
    // catch (logic_error &ex)
    // {       // this block will catch
    //     ... // all logic_error
    // }       // exceptions, even those
    // // of derived types
    // catch (invalid_argument &ex)
    // {       // this block can never be
    //     ... // executed, because all
    // }       // invalid_argument
    // // exceptions will be caught
    // // by the clause above
}
