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
    std::string name;
    Date dateOfBirth;
    Address address;

    // create an object supporting the Person interface
    std::shared_ptr<Person> pp(Person::create(name, dateOfBirth, address));

    std::cout << pp->name()      // use the object via the
              << " was born on " // Person interface
              << pp->birthDate()
              << " and now lives at "
              << pp->address();
    cout << endl;

    // the object is automatically
    // deleted when pp goes out of
    // scope — see Item 13

    return 0;
}
