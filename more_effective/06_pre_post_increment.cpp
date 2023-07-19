// g++ 06_pre_post_increment.cpp -o pre_post_increment.out && ./pre_post_increment.out

// postfix take an int as a dummy parameter

// increment and fetch
// fetch and increment

// make postfix return a const object to prevent
// (i++).f() from compiling

// prefer prefix to postfix due to performance

// postfix is implemented in terms of prefix, to ensure consistency

class UPInt
{ // "unlimited precision int"
public:
    UPInt() : value(0) {}
    UPInt(int i) : value(i) {}

    UPInt &operator++();         // prefix ++
    const UPInt operator++(int); // postfix ++

    UPInt &operator--();         // prefix --
    const UPInt operator--(int); // postfix --

    UPInt &operator+=(int); // a += operator for UPInts
    // and ints
private:
    int value;
};

// prefix form: increment and fetch
UPInt &UPInt::operator++()
{
    *this += 1;   // increment
    return *this; // fetch
}

// postfix form: fetch and increment
const UPInt UPInt::operator++(int)
{
    const UPInt oldValue = *this; // fetch
    ++(*this);                    // increment
    return oldValue;              // return what was
}

UPInt &UPInt::operator--()
{
    *this += -1;  // decrement
    return *this; // fetch
}

const UPInt UPInt::operator--(int)
{
    const UPInt oldValue = *this; // fetch
    --(*this);                    // decrement
    return oldValue;              // return what was
}

UPInt &UPInt::operator+=(int i)
{
    value += i;
    return *this;
}

int main()
{
    UPInt i;
    ++i; // calls i.operator++();
    i++; // calls i.operator++(0);
    --i; // calls i.operator--();
    i--; // calls i.operator--(0);
}