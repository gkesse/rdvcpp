// LambdaFourth.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// fonctions génériques pour la comparaison et l'échange
template <typename T>
bool Cmp(T const &a, T const &b)
{
    return (a > b);
}

template <typename T>
void Swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

// Les modèles de fonctions Cmp et Swap seront utilisés
// ci-dessous pour comparer deux éléments du tableau et les échanger.
// template <class T>
template <class T>
void SelectionSort(T *arr, int length)
{
    for (int i = 0; i < length - 1; ++i)
        for (int j = i + 1; j < length; ++j)
            if (Cmp(arr[i], arr[j]))
                Swap(arr[i], arr[j]);
}

template <typename T>
void SelectionSorLambda(T *arr, int length)
{
    auto CmpLambda = [](const auto &a, const auto &b)
    {
        return (a > b);
    };

    auto SwapLambda = [](auto &a, auto &b)
    {
        auto c = a;
        a = b;
        b = c;
    };

    for (int i = 0; i < length - 1; ++i)
        for (int j = i + 1; j < length; ++j)
            if (CmpLambda(arr[i], arr[j]))
                SwapLambda(arr[i], arr[j]);
}

int main(int argc, char **argv)
{
    double ar1[4] = {20, 10, 15, -41};
    SelectionSort(ar1, 4);
    for (int i = 0; i != 4; ++i)
        cout << ar1[i] << "\n";

    double ar2[4] = {20, 10, 15, -41};
    SelectionSorLambda(ar2, 4);
    for (int i = 0; i != 4; ++i)
        cout << ar2[i] << "\n";
    return 0;
}
