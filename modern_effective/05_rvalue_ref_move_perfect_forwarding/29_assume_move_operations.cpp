// g++ 29_assume_move_operations.cpp -o 29_assume_move_operations && ./29_assume_move_operations

// • Assume that move operations are not present, not cheap, and not used.
// writing templates
// unstable code
//
// • In code with known types or support for move semantics, there is no need for
// assumptions
//
// move operations only auto generated if:
// • No user-declared copy operations
// • No user-declared move operations
// • No user-declared copy-and-swap
// • No user-declared destructor

//
// std::array
// SSO
// container that offer strong exception guarantee

// There are thus several scenarios in which C++11’s move semantics do you no good:
// • No move operations: The object to be moved from fails to offer move opera‐
// tions. The move request therefore becomes a copy request.
// • Move not faster: The object to be moved from has move operations that are no
// faster than its copy operations.
// • Move not usable: The context in which the moving would take place requires a
// move operation that emits no exceptions, but that operation isn’t declared noex
// cept.
// It’s worth mentioning, too, another scenario where move semantics offers no effi‐
// ciency gain:
// • Source object is lvalue: With very few exceptions (see e.g., Item 25) only rvalues
// may be used as the source of a move operation
