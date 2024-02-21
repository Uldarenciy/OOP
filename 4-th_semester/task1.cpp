#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>
#include <cstdint>
#include <utility>
using namespace std::chrono_literals;

void foo(int i)
{
    std::cout << "Thread #" << i << " started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(i));
    std::cout << "Thread #" << i << " finished" << std::endl;
}

int main()
{
    std::this_thread::sleep_for(1s);
    std::cout << "Waited for 1 second" << std::endl;
    
    std::this_thread::sleep_for(100ms);
    std::cout << "Waited for 100 millisecond" << std::endl;

    int n = 0;
    std::cin >> n;
    std::vector<std::thread> threads;
    int i = 0;
    while (i < n)
    {
        std::thread th(foo, std::ref(i));
        th.join();
        threads.push_back(std::move(th));
        i++;
    }
    
}