//----- FloatBuffer.cpp
#include <iostream>
#include <vector>
using namespace std;

class FloatBuffer
{
    double *bfr;
    int count;

public:
    FloatBuffer()
        : bfr(nullptr), count(0)
    {
    }

    FloatBuffer(int pcount)
        : bfr(new double[pcount]), count(pcount)
    {
    }

    FloatBuffer(const FloatBuffer &other)
        : count(other.count), bfr(new double[other.count])
    {
        std::copy(other.bfr, other.bfr + count, bfr);
    }

    FloatBuffer &operator=(const FloatBuffer &other)
    {
        if (this != &other)
        {
            delete[] bfr;
            count = other.count;
            bfr = new double[count];
            std::copy(other.bfr, other.bfr + count, bfr);
        }
        return *this;
    }

    FloatBuffer(FloatBuffer &&other)
        : bfr(nullptr), count(0)
    {
        cout << "Constructeur de déplacement" << endl;

        bfr = other.bfr;
        count = other.count;

        other.bfr = nullptr;
        other.count = 0;
    }

    FloatBuffer &operator=(FloatBuffer &&other)
    {
        if (this != &other)
        {
            delete[] bfr;
            bfr = other.bfr;
            count = other.count;
            other.bfr = nullptr;
            other.count = 0;
        }

        return *this;
    }
};

int main()
{
    vector<FloatBuffer> v;
    v.push_back(FloatBuffer(25));
    v.push_back(FloatBuffer(75));
    return 0;
}