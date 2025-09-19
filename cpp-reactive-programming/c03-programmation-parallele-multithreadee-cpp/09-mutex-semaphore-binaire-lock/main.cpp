#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
std::mutex m;
int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(
            [i]()
            {
                m.lock();
                std::cout << "Thread " << i << std::endl;
                m.unlock();
            }));
    }
    std::for_each(
        threads.begin(),
        threads.end(),
        [](std::thread &t)
        {
            t.join();
        });
    return 0;
}

// Contrairement à la première version de cet exemple,
// la présence d 'une section critique permet de garantir
// que les messages affichés par les différents threads
// ne seront pas mélangés (bien que l' ordre d'affichage reste imprévisible)

// Il convient toutefois de noter que l'utilisation directe
// des méthodes lock et unlock de la classe std::mutex est une mauvaise pratique,
// car le programmeur doit alors gérer manuellement la libération du sémaphore
// pour tous les chemins d'exécution possibles menant à la sortie
// de la section critique, y compris en cas d'exception.
