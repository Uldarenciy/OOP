#include <iostream>
#include <string>

int main()
{
    std::string a = {};
    std::cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        //std::cout << a[i] << " ";
        if (!((65 <= a[i] and a[i] <= 90) or a[i] == 32))
        {
            std::cout << "false";
            return 0;
        }      
    }
    std::cout << "true";

}