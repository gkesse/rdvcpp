class parallel_job
{
    int &_iterations;

public:
    parallel_job(int &iterations)
        : _ iterations(iterations)
    {
    }
    void operator()()
    {
        for (int i = 0; i < _iterations; ++i)
        {
            some_implementation(i); // une certaine implémentation
        }
    }
};

void func()
{
    int local_var = 10000;
    parallel_job job(local_var);
    std::thread t(job);
    if (t.joinable())
        t.join();
}

// Il existe un mécanisme standard permettant à un thread
// de continuer à fonctionner même après la fin de la fonction
// qui l'a créé : la méthode `detach()`.
if (t.joinable())
    t.detach();

// La solution habituelle consiste à rendre le thread autonome
// et à copier les données nécessaires à son fonctionnement,
// plutôt que de les partager via des pointeurs.
