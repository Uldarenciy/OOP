#include <iostream>
#include <vector>
#include <string>
#include <array>
using std::cout, std::endl, std::string;

template <typename T>
T GetMax(const std::vector<T>& v)
{
    T result {};

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > result)
            result = v[i];
            
    }
    return result;
}

int main()
{
    std::vector v {string("Cat"), string("Dog"), string("Mouse"), string("Lion")};
    std::vector a {10, 20, 30, 40, 50};
    std::vector<std::pair<int, int>> b = {{4, 7}, {5, 4}};
    std::cout << GetMax(b).first;
}