template <class T>
T Accumulate(T a[], int count)
{
    T value = 0;
    for (int i = 0; i < count; ++i)
    {
        value += a[i];
    }
    return value;
}

int main()
{
    // Version générique du type SmartValue
    SmartValue<double> y[] = {10.0, 20.0, 30, 40};
    double res = Accumulate(y, 4);
    cout << res << endl;
}