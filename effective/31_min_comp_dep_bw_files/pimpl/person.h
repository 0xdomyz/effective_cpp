#include <string> // standard library components
                  // shouldn’t be forward-declared
#include <memory> // for tr1::shared_ptr; see below

class PersonImpl; // forward decl of Person impl. class
class Date;       // forward decls of classes used in
class Address;    // Person interface

class Person
{
public:
    Person(const std::string &name, const Date &birthday,
           const Address &addr);
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:                               // ptr to implementation;
    std::shared_ptr<PersonImpl> pImpl; // see Item 13 for info on
};                                     // std::tr1::shared_ptr
