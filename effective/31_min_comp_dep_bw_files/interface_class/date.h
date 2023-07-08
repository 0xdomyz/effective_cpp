#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
public:
    Date() = default;
    Date(const std::string &date) : theDate(date){};
    std::string toString() const { return theDate; };

private:
    std::string theDate;
};

#endif // DATE_H