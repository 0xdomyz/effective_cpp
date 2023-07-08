#ifndef PERSON_IMPL_H
#define PERSON_IMPL_H

#include <string>
#include "date.h"
#include "address.h"

class RealPerson : public Person
{
public:
    RealPerson(const std::string &name, const Date &birthday,
               const Address &addr)
        : theName(name), theBirthDate(birthday), theAddress(addr)
    {
    }
    virtual ~RealPerson() {}
    std::string name() const;      // implementations of these
    std::string birthDate() const; // functions are not shown, but
    std::string address() const;   // they are easy to imagine
private:
    std::string theName;
    Date theBirthDate;
    Address theAddress;
};

#endif // PERSON_IMPL_H
