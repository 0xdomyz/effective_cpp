#include <cstddef> // for size_t
#include "RCObject.h"

// As it turns out, it simplifies things for the creators of
// RCObjects to set refCount to 1 themselves
RCObject::RCObject()
    : refCount(0), shareable(true) {}

// we’re creating a new object representing a
// value, and new values are always unshared and referenced only by
// their creator
RCObject::RCObject(const RCObject &)
    : refCount(0), shareable(true) {}

// RCObject is a base class for a shared value object, and in a system
// based on reference counting, such objects are not assigned to one
// another, objects pointing to them a
RCObject &RCObject::operator=(const RCObject &)
{
    return *this;
}

RCObject::~RCObject() {} // virtual dtors must always
// be implemented, even if
// they are pure virtual
// and do nothing (see also
// Item 33)

void RCObject::addReference() { ++refCount; }

// For this class to be successful, we must
// engineer things so that RCObjects can be created only on the heap.
void RCObject::removeReference()
{
    if (--refCount == 0)
        delete this;
}

void RCObject::markUnshareable()
{
    shareable = false;
}

bool RCObject::isShareable() const
{
    return shareable;
}

bool RCObject::isShared() const
{
    return refCount > 1;
}
