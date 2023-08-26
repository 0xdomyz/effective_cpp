// g++ 28_understand_reference_collapsing.cpp -o 28_understand_reference_collapsing && ./28_understand_reference_collapsing

// • Reference collapsing occurs in four contexts: template instantiation, auto type
// generation, creation and use of typedefs and alias declarations, and
// decltype.
//
// • When compilers generate a reference to a reference in a reference collapsing
// context, the result becomes a single reference. If either of the original refer‐
// ences is an lvalue reference, the result is an lvalue reference. Otherwise it’s an
// rvalue reference.
//
// • Universal references are rvalue references in contexts where
// type deduction distinguishes lvalues from rvalues
// Lvalues of type T are
// deduced to have type T&, while rvalues of type T yield T as their deduced type.
//
// and where reference collapsing occurs.
//
