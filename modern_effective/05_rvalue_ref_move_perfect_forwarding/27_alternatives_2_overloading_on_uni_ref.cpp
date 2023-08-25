// g++ 27_alternatives_2_overloading_on_uni_ref.cpp -o 27_alternatives_2_overloading_on_uni_ref && ./27_alternatives_2_overloading_on_uni_ref

// • Alternatives to the combination of universal references and overloading
// include the use of distinct function names, passing parameters by lvalue
// reference-to-const, passing parameters by value,
//
// and using tag dispatch.
//
// • Constraining templates via std::enable_if permits the use of universal ref‐
// erences and overloading together, but it controls the conditions under which
// compilers may use the universal reference overloads.
//
// • Universal reference parameters often have efficiency advantages, but they typ‐
// ically have usability disadvantages
//

// overloading resolution
// Calls to overloaded functions are resolved by looking at all
// the parameters of all the overloads as well as all the arguments at the call site, then
// choosing the function with the best overall match—taking into account all parame‐
// ter/argument combinations.

// tag dispatch
// The call to the overloaded implementation functions inside logAndAdd
// “dispatches” the work to the correct overload by causing the proper tag object to be
// created. Hence the name for this design: tag dispatch. It’s a standard building block of
// template metaprogramming
