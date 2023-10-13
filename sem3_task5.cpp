#include <iostream>
#include <string>
#include <algorithm>

int string_sum(std::string& a)
{
    size_t o = 0;
    int result = 0;
    a.erase(0, 1);
    auto i = std::count(a.begin(), a.end(), ',');
    if (i == 0)
    {
        return 0;
    }

    for (; i >= 0; i--)
    {
        size_t pos_commo = a.find(',');
        result += std::stoi(a.substr(0, pos_commo));
        a.erase(0, pos_commo + 2);
        o += pos_commo;
    }

    return result;
       
}
int main()
{
    std::string a = "[10, 20, 30, 40, 50]" ;
    std::cout << string_sum(a) << "\n";
}