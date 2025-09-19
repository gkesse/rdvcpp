#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Display *affichage;
    Window fenetre;
    XEvent evenement;
    char *message = "Bonjour le monde !";
    int ecran;

    /* Ouverture de la connexion au serveur X */
    affichage = XOpenDisplay(NULL);
    if (affichage == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir la connexion au serveur X\n");
        exit(1);
    }
    ecran = DefaultScreen(affichage);
    /* Création de la fenêtre */
    fenetre = XCreateSimpleWindow(affichage,
                                  RootWindow(affichage, ecran), 10, 10, 200, 200, 1,
                                  BlackPixel(affichage, ecran), WhitePixel(affichage, ecran));
    /* Sélection des types d'événements à surveiller */
    XSelectInput(affichage, fenetre, ExposureMask | KeyPressMask);
    /* Affichage de la fenêtre */
    XMapWindow(affichage, fenetre);

    /* Boucle d'événements */
    while (1)
    {
        XNextEvent(affichage, &evenement);
        /* Dessin ou redessin de la fenêtre */
        if (evenement.type == Expose)
        {
            XFillRectangle(affichage, fenetre,
                           DefaultGC(affichage, ecran), 20, 20, 10, 10);
            XDrawString(affichage, fenetre,
                        DefaultGC(affichage, ecran), 50, 50, message, strlen(message));
        }
        /* Sortie de la boucle à la pression d'une touche */
        if (evenement.type == KeyPress)
            break;
    }
    /* Fermeture de la connexion au serveur X */
    XCloseDisplay(affichage);
    return 0;
}
