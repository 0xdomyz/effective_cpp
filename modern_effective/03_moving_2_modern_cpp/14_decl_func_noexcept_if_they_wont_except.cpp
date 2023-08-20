// g++ 14_decl_func_noexcept_if_they_wont_except.cpp -o 14_decl_func_noexcept_if_they_wont_except && ./14_decl_func_noexcept_if_they_wont_except

// • noexcept is part of a function’s interface, and that means that callers may
// depend on it.
// • noexcept functions are more optimizable than non-noexcept functions.
// • noexcept is particularly valuable for the move operations, swap, memory
// deallocation functions, and destructors.
// • Most functions are exception-neutral rather than noexcept.
