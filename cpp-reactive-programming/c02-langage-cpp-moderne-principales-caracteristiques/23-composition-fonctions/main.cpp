#include <iostream>
using namespace std;

struct AddOne
{
    template <class T>
    auto operator()(T x) const
    {
        return x + 1;
    }
};

struct SumFunction
{
    // fonction à deux arguments
    template <class T>
    auto operator()(T x, T y) const
    {
        return x + y;
    }
};

// Fonction unaire avec fermeture
// Utilisation d'un modèle à nombre variable d'arguments
template <class F>
struct PipableClosure : F
{
    template <class... Xs>
    PipableClosure(Xs &&...xs)
        // Xs – référence universelle
        // passage par valeur parfaite
        : F(std::forward<Xs>(xs)...)
    {
    }
};

// Fonction de conversion d'une fonction en fermeture
template <class F>
auto MakePipeClosure(F f)
{
    return PipableClosure<F>(std::move(f));
}

// Fermeture pour une fonction à deux arguments
template <class F>
struct PipableClosureBinary
{
    template <class... Ts>
    auto operator()(Ts... xs) const
    {
        return MakePipeClosure(
            [=](auto x) -> decltype(auto)
            { return F()(x, xs...); });
    }
};

// Opération de composition
// Utilisation de la transmission par référence universelle
template <class T, class F>
decltype(auto) operator|(T &&x, const PipableClosure<F> &pfn)
{
    return pfn(std::forward<T>(x));
}

int main()
{
    // Fermeture d'une fonction unaire
    const PipableClosure<AddOne> fnclosure = {};
    int value = 1 | fnclosure | fnclosure;
    std::cout << value << std::endl;
    // Fermeture d'une fonction à deux arguments
    const PipableClosureBinary<SumFunction> sumfunction = {};
    int value1 = 1 | sumfunction(2) | sumfunction(5) | fnclosure;
    std::cout << value1 << std::endl;
}
