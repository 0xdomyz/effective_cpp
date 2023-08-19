// g++ 02_understand_auto_type_deduction.cpp -o 02_understand_auto_type_deduction && ./02_understand_auto_type_deduction

// • auto type deduction is usually the same as template type deduction, but auto
// type deduction assumes that a braced initializer represents a std::initial
// izer_list, and template type deduction doesn’t.

// • auto in a function return type or a lambda parameter implies template type
// deduction, not auto type deduction.
