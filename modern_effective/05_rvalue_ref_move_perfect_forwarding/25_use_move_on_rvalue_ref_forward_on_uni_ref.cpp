// g++ 25_use_move_on_rvalue_ref_forward_on_uni_ref.cpp -o 25_use_move_on_rvalue_ref_forward_on_uni_ref && ./25_use_move_on_rvalue_ref_forward_on_uni_ref

// • Apply std::move to rvalue references and std::forward to universal refer‐
// ences the last time each is used.
//
// • Do the same thing for rvalue references and universal references being
// returned from functions that return by value.
//
// • Never apply std::move or std::forward to local objects if they would other‐
// wise be eligible for the return value optimization.
//

// compilers may elide the copying (or moving) of a local object2
//  in a
// function that returns by value if (1) the type of the local object is the same as that
// returned by the function and (2) the local object is what’s being returned.