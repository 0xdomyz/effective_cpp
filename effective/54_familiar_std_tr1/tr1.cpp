// g++ tr1.cpp -o tr1 -std=c++17 && ./tr1

#include <string>
#include <iostream>

using namespace std;

// function

void registerCallback(string(int));

void registerCallback(std::string func(int))
{
    // use the func
    string s = func(2);
    cout << s << endl;
}; // param type is a function
// taking an int and
// returning a string

// tr1 function equivalent in C++11
// void registerCallback2(std::function<std::string(int)> func)
// {
//     // use the func
//     string s = func(2);
//     cout << s << endl;
// }; // param type is a function

// bind
float f(float x, float y)
{
    return x + y;
}

#include <functional>
#include <cassert>

// unordered_map example
#include <unordered_map>

// type traits
#include <type_traits>

// result_of
#include <type_traits>

int main()
{
    {
        cout << "should be 2: ";
        registerCallback([](int i) -> string
                         { return to_string(i); });
    }

    {
        // bind
        auto f2 = bind(f, 1, 2);
        assert(f2() == 3);

        auto f3 = bind(f, placeholders::_1, 2);
        assert(f3(1) == 3);
    }

    {
        // unordered_map
        unordered_map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
        for (auto p : m)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    {
        // type traits
        cout << is_same<int, int>::value << endl;
        cout << is_same<int, float>::value << endl;

        // compile time if
        if constexpr (is_same<int, int>::value)
        {
            cout << "int" << endl;
        }
        else
        {
            cout << "not int" << endl;
        }
    }

    {
        // result_of
    }

    return 0;
}
