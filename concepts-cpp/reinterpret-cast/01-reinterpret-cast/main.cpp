// Programme C++ illustrant l'utilisation de reinterpret_cast
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    {
        int *p = new int(65);
        char *ch = reinterpret_cast<char *>(p);
        cout << "(1): " << *p << endl;
        cout << "(2): " << *ch << endl;
        cout << "(3): " << int(*ch) << endl;
        cout << "(4): " << bitset<8>(*ch) << endl;
        cout << "====" << endl;
    }
    {
        int *p = new int(255);
        char *ch = reinterpret_cast<char *>(p);
        cout << "(1): " << *p << endl;
        cout << "(2): " << *ch << endl;
        cout << "(3): " << int(*ch) << endl;
        cout << "(4): " << bitset<8>(*ch) << endl;
        cout << "====" << endl;
    }
    {
        int *p = new int(256);
        char *ch = reinterpret_cast<char *>(p);
        cout << "(1): " << *p << endl;
        cout << "(2): " << *ch << endl;
        cout << "(3): " << int(*ch) << endl;
        cout << "(4): " << bitset<8>(*ch) << endl;
        cout << "====" << endl;
    }
    {
        int *p = new int(256 + 65);
        char *ch = reinterpret_cast<char *>(p);
        cout << "(1): " << *p << endl;
        cout << "(2): " << *ch << endl;
        cout << "(3): " << int(*ch) << endl;
        cout << "(4): " << bitset<8>(*ch) << endl;
        cout << "====" << endl;
    }
    return 0;
}