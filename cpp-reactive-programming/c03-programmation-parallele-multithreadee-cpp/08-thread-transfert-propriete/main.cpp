void fonction1()
{
    std::cout << "Fonction 1\n";
}
void fonction2()
{
    std::cout << "Fonction 2\n";
}

int main()
{
    std::thread t1(fonction1);
    // Transfert de la propriété du thread de t1 vers t2
    std::thread t2 = std::move(t1);
    t1 = std::thread(fonction2);
    // Objet vide, ne gérant aucun thread
    std::thread t3;
    // Transfert de la propriété du thread de t2 vers t3
    t3 = std::move(t2);
    // Il n'est pas nécessaire d'attendre la fin de t2 :
    // il ne gère plus de thread
    if (t1.joinable())
        t1.join();
    if (t3.joinable())
        t3.join();
    return 0;
}

// La prise en charge de la sémantique de déplacement
// par la classe std::thread permet de transférer
// la propriété du thread hors de la fonction.
void func()
{
    std::cout << "func()\n";
}
std::thread thread_creator()
{
    return std::thread(func);
}
void thread_wait_func()
{
    std::thread t = thread_creator();
    t.join();
}
