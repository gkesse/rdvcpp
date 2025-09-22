// Programme C illustrant la taille d'une structure
#include <stdio.h>

int main()
{

    struct A
    {
        // sizeof(int) = 4
        int x;
        // Remplissage de 4 octets

        // sizeof(double) = 8
        double z;
        // Remplissage de 0 octets

        // sizeof(short int) = 2
        short int y;
        // Remplissage de 6 octets
    };

    printf("(1): Taille de la structure : %d octets\n", (int)sizeof(struct A));

    struct B
    {
        // sizeof(double) = 8
        double z;
        // Remplissage de 0 octets

        // sizeof(int) = 4
        int x;
        // Remplissage de 0 octets

        // sizeof(short int) = 2
        short int y;
        // Remplissage de 2 octets
    };

    printf("(2): Taille de la structure : %d octets\n", (int)sizeof(struct B));

    struct C
    {
        // sizeof(double) = 8
        double z;
        // Remplissage de 0 octets

        // sizeof(short int) = 2
        short int y;
        // Remplissage de 2 octets

        // sizeof(int) = 4
        int x;
        // Remplissage de 0 octets
    };

    printf("(3): Taille de la structure : %d octets\n", (int)sizeof(struct C));

    return 0;
}