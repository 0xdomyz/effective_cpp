// g++ person.cpp -o person && ./person

#include <string>

class Address
{
public:
    Address(const std::string &houseName, const std::string &street) : houseName(houseName), street(street){};
    Address() : houseName("default"), street("default"){};

private:
    std::string houseName;
    std::string street;
}; // where someone lives

class PhoneNumber
{
public:
    PhoneNumber(const std::string &internationalCode, const std::string &number) : internationalCode(internationalCode), number(number){};
    PhoneNumber() : internationalCode("00"), number("00"){};

private:
    std::string internationalCode;
    std::string number;
};

class Person
{
public:
private:
    std::string name;        // composed object
    Address address;         // ditto
    PhoneNumber voiceNumber; // ditto
    PhoneNumber faxNumber;   // ditto
};

int main()
{
    Address a;
    a = Address("house", "street");
    PhoneNumber p("00", "123456789");

    Person person;
    person = Person();

    return 0;
}