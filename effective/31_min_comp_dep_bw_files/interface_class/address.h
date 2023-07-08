#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
    Address() = default;
    Address(const std::string &addr) : theAddress(addr){};
    std::string toString() const { return theAddress; };

private:
    std::string theAddress;
};

#endif // ADDRESS_H