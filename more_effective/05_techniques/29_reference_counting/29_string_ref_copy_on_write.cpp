// g++ 29_string_ref_copy_on_write.cpp -o 29_string_ref_copy_on_write && ./29_string_ref_copy_on_write

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    {
        // std string has sharability flag or similar
        string s1("hello");
        char *p = &s1[0];

        string s2;
        s2 = s1;

        *p = 'H';

        assert(s1 == "Hello");
        assert(s2 == "hello");
    }

    {
        string s1("hello");
        char *p = &s1[0];

        s1 = "123456789123456789123456789123456789123456789";

        cout << *p << endl; // undefined behavior
    }
}
