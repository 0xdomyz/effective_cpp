#ifndef SET_H
#define SET_H

#include <list>
#include <algorithm>

template <class T> // the right way to use list for Set
class Set
{
public:
    bool member(const T &item) const;
    void insert(const T &item);
    void remove(const T &item);
    std::size_t size() const;

private:
    std::list<T> rep; // representation for Set data
};

template <typename T>
bool Set<T>::member(const T &item) const
{
    return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template <typename T>
void Set<T>::insert(const T &item)
{
    if (!member(item))
        rep.push_back(item);
}

template <typename T>
void Set<T>::remove(const T &item)
{
    typename std::list<T>::iterator it =         // see Item 42 for info on
        std::find(rep.begin(), rep.end(), item); // “typename” here
    if (it != rep.end())
        rep.erase(it);
}

template <typename T>
std::size_t Set<T>::size() const
{
    return rep.size();
}

#endif // SET_H