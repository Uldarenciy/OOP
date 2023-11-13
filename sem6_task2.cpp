#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<std::string>& v)
{
    for (auto it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
}

std::vector<std::string> reverse_vector(std::vector<std::string>& v)
{
    for (std::string& s: v)
        std::reverse(s.begin(), s.end());
    
    std::reverse(v.begin(), v.end());

    return v;
}
int main()
{
    std::vector<std::string> v = {"cat", "dog", "mouse", "elephant"};
    std::vector<std::string> b = {"a", "bc"};
    reverse_vector(v);
    print_vector(v);
    std::cout << std::endl;
    print_vector(reverse_vector(b));
}