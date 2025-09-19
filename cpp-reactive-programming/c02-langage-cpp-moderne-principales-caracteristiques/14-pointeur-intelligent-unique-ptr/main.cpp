#include <iostream>
#include <deque>
#include <memory>
using namespace std;

int main(int argc, char **argv)
{
    unique_ptr<deque<int>> dq(new deque<int>());
    dq->push_front(10);
    dq->dq->push_front(20);
    dq->push_back(23);
    dq->push_front(16);
    dq->push_back(41);

    auto dqiter = dq->begin();
    while (dqiter != dq->end())
    {
        cout << *dqiter << "\n";
        dqiter++;
    }

    return 0;
}