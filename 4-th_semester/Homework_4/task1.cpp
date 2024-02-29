
#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>

class Mutex
{
private:
    std::atomic_flag checker = ATOMIC_FLAG_INIT;
public:
    void lock()
    {
        while (checker.test_and_set())
            ;
    }
    void unlock()
    {
        checker.clear();
    }
};

Mutex d;
int b = 0;
void func1()
{
    d.lock();

    for (int i = 0; i < 1'000'000; i += 2)
        b++;

    d.unlock();
}


using namespace std::chrono_literals;
using std::cout, std::endl;

//std::atomic<int> a = 0;
std::mutex m;
int a = 0;
void func()
{
    m.lock();

    for (int i = 0; i < 1'000'000; i += 2)
        a++;

    m.unlock();
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func1);

    t1.join();
    t2.join();
    cout << b << endl;
}