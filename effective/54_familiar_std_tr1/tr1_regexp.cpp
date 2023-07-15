// g++ tr1_regexp.cpp -o tr1_regexp && ./tr1_regexp

#include <string>
#include <iostream>

using namespace std;

// function

// regexp
#include <regex>
#include <cassert>

int main()
{

    {
        // regexp
        regex r("abc");
        string s = "abc";
        assert(regex_match(s, r));

        regex r2("abc", regex_constants::icase);
        string s2 = "ABC";
        assert(regex_match(s2, r2));

        // numbers that start with 04 and has length 10
        regex r3("04[0-9]{8}");
        string s3 = "0412345678";
        assert(regex_match(s3, r3));
        string s4 = "05123456789";
        assert(!regex_match(s4, r3));

        // 3 capital letter , hyphen, 4 digits
        regex r4("[A-Z]{3}-[0-9]{4}");
        string s5 = "ABC-1234";
        assert(regex_match(s5, r4));
        string s6 = "ABC-12345";
        assert(!regex_match(s6, r4));
    }

    return 0;
}
