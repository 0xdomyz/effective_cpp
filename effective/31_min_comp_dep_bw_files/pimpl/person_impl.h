#ifndef PERSON_IMPL_H
#define PERSON_IMPL_H

#include <string>
#include "date.h"
#include "address.h"

class PersonImpl
{
public:
    PersonImpl(const std::string &name, const Date &birthday,
               const Address &addr) : theName(name), theBirthDate(birthday), theAddress(addr){};
    std::string name() const { return theName; };
    std::string birthDate() const { return theBirthDate.toString(); };
    std::string address() const { return theAddress.toString(); };

private:
    std::string theName; // implementation detail
    Date theBirthDate;   // implementation detail
    Address theAddress;  // implementation detail
};

#endif // PERSON_IMPL_H