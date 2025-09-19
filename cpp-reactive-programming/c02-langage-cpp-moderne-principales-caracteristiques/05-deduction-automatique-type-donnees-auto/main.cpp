#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;
int main()
{
    vector<double> vtdbl = {0, 3.14, 2.718, 10.00};
    auto vt_dbl2 = vtdbl;
    auto size = vt_dbl2.size();
    auto &rvec = vtdbl;
    cout << size << endl;

    for (auto it = vtdbl.begin(); it != vtdbl.end(); ++it)
        cout << *it << " ";

    for (auto it2 = vt_dbl2.begin(); it2 != vt_dbl2.end(); ++it2)
        cout << *it2 << " ";

    rvec[0] = 100;

    for (auto it3 = vtdbl.begin(); it3 != vtdbl.end(); ++it3)
        cout << *it3 << " ";

    return 0;
}
