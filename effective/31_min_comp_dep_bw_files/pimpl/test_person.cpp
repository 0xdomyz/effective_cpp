// g++ test_person.cpp -o test_person && ./test_person

#include <iostream>
#include "person.h"
#include <string>

using namespace std;

int main()
{
    Person p("John", string("01/01/2000"), string("1234 Main St."));
    cout << p.name() << endl;
    cout << p.birthDate() << endl;
    cout << p.address() << endl;
    return 0;
}