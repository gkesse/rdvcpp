#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;

// Les objets de type shared_ptr<T> peuvent être transmis par valeur :
// la copie de ce pointeur intelligent pointe vers le même objet,
// et le constructeur de copie incrémente le compteur de références.
void foo_byvalue(std::shared_ptr<int> i)
{
    (*i)++;
}

// La transmission d'un objet shared_ptr<T>
// par référence ne crée pas de copie.
void foo_byreference(std::shared_ptr<int> &i)
{
    (*i)++;
}

int main(int argc, char **argv)
{
    auto sp = std::make_shared<int>(10);
    foo_byvalue(sp);
    foo_byreference(sp);
    // La valeur affichée devrait être 12
    std::cout << *sp << std::endl;
    return 0;
}