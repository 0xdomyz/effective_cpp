// g++ 16_make_const_member_funcs_thread_safe.cpp -o 16_make_const_member_funcs_thread_safe && ./16_make_const_member_funcs_thread_safe

// • Make const member functions thread safe unless you’re certain they’ll never
// be used in a concurrent context.
// • Use of std::atomic variables may offer better performance than a mutex, but
// they’re suited for manipulation of only a single variable or memory location.
