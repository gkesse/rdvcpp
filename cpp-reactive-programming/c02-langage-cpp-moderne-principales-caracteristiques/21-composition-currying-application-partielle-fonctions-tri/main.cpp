//------------ Compose.cpp
//------ g++ -std=c++ Compose.cpp
#include <iostream>
using namespace std;

// cas de base pour la compilation récursive
template <typename F, typename G>
auto Compose(F &&f, G &&g)
{
    return [=](auto x)
    {
        return f(g(x));
    };
}

// récursion sur les arguments lors de la compilation
template <typename F, typename... R>
auto Compose(F &&f, R &&...r)
{
    return [=](auto x)
    { return f(Compose(r...)(x)); };
}

auto CurriedAdd3(int x)
{
    // capture de la variable x
    return [x](int y)
    {
        return [x, y](int z)
        { return x + y + z; };
    };
};

template <typename... Ts>
auto PartialFunctionAdd3(Ts... xs)
{
    static_assert(sizeof...(xs) <= 3);
    if constexpr (sizeof...(xs) == 3)
    {
        // Base case: evaluate and return the sum.
        return (0 + ... + xs);
    }
    else
    {
        // Recursive case: bind `xs...` and return another
        return [xs...](auto... ys)
        {
            return PartialFunctionAdd3(xs..., ys...);
        };
    }
}

int main()
{
    // composition de deux fonctions
    auto val = Compose(
        [](int const a)
        {
            return std::to_string(a);
        },
        [](int const a)
        {
            return a * a;
        })(4);                // val = "16"
    cout << val << std::endl; // affichera 16
                              // appel de la fonction curryfiée
    auto p = CurriedAdd3(4)(5)(6);

    cout << p << endl;
    // composition de plusieurs fonctions
    auto func = Compose(
        [](int const n)
        {
            return std::to_string(n);
        },
        [](int const n)
        {
            return n * n;
        },
        [](int const n)
        {
            return n + n;
        },
        [](int const n)
        {
            return std::abs(n);
        });
    cout << func(5) << endl;
    // application partielle de la fonction
    PartialFunctionAdd3(1, 2, 3);
    PartialFunctionAdd3(1, 2)(3);
    PartialFunctionAdd3(1)(2)(3);
    return 0;
}