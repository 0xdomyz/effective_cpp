// g++ 24_dist_uni_ref_from_rvalue_ref.cpp -o 24_dist_uni_ref_from_rvalue_ref && ./24_dist_uni_ref_from_rvalue_ref

// • If a function template parameter has type T&& for a deduced type T, or if an
// object is declared using auto&&, the parameter or object is a universal refer‐
// ence.
//
// • If the form of the type declaration isn’t precisely type&&, or if type deduction
// does not occur, type&& denotes an rvalue reference.
//
// • Universal references correspond to rvalue references if they’re initialized with
// rvalues. They correspond to lvalue references if they’re initialized with lval‐
// ues.
//