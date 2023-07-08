#ifndef PERSON_H
#define PERSON_H

#include <string> // standard library components
                  // shouldn’t be forward-declared
#include <memory> // for tr1::shared_ptr; see below

class Date;    // forward decls of classes used in
class Address; // Person interface

class Person
{
public:
    virtual ~Person(){};
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
    virtual std::string address() const = 0;

    static std::shared_ptr<Person>  // return a tr1::shared_ptr to a new
    create(const std::string &name, // Person initialized with the
           const Date &birthday,    // given params; see Item 18 for
           const Address &addr);    // why a tr1::shared_ptr is returned
};

#include "date.h"    // now that Date is
#include "address.h" // complete, we can
                     // #include its header file

#endif // PERSON_H