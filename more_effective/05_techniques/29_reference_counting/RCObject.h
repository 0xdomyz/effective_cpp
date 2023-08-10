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

// template class for smart pointers-to-T objects.
// - T must
//   support the RCObject interface, typically by inheriting from RCObject
// - T containing a copy constructor that makes a truly independent copy
// - pointee can not point to a class derived from T
template <class T>
class RCPtr
{
public:
    RCPtr(T *realPtr = 0);
    RCPtr(const RCPtr &rhs);
    ~RCPtr();
    RCPtr &operator=(const RCPtr &rhs);
    T *operator->() const; // see Item 28
    T &operator*() const;  // see Item 28
private:
    T *pointee; // dumb pointer this
    // object is emulating
    void init(); // common initialization
};               // code

// RCPtr methods

template <class T>
RCPtr<T>::RCPtr(T *realPtr) : pointee(realPtr)
{
    init();
}
template <class T>
RCPtr<T>::RCPtr(const RCPtr &rhs) : pointee(rhs.pointee)
{
    init();
}

template <class T>
void RCPtr<T>::init()
{
    if (pointee == 0)
    {           // if the dumb pointer is
        return; // null, so is the smart one
    }
    if (pointee->isShareable() == false)
    {                              // if the value
        pointee = new T(*pointee); // isn’t shareable,
    }                              // copy it
    pointee->addReference();       // note that there is now a
} // new reference to the value

template <class T>
RCPtr<T> &RCPtr<T>::operator=(const RCPtr &rhs)
{
    if (pointee != rhs.pointee)
    { // skip assignments
        // where the value
        // doesn’t change
        T *oldPointee = pointee; // save old pointee value
        pointee = rhs.pointee;   // point to new value
        init();                  // if possible, share it
        // else make own copy
        if (oldPointee)
        {
            oldPointee->removeReference(); // remove reference to
        }                                  // current value
    }
    return *this;
}

template <class T>
RCPtr<T>::~RCPtr()
{
    if (pointee)
        pointee->removeReference();
}

template <class T>
T *RCPtr<T>::operator->() const { return pointee; }
template <class T>
T &RCPtr<T>::operator*() const { return *pointee; }

#endif // !GUARD_RCObject_h
