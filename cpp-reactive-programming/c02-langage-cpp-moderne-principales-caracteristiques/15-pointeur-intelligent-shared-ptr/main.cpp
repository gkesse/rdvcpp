#include <iostream>
#include <deque>
#include <memory>
using namespace std;

int main(int argc, char **argv)
{
    std::shared_ptr<int> ptr_1(new int(500));
    std::weak_ptr<int> wptr_1 = ptr_1;
    {
        std::shared_ptr<int> ptr_2 = wptr_1.lock();
        if (ptr_2)
        {
            cout << *ptr_2 << endl; // sera exécuté
        }
        // Fin de la portée de visibilité de l'objet ptr_2
    }
    ptr_1.reset(); // L'objet est détruit
    std::shared_ptr<int> ptr_3 = wptr_1.lock();
    if (ptr_3)
        cout << *ptr_3 << endl;
    else
        cout << "The pointer is empty" << endl;
    return 0;
}
