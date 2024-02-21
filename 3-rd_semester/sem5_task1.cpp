#include <iostream>
#include <list>

void Josephus(int n, int m)
{
    std::list<int> l;
    for (int i = 1; i <= n; i++)
    {
        l.push_back(i);   
    }
    
    std::list<int>::iterator it1 = l.begin();
    
    while (l.size() > 1)
    {
        for (int i = 1; i < m; i++)
        {
            it1++;

            if (it1 == l.end())
                it1 = l.begin();
            
            
        }
        
        std::cout << *it1 << " ";
        
        it1 = l.erase(it1);
        if (it1 == l.end())
            it1 = l.begin();
        
        
    }
    
    std::cout << std::endl << l.front();
    
}


int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    Josephus(n, m);   
}