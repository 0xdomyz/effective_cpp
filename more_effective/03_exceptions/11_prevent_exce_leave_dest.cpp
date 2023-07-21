// g++ 11_prevent_exce_leave_dest.cpp -o test && ./test

// We thus find ourselves with two good reasons for keeping exceptions
// from propagating out of destructors.

// First, it prevents terminate from
// being called during the stack-unwinding part of exception propagation.

// Second, it helps ensure that destructors always accomplish everything
// they are supposed to accomplish

#include <iostream>

using namespace std;

void startTransaction()
{
    cout << "startTransaction" << endl;
};
void endTransaction()
{
    cout << "endTransaction" << endl;
};

class Session
{
public:
    Session();
    ~Session();

private:
    static void logCreation(Session *objAddr)
    {
        cout << "logCreation" << endl;
    };
    static void logDestruction(Session *objAddr)
    {
        cout << "logDestruction" << endl;
    };
};

Session::Session() // to keep things simple,
{                  // this ctor handles no
    // exceptions
    logCreation(this);
    startTransaction(); // start DB transaction
}

Session::~Session()
{
    try
    {
        logDestruction(this);
    }
    catch (...)
    {
    }
    // That block prevents exceptions thrown from logDestruction
    // from propagating beyond Session’s destructor
    endTransaction(); // end DB transaction
}

int main()
{
    Session s;
    return 0;
}