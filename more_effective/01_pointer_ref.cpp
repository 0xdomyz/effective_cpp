// g++ 01_pointer_ref.cpp -o 01_pointer_ref && ./01_pointer_ref

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