#include <string>

class Date
{
public:
    Date(const std::string &date) : theDate(date){};
    std::string toString() const { return theDate; };

private:
    std::string theDate;
};