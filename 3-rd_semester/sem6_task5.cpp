#include <iostream>
#include <string>

int main()
{
    std::string s = "123     456      78     ";
    //std::getline(std::cin, s);
    size_t j = s.length(); 
    
    int o = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        //o += 1;
        //std::cout << j;
        if (i == s.length())
        {
            std::cout << s << "qwer";
            return 0;
        }
             
        
        if (s[i] == ' ')
        {
            while (s[i] == s[j])
            {
                
                if (i == j)
                {
                    std::cout << s;
                    return 0;
                }
                
                //j--;
                while (s[j] != ' ')
                {
                    j--;
                }
                
            }
            std::swap(s[i], s[j++]);
            
            
        }
        
    }  
    std::cout << s;
      
}
