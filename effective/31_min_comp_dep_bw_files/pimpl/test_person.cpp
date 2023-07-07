// compile all files together:
// g++ test_person.cpp person.cpp -o test_person && ./test_person

// compile person.cpp into a library:
// g++ -c person.cpp -o person.o
// then compile test_person.cpp with the library:
// g++ test_person.cpp person.o -o test_person && ./test_person

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
