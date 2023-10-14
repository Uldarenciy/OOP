#include <iostream>
#include <string>
#include "miptstring.hpp"

int main()
{
    mipt::String a = "Cat";
    mipt::String *b = new mipt::String {"Dog"};
    std::cout << a << "\n" << *b << "\n";
    delete b;
    char x[sizeof(mipt::String)]; //24
    mipt::String *c = new(x) mipt::String {"Elephant"};
    std::cout << *c << "\n";
    c->~String();
}