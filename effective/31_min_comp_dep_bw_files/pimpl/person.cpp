#include "person.h" // we’re implementing the Person class,
// so we must #include its class definition
#include "person_impl.h" // we must also #include PersonImpl’s class
// definition, otherwise we couldn’t call
// its member functions; note that
// PersonImpl has exactly the same public
// member functions as Person — their
// interfaces are identical

Person::Person(const std::string &name, const Date &birthday,
               const Address &addr)
    : pImpl(new PersonImpl(name, birthday, addr))
{
}

std::string Person::name() const
{
    return pImpl->name();
}

std::string Person::birthDate() const
{
    return pImpl->birthDate();
}

std::string Person::address() const
{
    return pImpl->address();
}