#include <iostream>
#include <cstring>

struct Book
{
    char title[100];
    int pages;
    float price;
};
void addPrice(Book& book1, float x)
{
    book1.price += x;
}

int main()
{
    Book book1;
    book1.pages = 100;

    const char* str = "Tom Cruse";
    strcpy(book1.title, str);

    book1.price = 12.5;
    addPrice(book1, 1.5);
    std::cout << book1.price << "\n" << book1.title << "\n" << book1.pages;
}