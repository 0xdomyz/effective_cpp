// g++ 30_proxy_classes.cpp -o 30_proxy_classes && ./30_proxy_classes

// can't create 2D array with run time dimensions using C++ built-ins

// implementing 2D arrays
// #################
// create via class
// but there is no operator[][] for desired syntax
// () operator can be used but it looks like a function call
// based on built in 2d array, can create Array1D and overload operator[] twice

// Objects that
// stand for other objects are often called proxy objects, and the classes
// that give rise to proxy objects are often called proxy classes.
// there objects are also called surrogates

// Distinguishing Reads from Writes via operator[]
// #################

// Of the varied uses of proxy
// classes, however, the most heralded is that of helping distinguish
// reads from writes through operator[].

// operator[] can be called in two different contexts: to read
// a character or to write a character. Reads are known as rvalue usages;
// writes are known as lvalue usages.

// In general, using an object
// as an lvalue means using it such that it might be modified, and using
// it as an rvalue means using it such that it cannot be modified.

// inside operator[], there is no
// way to determine the context in which the function was called

// Compilers choose between const and nonconst member functions by looking only
// at whether the object invoking a function is const. No consideration is given to
// the context in which a call is made.
// therefore overload operator[] on the basis of its constness wont work

// can still treat reads differently
// from writes if we delay our lvalue-versus-rvalue actions until we see
// how the result of operator[] is used.
// All we need is a way to postpone
// our decision on whether our object is being read or written until after
// operator[] has returned. (This is an example of lazy evaluation

// have operator[] return a proxy for string char, then wait to see how the proxy is used

// the 3 things you can do with a proxy
//
// Create it, i.e., specify which string character it stands for.
//
// Use it as the target of an assignment, in which case you are really
// making an assignment to the string character it stands for. When
// used in this way, a proxy represents an lvalue use of the string on
// which operator[] was invoked.
//
// Use it in any other way. When used like this, a proxy represents
// an rvalue use of the string on which operator[] was invoked.

// limitations
// #################

// objects are used as
// lvalues in contexts other than just assignment, and using proxies in
// such contexts usually yields behavior different from using real objects

// In general, taking the address of a proxy yields a different
// type of pointer than does taking the address of a real object.
//
// overload the address-of operator to solve

// if we have a template for reference-counted
// arrays that use proxy classes to distinguish lvalue and rvalue invocations of
// operator[]
//
// then there are operators that require lvalues, including operator*=, operator<<=,
//  operator--, operator++, has to be overloaded to work with proxy classes

// A related problem has to do with invoking member functions on real
// objects through proxies. To be blunt about it, you can’t

// when being passed to functions that take references to non-const objects
// in an example, swap takes char& parameters, not a proxy object
//  the char to which it may be converted can’t be bound to swap’s
// char& parameters, because that char is a temporary object

// When a proxy object is implicitly converted into the real object it stands for,
// a user-defined conversion function is invoked.
// compilers may use only one user-defined conversion function when
// converting a parameter at a call site into the type needed.
// it is possible for function
// calls that succeed when passed real objects to fail when passed proxies

// evaluation
// #################
//
// Pro
// Proxy classes can be used to achieve behavior that is difficult or impossible to
//  implement otherwise, such as multidimensional arrays and lvalue/rvalue differentiation.
//
// Con
//   However, they have disadvantages such as being temporaries and increasing the
//    complexity of software systems.
// Additionally, proxy objects often exhibit behavior
//     that is subtly different from that of the real objects they represent, which can
//     change the semantics of the class.
//     but in many cases there is little
//      need for the operations that would make the presence of proxies apparent to clien
