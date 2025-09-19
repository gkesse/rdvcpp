// Variadic.cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int add() { return 0; }

template <class T0, class... Ts>
decltype(auto) add(T0 first, Ts... rest)
{
    return first + add(rest...);
}

int main()
{
    int n = add(0, 2, 3, 4);
    cout << n << endl;
    return 0;
}
