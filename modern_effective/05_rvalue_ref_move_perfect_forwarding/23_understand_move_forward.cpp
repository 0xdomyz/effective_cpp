// g++ 23_understand_move_forward.cpp -o 23_understand_move_forward && ./23_understand_move_forward

// • std::move performs an unconditional cast to an rvalue. In and of itself, it
// doesn’t move anything.
//
// • std::forward casts its argument to an rvalue only if that argument is bound
// to an rvalue.
//
// • Neither std::move nor std::forward do anything at runtime.
//
