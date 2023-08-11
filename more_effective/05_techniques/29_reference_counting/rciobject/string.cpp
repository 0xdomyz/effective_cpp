#include "string.h"
#include <cstring>

using namespace std;

String::String(const char *value)
{
    init(value);
};

String::String(const String &rhs)
{
    init(rhs.data);
};

String::~String()
{
    delete[] data;
};

String &String::operator=(const String &rhs)
{
    if (this != &rhs)
    {
        delete[] data;
        init(rhs.data);
    }
    return *this;
};

void String::init(const char *initValue)
{
    data = new char[strlen(initValue) + 1];
    strcpy(data, initValue);
};

const char &String::operator[](int index) const
{
    return data[index];
};

char &String::operator[](int index)
{
    return data[index];
};
