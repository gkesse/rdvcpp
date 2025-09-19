{
private:
    long double _fact;

public:
    Factorial() : _fact(1)
    {
    }
    void operator()(int number)
    {
        _fact = 1;
        for (int i = 1; i <= number; ++i)
        {
            _fact *= i;
        }
        std::cout
            << "The factorial of the number "
            << number
            << " is equal to "
            << _fact
            << std::endl;
    }
};

int main()
{
    Factorial fact;
    std::thread t1(fact, 10);
    t1.join();
}

void thread_proc(std::string msg);
std::thread t(thread_proc, "Hello World\n");

// le code client transmet une valeur de type const char*,
// tandis que le thread reçoit un objet de type std::string.

void thread_proc(std::string msg);
void func()
{
    char buf[512] = "Hello World\n";
    std::thread t(thread_proc, buf);
    t.detach();
}

// Il est théoriquement possible que la fonction func se termine
// avant que le tableau de caractères buf soit converti
// en objet de type std::string

std::thread t(thread_proc, std::string(buf));
