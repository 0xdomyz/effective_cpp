// g++ zero.cpp -o zero && ./zero

class CantBeInstantiated
{
private:
    CantBeInstantiated(){};
    CantBeInstantiated(const CantBeInstantiated &){};
};

int main()
{
    // CantBeInstantiated obj1;       // error: ‘CantBeInstantiated::CantBeInstantiated()’ is private
    // CantBeInstantiated obj2(obj1); // error: ‘CantBeInstantiated::CantBeInstantiated(const CantBeInstantiated&)’ is private
    return 0;
}
