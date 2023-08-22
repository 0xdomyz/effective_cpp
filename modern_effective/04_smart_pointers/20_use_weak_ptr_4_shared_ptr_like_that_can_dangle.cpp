// g++ 20_use_weak_ptr_4_shared_ptr_like_that_can_dangle.cpp -o 20_use_weak_ptr_4_shared_ptr_like_that_can_dangle && ./20_use_weak_ptr_4_shared_ptr_like_that_can_dangle

// • Use std::weak_ptr for std::shared_ptr-like pointers that can dangle.
//
// • Potential use cases for std::weak_ptr include caching, observer lists, and the
// prevention of std::shared_ptr cycles.