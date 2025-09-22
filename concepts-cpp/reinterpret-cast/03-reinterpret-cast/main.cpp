// Code C++ illustrant l'utilisation de reinterpret_cast pour les pointeurs
#include <iostream>
using namespace std;

class A
{
public:
    void fun_a()
    {
        cout << "Dans la classe A\n";
    }
};

class B
{
public:
    void fun_b()
    {
        cout << "Dans la classe B\n";
    }
};

int main()
{
    // Création d'un objet de la classe B
    B *x = new B();

    // Conversion du pointeur vers un objet de la classe A
    A *new_a = reinterpret_cast<A *>(x);

    // Appel de la fonction de la classe A
    new_a->fun_a();
    return 0;
}