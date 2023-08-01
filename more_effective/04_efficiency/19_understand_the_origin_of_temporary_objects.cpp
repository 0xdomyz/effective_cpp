// g++ 19_understand_the_origin_of_temporary_objects.cpp -o 19_understand_the_origin_of_temporary_objects && echo "r rt56fr" | ./19_understand_the_origin_of_temporary_objects

// arise whenever a non-heap object is created but not named.
// when implicit type conversions are applied to make function
// calls succeed
// when functions return objects

#include <iostream>
#include <iomanip>

using namespace std;

static const size_t MAX_STRING_LEN = 100;

// returns the number of occurrences of ch in str
size_t countChar(const string &str, char ch)
{
    size_t count = 0;
    for (size_t i = 0; i < str.length(); ++i)
        if (str[i] == ch)
            ++count;
    return count;
};

int main(void)
{
    char buffer[MAX_STRING_LEN];
    char c;
    // read in a char and a string; use setw to avoid
    // overflowing buffer when reading the string

    cin >> c >> setw(MAX_STRING_LEN) >> buffer;
    cout << "There are " << countChar(buffer, c)
         << " occurrences of the character " << c
         << " in " << buffer << endl;
}

// These conversions occur only when passing objects by value or when
// passing to a reference-to-const parameter. They do not occur when
// passing an object to a reference-to-non-const parameter.

// Anytime you see a reference-to-const parameter,the possibility exists
// that a temporary will be created to bind to thatparameter.
// Anytime you see a function returning an object, a temporary will be
// created (and later destroyed).