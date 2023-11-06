#include <iostream>
#include <vector>
#include <span>

template <typename T>
void print_vector(const std::vector<T> &v)
{
    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';
}

int sumEven(const std::vector<int>& v)
{
    int result {};
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
            result += v[i];    
    }

    return result;
}

std::vector<int> lastDigits1(const std::vector<int>& v)
{
    std::vector<int> x = v;
    for (size_t i = 0; i < v.size(); i++)
    {
        x[i] = (v[i] % 10);
    }
    return x;
    
}

void lastDigits2(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = v[i] % 10;
    }
    
}

void lastDigits3(std::vector<int>* pv)
{
    for (size_t i = 0; i < (*pv).size(); i++)
    {
        (*pv)[i] = (*pv)[i] % 10;
    }
    
}

void lastDigits4(std::span<int> sp)
{
    for (size_t i = 0; i < sp.size(); i++)
    {
        sp[i] = sp[i] % 10;
    }
    
}

int main()
{
    std::vector<int> a = {41, 82, 163};
    print_vector(lastDigits1(a));
    std::vector<int>* pv = &a;
    //lastDigits3(pv);
    std::span<int> b = a;
    lastDigits4(b);
    std::cout << " " << b[0] << " " << b[1];
}