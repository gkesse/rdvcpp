// FuncWrapper.cpp, требуется C++ 17 (-std=c++1z )
#include <functional>
#include <iostream>
using namespace std;

// Fonction simple
void PrintNumber(int val)
{
    cout << val << endl;
}

// Classe avec opérateur d'appel surchargé
struct PrintNumber
{
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

// Nécessaire pour appeler la méthode
struct FooClass
{
    int number;
    FooClass(int pnum)
        : number(pnum)
    {
    }

    void PrintNumber(int val) const
    {
        std::cout << number + val << endl;
    }
};

int main()
{
    // Wrapper autour d'une fonction standard
    std::function<void(int)> displaynum = PrintNumber;
    displaynum(0xF000);

    // Appel via std::invoke
    std::invoke(displaynum, 0xFF00);

    // Wrapper autour d'une fonction lambda
    std::function<void()> lambdaprint = []()
    {
        PrintNumber(786);
    };

    lambdaprint();
    std::invoke(lambdaprint);

    // Wrapper autour d'une méthode de classe
    std::function<void(const FooClass &, int)>
        classdisplay = &FooClass::PrintNumber;

    // Création d'une instance
    const FooClass fooinstance(100);
    classdisplay(fooinstance, 100);
}
