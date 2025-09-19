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
                std::lock_guard<std::mutex> guard(m);
                std::cout << "Thread " << i << std::endl;
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

// L'objet de type std::lock_guard est local et est créé à chaque fois
// qu'un thread entre dans la section critique. Une fois créé et le thread
// ayant poursuivi son exécution, on peut être certain que le sémaphore binaire
// est verrouillé. Dès que le thread sort de la portée de l'objet guard,
// son destructeur est automatiquement appelé, ce qui libère le sémaphore.