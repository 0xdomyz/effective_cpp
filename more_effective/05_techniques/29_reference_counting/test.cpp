// g++ test.cpp RCObject.cpp string.cpp -o test && ./test

#include "string.h"
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    String s1("hello");
    String s2;

    s2 = s1;

    cout << "should be the same: " << endl;
    cout << (void *)(s1.get_data()->data) << endl;
    cout << (void *)(s2.get_data()->data) << endl;

    s2[0] = 'j';
    cout << "should be different since s2 is copied on write: " << endl;
    cout << (void *)(s2.get_data()->data) << endl;

    s1[0];
    cout << "should be the same since s1 is not copied on write: " << endl;
    cout << (void *)(s1.get_data()->data) << endl;

    String s3(s1);
}
