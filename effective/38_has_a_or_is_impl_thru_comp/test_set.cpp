// g++ test_set.cpp -o test_set && ./test_set

#include <iostream>
#include "set.h"

using namespace std;

int main()
{
    Set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << "s contains 3: " << s.member(3) << endl; // "s contains 3: 1"
    cout << "s contains 6: " << s.member(6) << endl; // "s contains 6: 0"

    cout << "s.size(): " << s.size() << endl;

    s.remove(3);
    s.remove(4);

    cout << "s.size(): " << s.size() << endl;

    return 0;
}
