/*
    Задача:

        В данном примере написана функция getMax, которая находит максимум из чисел в векторе.
        При этом вычисления проходят однопоточно.


        Вам нужно написать функцию     

            uint64_t getMaxPar(int n, const std::vector<uint64_t>& v)

        которая будет делать то же самое, но только использовать для этого n потоков.
*/


#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdint>
using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;

uint64_t getMax(const std::vector<uint64_t>& v)
{
    uint64_t result = v.at(0);
    for (auto el : v)
    {
        if (el > result)
            result = el;
    }
    return result;
}

uint64_t getMax1(const std::vector<uint64_t>& v, uint64_t& result)
{
    result = getMax(v);
    return result;
}



uint64_t getMaxPar(int n, const std::vector<uint64_t>& v)
{
    std::vector<std::thread> threads;
    std::vector<uint64_t> results;
    std::vector<int> steps(n);
    uint64_t main_result;
    for (size_t i = 0; i < n - 1; i++)
        steps[i] = v.size() / (n - 1);
    steps[n - 1] = v.size() % (n - 1); 
    //cout << "steps[n] = " << steps[n] << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << steps[i] << endl;
    // }
    
    for (size_t i = 0; i < n; i++)
    {
        threads[i] = std::thread t(getMax1, v.begin() + steps.at(i), v.end() - (steps.size() - steps.at(i)), std::ref(result));
    }
    
    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
    std::thread Main_Result(getMax1, std::ref(results), std::ref(main_result));
    return 1; 
}

int main()
{
    cout << "Generating numbers!" << endl;
    std::vector<uint64_t> numbers(57);
    numbers[0] = 123456789;
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        numbers[i] = numbers[i - 1] * i + 1;
    }
    cout << "Numbers generated!" << endl;

    // auto start = std::chrono::high_resolution_clock::now();
    //uint64_t m = getMax(numbers);
    
    cout << "Maximum = " << endl;


    // auto end = std::chrono::high_resolution_clock::now();
    // cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    //      << " milliseconds." << endl;
    uint64_t result;
    std::thread t1(getMax1, std::ref(numbers), std::ref(result));
    t1.join();
    std::cout << result;

}