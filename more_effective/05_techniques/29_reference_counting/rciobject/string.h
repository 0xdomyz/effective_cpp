#ifndef STRING_H
#define STRING_H

#include "RCIPtr.h"

class String
{
public:
    String(const char *value = "");
    String(const String &rhs);
    ~String();
    String &operator=(const String &rhs);

    const char &operator[](int index) const;
    char &operator[](int index); // will mark the StingValue as unshareable

    char *get_data() const { return data; } // instrumented to test copy-on-write

private:
    char *data;
    void init(const char *initValue);
};

class RCString
{
public:
    RCString(const char *v = "") : value(new String(v)) {}

    char &operator[](int index)
    {
        if (value.getRCObject().isShared())
        {                               // do COW if
            value = new String(*value); // String is shared
        }
        return value->operator[](index);
    }
    const char &operator[](int index) const
    {
        return value->operator[](index);
        // which operator[] to call?
    }
    RCIPtr<String> &get_data() // instrumented to test copy-on-write
    {
        return value;
    };

private:
    RCIPtr<String> value;
};

#endif // STRING_H ///:~