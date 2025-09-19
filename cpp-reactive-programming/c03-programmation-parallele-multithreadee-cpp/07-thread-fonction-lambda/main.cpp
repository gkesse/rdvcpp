int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(
            [i]()
            {
                std::cout << "Thread " << i << std::endl;
            }));
    }
    std::cout << "\nMain function" << std::endl;
    std::for_each(
        threads.begin(),
        threads.end(),
        [](std::thread &t)
        {
            t.join();
        });
    return 0;
}
