// g++ 18_use_unique_ptr_4_exclusive_own_man.cpp -o 18_use_unique_ptr_4_exclusive_own_man && ./18_use_unique_ptr_4_exclusive_own_man

// • std::unique_ptr is a small, fast, move-only smart pointer for managing
// resources with exclusive-ownership semantics.
// • By default, resource destruction takes place via delete, but custom deleters
// can be specified. Stateful deleters and function pointers as deleters increase the
// size of std::unique_ptr objects.
// • Converting a std::unique_ptr to a std::shared_ptr is easy.

#include <iostream>
#include <memory>

class Investment
{
public:
    virtual ~Investment(){}; // design
};
class Stock : public Investment
{
};
class Bond : public Investment
{
};
class RealEstate : public Investment
{
};

void makeLogEntry(Investment *pInvestment)
{
    std::cout << "makeLogEntry" << std::endl;
}

template <typename... Ts>
auto makeInvestment(int nbr, Ts &&...params) // C++14
{
    auto delInvmt = [](Investment *pInvestment) // this is now
    {                                           // inside
        makeLogEntry(pInvestment);              // make-
        delete pInvestment;                     // Investment
    };
    std::unique_ptr<Investment, decltype(delInvmt)> // as
        pInv(nullptr, delInvmt);                    // before
    if (nbr == 0)                                   // as before
    {
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    }
    else if (nbr == 1)
    {
        pInv.reset(new Bond(std::forward<Ts>(params)...));
    }
    else if (nbr == 2) // as before
    {
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    }
    return pInv; // as before
}

int main()
{
    auto pInvestment = makeInvestment(0);
    auto pInvestment2 = makeInvestment(1);
    auto pInvestment3 = makeInvestment(2);
    return 0;
}