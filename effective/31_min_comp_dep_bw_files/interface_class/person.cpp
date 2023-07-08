#include "person.h"
#include "person_impl.h"

std::shared_ptr<Person> Person::create(const std::string &name,
                                       const Date &birthday,
                                       const Address &addr)
{
    return std::shared_ptr<Person>(new RealPerson(name, birthday,
                                                  addr));
}

std::string RealPerson::name() const
{
    return theName;
}

std::string RealPerson::birthDate() const
{
    return theBirthDate.toString();
}

std::string RealPerson::address() const
{
    return theAddress.toString();
}
