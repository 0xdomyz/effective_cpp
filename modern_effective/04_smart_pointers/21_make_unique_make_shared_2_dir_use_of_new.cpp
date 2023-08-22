// g++ 21_make_unique_make_shared_2_dir_use_of_new.cpp -o 21_make_unique_make_shared_2_dir_use_of_new && ./21_make_unique_make_shared_2_dir_use_of_new

// • Compared to direct use of new, make functions eliminate source code duplica‐
// tion, improve exception safety, and, for std::make_shared and std::allo
// cate_shared, generate code that’s smaller and faster.
//
// • Situations where use of make functions is inappropriate include the need to
// specify custom deleters and a desire to pass braced initializers.
//
// • For std::shared_ptrs, additional situations where make functions may be
// ill-advised include (1) classes with custom memory management and (2) sys‐
// tems with memory concerns, very large objects, and std::weak_ptrs that
// outlive the corresponding std::shared_ptrs.
