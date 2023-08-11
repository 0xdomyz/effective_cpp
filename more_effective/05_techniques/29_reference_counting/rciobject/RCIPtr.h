#ifndef RCIPTR_H
#define RCIPTR_H

#include "RCObject.h"

template <class T>
class RCIPtr
{
public:
    RCIPtr(T *realPtr = 0);
    RCIPtr(const RCIPtr &rhs);
    ~RCIPtr();
    RCIPtr &operator=(const RCIPtr &rhs);
    T *operator->() const;
    T &operator*() const;
    RCObject &getRCObject() // give clients access to
    {
        return *counter;
    } // isShared, etc.
private:
    struct CountHolder : public RCObject
    {
        ~CountHolder() { delete pointee; }
        T *pointee;
    };
    CountHolder *counter;
    void init();
};

template <class T>
void RCIPtr<T>::init()
{
    if (counter->isShareable() == false)
    {
        T *oldValue = counter->pointee;
        counter = new CountHolder;
        counter->pointee = oldValue ? new T(*oldValue) : 0;
    }
    counter->addReference();
}

template <class T>
RCIPtr<T>::RCIPtr(T *realPtr)
    : counter(new CountHolder)
{
    counter->pointee = realPtr;
    init();
}

template <class T>
RCIPtr<T>::RCIPtr(const RCIPtr &rhs)
    : counter(rhs.counter)
{
    init();
}

template <class T>
RCIPtr<T>::~RCIPtr()
{
    counter->removeReference();
}

template <class T>
RCIPtr<T> &RCIPtr<T>::operator=(const RCIPtr &rhs)
{
    if (counter != rhs.counter)
    {
        counter->removeReference();
        counter = rhs.counter;
        init();
    }
    return *this;
}

template <class T>
T *RCIPtr<T>::operator->() const
{
    return counter->pointee;
}

template <class T>
T &RCIPtr<T>::operator*() const
{
    return *(counter->pointee);
}

#endif // RCIPTR_H ///:~