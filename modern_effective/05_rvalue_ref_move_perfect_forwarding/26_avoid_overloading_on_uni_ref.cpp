// g++ 26_avoid_overloading_on_uni_ref.cpp -o 26_avoid_overloading_on_uni_ref && ./26_avoid_overloading_on_uni_ref

// • Overloading on universal references almost always leads to the universal refer‐
// ence overload being called more frequently than expected.
//
// • Perfect-forwarding constructors are especially problematic, because they’re
// typically better matches than copy constructors for non-const lvalues, and
// they can hijack derived class calls to base class copy and move constructors.
//