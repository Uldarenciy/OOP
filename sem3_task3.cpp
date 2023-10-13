#include <iostream>
#include <string>
#include <string_view>

std::string operator*(std::string a, int n)
{
    std::string b {};
    for (size_t i = 0; i < n; i++)
    {
        b += a;
    }
    return b;
}

int main()
{
    std::string a = "Dog";
    std::cout << a * 5 << std::endl;
}