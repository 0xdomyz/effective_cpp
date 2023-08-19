// g++ 01_template_type_deduct.cpp -o 01_template_type_deduct && ./01_template_type_deduct

template <typename T>
void f(const T &param){}; // ParamType is const T&

int main()
{
    int x = 0;
    f(x); // call f with an int
}