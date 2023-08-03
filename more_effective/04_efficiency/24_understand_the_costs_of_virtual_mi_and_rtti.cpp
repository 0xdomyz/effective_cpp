// g++ 24_understand_the_costs_of_virtual_mi_and_rtti.cpp -o 24_understand_the_costs_of_virtual_mi_and_rtti && ./24_understand_the_costs_of_virtual_mi_and_rtti

//                      | increases       |Increases        |Reduces
// Feature              | Size of Objects |Per-Class Data   |Inlining
// Virtual Functions    | Yes             |Yes              |Yes
// Multiple Inheritance | Yes             |Yes              |No
// Virtual Base Classes |Often            |Sometimes        |No
// RTTI                 |No               |Yes              |No

// From the point of view of efficiency,
// however, you are unlikely to do better than the compiler
// generated implementations by coding these features yourself
