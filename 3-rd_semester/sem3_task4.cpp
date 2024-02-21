#include <iostream>
#include <string>

void truncateToDot(std::string& s)
{
    size_t position = s.find('.'); 
    s = s.substr(0, s.find('.'));
}

int main()
{
    std::string a = "wikipedia.org";
    truncateToDot(a);
    std::cout << a;
}