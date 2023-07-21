// g++ 01_pointer_ref.cpp -o 01_pointer_ref && ./01_pointer_ref

// you should use a pointer whenever you need to take into
// account the possibility that there’s nothing to refer to (in which case
// you can set the pointer to null) or whenever you need to be able to refer
// to different things at different times (in which case you can change
// where the pointer points).

// You should use a reference whenever you
// know there will always be an object to refer to and you also know that
// once you’re referring to that object, you’ll never want to refer to anything else
// They’re also appropriate when implementing operators whose
// syntactic requirements make the use of pointers undesirable.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string &rs; // error! References must
    // be initialized
    string s("xyzzy");
    string &rs = s; // okay, rs refers to s
}