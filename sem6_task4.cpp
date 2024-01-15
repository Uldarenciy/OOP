#include <iostream>
#include <string_view>


bool isIdentifier(std::string_view s)
{
    if (!((65 <= s[0] and s[0] <= 90) or (97 <= s[0] and s[0] <= 122)))
    {
        std::cout << "false";
        return 0;
    }
    for (size_t i = 0; i != s.length(); i++)
    {
        if (!((65 <= s[i] and s[i] <= 90) or (97 <= s[i] and s[i] <= 122) or s[i] == 95 or 48 <= s[i] and s[i] <= 57))
        {
            std::cout << "false";
            return 0;
        }
        
    }

    std::cout << "true";
    return 1;
   
}

int main()
{
    

    std::string a = "my-name";
    std::cin >> a;
    isIdentifier(a);

    
}