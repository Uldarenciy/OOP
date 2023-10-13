#include <iostream>
#include <string>

int main()
{
    int* p = new int {123};
    std::string* a = new std::string {"Cats and Dogs"};
    int* b  = new int [5]{10, 20, 30, 40, 50}; 
    std::string* c  = new  std::string [3]{"Cat", "Dog", "Mouse"};
    std::string_view* d  = new  std::string_view [3]{c[0], c[1], c[2]};
    std::cout << *p << '\n' << *a << '\n' << b[0] << '\n' << c[2] << '\n' << d[1] << std::endl;

    
    delete[] c;
    delete[] d;
    delete[] b;
    delete p;
    //delete a;
    c[2] = "Elephant";
    std::cout << "after deletion " << *p << '\n' << *a << '\n' << b[0] << '\n' << c[2] << '\n' << d[1] << '\n';
    
}