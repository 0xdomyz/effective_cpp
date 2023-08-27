// g++ 30_perfect_forwarding_failure_cases.cpp -o 30_perfect_forwarding_failure_cases && ./30_perfect_forwarding_failure_cases

// • Perfect forwarding fails when template type deduction fails or when it deduces
// the wrong type.
//
// • The kinds of arguments that lead to perfect forwarding failure are braced ini‐
// tializers, null pointers expressed as 0 or NULL, declaration-only integral const
// static data members, template and overloaded function names, and bitfields.
//