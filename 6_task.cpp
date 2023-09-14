#include <iostream>
#include <cstring>

struct Book
{
    char title[100];
    int pages;
    float price;
};

bool isExpensive(const Book& p)
{
    if (p.price > 1000)
    {
        return true;
    }
    return false;
}

int main()
{
    Book book1;
    book1.pages = 100;

    const char* str = "Tom Cruse";
    strcpy(book1.title, str);

    book1.price = 1250;
    const Book& p = book1;
    std::cout << isExpensive(p) << "\n";

    
    std::cout << book1.price << "\n" << book1.title << "\n" << book1.pages;
}