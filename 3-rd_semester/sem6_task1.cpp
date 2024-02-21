#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    
}
int main()
{
    int n = 0, k = 0;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        v[i] = k;
    }
    auto it = std::max_element(v.begin(), v.end());
    std::sort(v.begin(), it, [](int a, int b){return a < b;});
    std::sort(it, v.end(), [](int a, int b){return a > b;});
    print_vector(v);

}