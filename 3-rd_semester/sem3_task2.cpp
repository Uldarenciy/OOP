#include <iostream>
#include <string>
#include <string_view>

std::string repeat1(std::string_view s)
{
    std::string part1 = static_cast<std::string> (s);
    part1 += part1;
    return part1;
}

void repeat2(std::string& s)
{
    s+=s;
}

void repeat3(std::string* ps)
{
    *ps += *ps;
}

std::string* repeat4(std::string_view s)
{
    std::string part1 = static_cast<std::string> (s);
    part1 += part1;
    std::string* p = new std::string(part1);
    return p;
}

int main()
{
    std::string a = "Cat";
    std::string b = "Dog";
    std::string_view c = "Mouse";
    std::string* d = &a;
    std::string_view e = "Elephant";
    std::cout << *d << "\n";
    std::cout << repeat1(*d) << std::endl;
    repeat2(b);
    std::cout << b << std::endl;
    std::cout << repeat1(c) << std::endl;
    std::cout << repeat4(e) << std::endl;
}