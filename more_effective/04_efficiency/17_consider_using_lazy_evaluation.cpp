// In C++, lazy evaluation is a programming technique that involves delaying the
// evaluation of an expression until its value is actually needed. This can be useful
// in a variety of situations, such as:

// - To avoid unnecessary copying of objects. By delaying the evaluation of an expression
//   until its value is actually needed, it is possible to avoid creating unnecessary
//   copies of objects. For example:

#include <vector>
#include <unordered_map>
#include <string>

class MyClass
{
public:
    const std::vector<int> &getValues() const
    {
        if (values.empty())
        {
            // compute values lazily
        }
        return values;
    }

private:
    mutable std::vector<int> values;
};

// In this example, the getValues() function returns a const reference to a vector of
// integers. If the vector has not yet been computed, the function computes it lazily
// and stores it in the values member variable. Subsequent calls to getValues() return
// a reference to the precomputed vector, avoiding unnecessary computation and copying.

// - To distinguish reads from writes using operator[]. By overloading the [] operator
//   to return a proxy object instead of a reference to the underlying data, it is possible
//   to distinguish between reads and writes to the data. This can be useful in situations
//   where the data is expensive to compute or retrieve. For example:

class MyArray
{
public:
    class Proxy
    {
    public:
        operator int() const { return value; }
        Proxy &operator=(int newValue)
        {
            value = newValue;
            return *this;
        }

    private:
        int value;
    };
    Proxy operator[](int index) { return Proxy(); }
};

// In this example, the MyArray class overloads the [] operator to return a Proxy object
// instead of a reference to the underlying data. The Proxy object provides an implicit
// conversion to int, allowing the data to be read, and an assignment operator, allowing
// the data to be written. By using this technique, it is possible to distinguish between
// reads and writes to the data, and to avoid unnecessary computation or retrieval of the
// data when it is not needed.

// - To avoid unnecessary reads from databases. By delaying the retrieval of data from a
//   database until it is actually needed, it is possible to avoid unnecessary reads and
//   improve performance. For example:

std::string retrieveValueFromDatabase(int id)
{
    // expensive database read
}

class Database
{
public:
    std::string getValue(int id) const
    {
        auto emplaceResult = const_cast<std::unordered_map<int, std::string> &>(cache).emplace(id, "");
        if (emplaceResult.second)
        {
            // key not found, retrieve value from database and insert into cache
            emplaceResult.first->second = retrieveValueFromDatabase(id);
        }
        return emplaceResult.first->second;
    }

private:
    mutable std::unordered_map<int, std::string> cache;
};

// In this example, the getValue() function retrieves a value from a database, but only
// if the value is not already in the cache. Subsequent calls to getValue() return the
// cached value, avoiding unnecessary reads from the database.

// - To avoid unnecessary numerical computations. By delaying the evaluation of numerical
//   expressions until their values are actually needed, it is possible to avoid unnecessary
//   computations and improve performance. For example:

class MyMath
{
public:
    MyMath() : value(0.0), computed(false) {}

    double getValue() const
    {
        if (!computed)
        {
            value = computeValue();
            computed = true;
        }
        return value;
    }

private:
    mutable double value;
    mutable bool computed;
    double computeValue() const
    {
        // expensive computation
    }
};

// In this example, the getValue() function computes a numerical value, but only if the
// value has not already been computed. Subsequent calls to getValue() return the precomputed
// value, avoiding unnecessary computations.

// By using lazy evaluation, it is possible to improve the performance and efficiency of
// C++ programs in a variety of situations, while avoiding unnecessary computation and
// improving program safety and reliability.