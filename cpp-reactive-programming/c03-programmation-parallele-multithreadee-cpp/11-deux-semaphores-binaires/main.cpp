// Mutexes globaux
std::mutex evenMutex;
std::mutex oddMutex;

// Fonction pour afficher les nombres pairs
void printEven(int max)
{
    for (unsigned i = 0; i <= max; i += 2)
    {
        oddMutex.lock();
        std::cout << i << ",";
        evenMutex.lock();
        oddMutex.unlock();
        evenMutex.unlock();
    }
}

// Fonction pour afficher les nombres impairs
void printOdd(int max)
{
    for (unsigned i = 1; i <= max; i += 2)
    {
        evenMutex.lock();
        std::cout << i << ",";
        oddMutex.lock();
        evenMutex.unlock();
        oddMutex.unlock();
    }
}

int main()
{
    auto max = 100;
    std::thread t1(printEven, max);
    std::thread t2(printOdd, max);
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    return 0;
}

// Ce code est susceptible de provoquer un blocage,
// car chaque thread attend que le sémaphore verrouillé par un autre thread
// soit libéré, tout en maintenant verrouillé le sémaphore dont
// un autre thread a besoin pour libérer le premier.

void printEven(int max)
{
    for (unsigned i = 0; i <= max; i += 2)
    {
        evenMutex.lock();
        std::cout << i << ",";
        oddMutex.lock();
        evenMutex.unlock();
        oddMutex.unlock();
    }
}

void printOdd(int max)
{
    for (unsigned i = 1; i <= max; i += 2)
    {
        evenMutex.lock();
        std::cout << i << ",";
        oddMutex.lock();
        evenMutex.unlock();
        oddMutex.unlock();
    }
}

// un tel code est difficile à comprendre,
// car le programmeur doit s'assurer que l'ordre des opérations soit identique
// dans toutes les fonctions qui utilisent ces sémaphores.

void printEven(int max)
{
    for (unsigned i = 0; i <= max; i += 2)
    {
        std::lock(evenMutex, oddMutex);
        std::lock_guard<std::mutex> lk_even(
            evenMutex, std::adopt_lock);
        std::lock_guard<std::mutex> lk_odd(
            oddMutex, std::adopt_lock);
        std::cout << i << ",";
    }
}
void printOdd(int max)
{
    for (unsigned i = 1; i <= max; i += 2)
    {
        std::lock(evenMutex, oddMutex);
        std::lock_guard<std::mutex> lk_even(
            evenMutex, std::adopt_lock);
        std::lock_guard<std::mutex> lk_odd(
            oddMutex, std::adopt_lock);
        std::cout << i << ",";
    }
}

// la fonction std::lock acquiert les deux sémaphores.
// Ensuite, deux objets de type std::lock_guard
// sont créés, un pour chaque sémaphore. Lors de la création de ces objets,
// l'argument std::adopt_lock est passé au constructeur, indiquant que le sémaphore
// est déjà acquis et que le constructeur n'a donc pas besoin de tenter de l'acquérir.
// Les destructeurs de ces objets libéreront les sémaphores, même en cas d'exception
// dans la section critique.

// En conclusion, la fonction std::lock permet d'éviter les blocages si tous les threads
// l'utilisent pour acquérir simultanément plusieurs sémaphores.