// g++ 35_familiarize_yourself_with_the_language_standard.cpp -o 35_familiarize_yourself_with_the_language_standard && ./35_familiarize_yourself_with_the_language_standard

// capabilities of the std
// Support for the standard C library
// Support for strings
// Support for localization
// Support for I/O
// Support for numeric applications
// Support for general-purpose containers and algorithms, STL

// two idiosyncrasies
//
// 1
// almost everything in the library is a template
// generalize it
// and make the generalization a template — is repeated throughout the
// standard C++ library.
//
// 2
// virtually everything it contains is inside the namespace std

// If the
// pointer points to the element beyond the end of the array, it can be
// The C++ Language and Library Standard 281
// compared only to other pointers to the array; the results of dereferencing it are undefined

// At its core, STL is very simple. It is just a collection of class and function
// templates that adhere to a set of conventions
//
// The STL collection
// classes provide functions like begin and end that return iterator objects of types
//  defined by the classes. The STL algorithm functions move
// through collections of objects by using iterator objects over STL collections.
// STL iterators act like pointers

//  As long as
// you follow the STL conventions, the standard STL collections will work
// with your algorithms and your collections will work with the standard
// STL algorithms.
