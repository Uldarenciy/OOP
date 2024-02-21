#include <iostream>
#include <string>

std::string func(std::string& a)
{
    if (a.size() == 0)
    {   
        return a;
    }   
    else if (a[0] >= 97)
    {
        a[0] = toupper(a[0]);
    }
    else if (a[0] <= 90)
    {
        a[0] = tolower(a[0]);
    }
    return a;
}

int main()
{
    std::string a = "Cat";
    std::cout << "a = " << func(a) << " вот так!";
    std::cout << a[0];
}
