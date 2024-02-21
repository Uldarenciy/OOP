#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

void print_this(std::vector<std::pair<int, int>>& a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << "[ " << a[i].first << ", " << a[i].second << " ]";
    }
    
}
std::vector <std::pair<int, int>> factors (10);


std::vector<std::pair<int, int>> factorization(int n)
{
    if (n == 1)
    {
        factors.push_back(std::make_pair(1, 1));
        std::reverse(factors.begin(), factors.end());
        return factors;
    }
    for (int i = 2; i <= sqrt(n); i++) 
    {
    int o = 0;
    while (n % i==0) 
    {
        o += 1;
        n /= i;
    }
    if (o != 0)
        factors.push_back(std::make_pair(i, o));
        
}

    if (n != 1) 
    {
        
        factors.push_back(std::make_pair(n, 1));

    }
    std::reverse(factors.begin(), factors.end());
    return factors;
}

int main()
{
    std::vector<std::pair<int, int>> v {};
    
    v = factorization(626215995);
    print_this(v); //не нашел способа, как вектор пар вывести
}