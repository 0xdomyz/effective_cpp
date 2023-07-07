// g++ decl_and_func.cpp -o decl_and_func && ./decl_and_func

class Date;                     // class declaration
Date today();                   // fine — no definition
void clearAppointments(Date d); // of Date is needed

int main() {}