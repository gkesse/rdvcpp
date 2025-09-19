class parallel_job
{
public:
    void operator()()
    {
        some_implementation(); // une certaine implémentation
    }
};

parallel_job job;
std::thread t(job);
std::thread t(std::move(job));
std::thread t(parallel_job());
std::thread t{parallel_job{}};
std::thread t((parallel_job()));