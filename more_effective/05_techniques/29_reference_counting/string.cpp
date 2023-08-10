#include "string.h"
#include <cstring>

using namespace std;

void String::StringValue::init(const char *initValue)
{
    data = new char[strlen(initValue) + 1];
    strcpy(data, initValue);
}

String::StringValue::StringValue(const char *initValue)
{
    init(initValue);
}

String::StringValue::StringValue(const StringValue &rhs)
{
    init(rhs.data);
}

String::StringValue::~StringValue()
{
    delete[] data;
}

// string
String::String(const char *initValue)
    : value(new StringValue(initValue)) {}
const char &String::operator[](int index) const
{
    return value->data[index];
}

char &String::operator[](int index)
{
    if (value->isShared())
    {
        value = new StringValue(value->data);
    }
    value->markUnshareable();
    return value->data[index];
}
