#ifndef GUARD_RCObject_h
#define GUARD_RCObject_h

// Any class wishing to take advantage of automatic reference
// counting must inherit from this class.
//
// RCObject encapsulates the reference count itself,
// as well as functions for incrementing and decrementing that count.
//
// It also contains the code for destroying a value
// when it is no longer in use, i.e., when its reference count becomes 0.
//
// Finally, it contains a field that keeps track of whether this value is
// shareable, and it provides functions to query this value and set it to
// false. There is no need for a function to set the shareability field to
// true, because all values are shareable by default.

#include <cstddef> // for size_t

class RCObject
{
public:
    RCObject();
    RCObject(const RCObject &rhs);
    RCObject &operator=(const RCObject &rhs);
    virtual ~RCObject() = 0; // be used only as a base class.
    void addReference();
    void removeReference();
    void markUnshareable();
    bool isShareable() const;
    bool isShared() const;

private:
    size_t refCount;
    bool shareable;
};

// but the calls to those functions must still be manually
// inserted in other classes. It is still up to the String copy constructor
// and the String assignment operator to call addReference and removeReference on
// StringValue objects. This is clumsy. We’d like to
// move those calls out into a reusable class, too

// If we could somehow make the pointer itself
// detect these happenings and automatically perform the necessary manipulations of
// the refCount field, we’d be hom

#endif // !GUARD_RCObject_h
