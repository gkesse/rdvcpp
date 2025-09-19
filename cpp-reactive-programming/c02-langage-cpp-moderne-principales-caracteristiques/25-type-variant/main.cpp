#include <variant>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    std::variant<int, float, string> v, w;
    v = 12.0f; // Contient une valeur de type float
    cout << std::get<1>(v) << endl;
    w = 20; // Affectation d'une valeur de type int
    cout << std::get<0>(w) << endl;
    w = "hello"s; // Affectation d'une chaîne de caractères
    cout << std::get<2>(w) << endl;
}
