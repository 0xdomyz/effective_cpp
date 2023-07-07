#include <string>

class Address
{
public:
    Address(const std::string &addr) : theAddress(addr){};
    std::string toString() const { return theAddress; };

private:
    std::string theAddress;
};