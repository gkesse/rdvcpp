// Code C++ illustrant l'utilisation d'une structure
#include <iostream>
using namespace std;

int main()
{
    {
        // Définition de la structure mystruct
        struct mystruct
        {
            int x;
            int y;
            char c;
            bool b;
        };

        mystruct s;

        // Affectation des valeurs
        s.x = 5;
        s.y = 10;
        s.c = 'a';
        s.b = true;

        cout << "(1): " << sizeof(s) << endl;
        cout << "(1): " << sizeof(int) << endl;
        cout << "(1): " << sizeof(char) << endl;
        cout << "(1): " << sizeof(bool) << endl;

        // Le type de données doit être le même lors du transtypage.

        // Conversion du pointeur de 's'
        // en pointeur de type int (dans 'p')
        int *p = reinterpret_cast<int *>(&s);

        // Affichage de la valeur pointée par *p
        cout << "(2): " << *p << endl;

        // Incrémentation du pointeur
        p++;

        // Affichage de la valeur entière suivante
        cout << "(3): " << *p << endl;

        // Incrémentation du pointeur
        p++;

        // Transtypage du pointeur p
        // en pointeur de type char (ch)
        char *ch = reinterpret_cast<char *>(p);

        // Affichage du caractère pointé par (*ch)
        cout << "(4): " << *ch << endl;

        // Incrémentation du pointeur
        ch++;

        // (*ch) pointe maintenant sur une valeur booléenne ;
        // il faut donc utiliser le même type
        // de conversion pour y accéder.
        // (*n) est donc de type bool.
        bool *n = reinterpret_cast<bool *>(ch);

        // Affichage du caractère pointé par (*n)
        cout << "(5): " << *n << endl;

        // On peut aussi utiliser cette instruction pour
        // afficher la valeur pointée par (*ch).
        cout << "(6): " << *(reinterpret_cast<bool *>(ch)) << endl;

        cout << "====" << endl;
    }
    {
        // Définition de la structure mystruct
        struct mystruct
        {
            bool b;
            char c;
            int x;
            int y;
        };

        mystruct s;

        // Affectation des valeurs
        s.b = true;
        s.c = 'a';
        s.x = 5;
        s.y = 10;

        cout << "(1): " << sizeof(s) << endl;

        // Le type de données doit être le même lors du transtypage.

        // Conversion du pointeur de 's'
        // en pointeur de type bool (dans 'p')
        bool *p = reinterpret_cast<bool *>(&s);

        // Affichage de la valeur pointée par *p
        cout << "(2): " << *p << endl;

        // Incrémentation du pointeur
        p++;

        // Transtypage du pointeur p
        // en pointeur de type char (ch)
        char *ch = reinterpret_cast<char *>(p);

        // Affichage de la valeur entière suivante
        cout << "(3): " << *ch << endl;

        // Incrémentation du pointeur
        ch++;

        // Transtypage du pointeur ch
        // en pointeur de type int (n)
        int *n = reinterpret_cast<int *>(ch);

        // Affichage du caractère pointé par (*n)
        cout << "(4): " << *n << endl;

        // Incrémentation du pointeur
        n++;

        // Affichage du caractère pointé par (*n)
        cout << "(5): " << *n << endl;
    }

    return 0;
}