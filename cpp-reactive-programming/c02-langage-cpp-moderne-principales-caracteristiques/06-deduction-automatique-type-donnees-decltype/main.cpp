#include <iostream>
using namespace std;

int foo() { return 10; }
char bar() { return 'g'; }
auto fancy() -> decltype(1.0f) { return 1; }

int main()
{
    decltype(foo()) x;
    decltype(bar()) y;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    struct A
    {
        double x;
    };

    const A *a = new A();

    decltype(a->x) z;
    decltype((a->x)) t = z;

    cout << typeid(z).name() << endl;
    cout << typeid(t).name() << endl;
    cout << typeid(decltype(fancy())).name() << endl;

    return 0;
}
