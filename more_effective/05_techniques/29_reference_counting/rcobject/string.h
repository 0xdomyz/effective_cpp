#ifndef GUARD_string_h
#define GUARD_string_h

#include "RCObject.h"

class String
{       // class to be used by
public: // application developers
    String(const char *value = "");
    const char &operator[](int index) const;
    char &operator[](int index); // will mark the StingValue as unshareable

private:
    // class representing string values
    struct StringValue : public RCObject
    {
        char *data;
        StringValue(const char *initValue);
        StringValue(const StringValue &rhs);
        void init(const char *initValue);
        ~StringValue();
    };
    RCPtr<StringValue> value;

public:
    RCPtr<StringValue> &get_data()
    {
        return value;
    };
};

#endif