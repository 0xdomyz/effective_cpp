// g++ 09_prefer_alias_decl_2_typedefs.cpp -o 09_prefer_alias_decl_2_typedefs && ./09_prefer_alias_decl_2_typedefs

// • typedefs don’t support templatization, but alias declarations do.
// • Alias templates avoid the “::type” suffix and, in templates, the “typename”
// prefix often required to refer to typedefs.
// • C++14 offers alias templates for all the C++11 type traits transformations.