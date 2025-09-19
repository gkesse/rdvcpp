// Merci à Dennis Ritchie et Brian Kernighan
// pour cette convention de codage
#include <iostream>
int main()
{
    std::cout << "Hello world\n";
    return 0;
}

#include <iostream>
#include <string>
#include <thread>

// Cette fonction sera exécutée dans un thread séparé
void thread_proc(std::string msg)
{
    std::cout << "thread_proc : " << msg;
}

int main()
{
    // Création d'un thread et exécution de la fonction 'thread_proc'
    std::thread t(thread_proc, "Bonjour le monde !\n");
    // Attente de la fin du thread avant la terminaison du programme
    t.join();
}
