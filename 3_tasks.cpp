#include <iostream>

namespace myspace
{
    void printNTimes(const char* str, int n = 10)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << str;
        }
    }

    int cube(int a)
    {
        return a*a*a;
    }

    int cubeR(int& a)
    
    {
        return a*a*a;
    }

}

int main()
{   
    myspace::printNTimes("123 ");
    
    int a = 4;
    int& p = a;
    std::cout << "\n" << myspace::cubeR(p);
    std::cout << "\n" << myspace::cube(a) << "\n";
}
    
   