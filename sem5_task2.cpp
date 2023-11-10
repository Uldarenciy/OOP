#include <iostream>
#include <stack>

std::string PSP(std::string s)
{
    std::stack<char> c;
    for (char x: s)
    {
        if (x == ')')
        {
            if (c.empty())
                return "No";
            else if (c.top() == '(')
                c.pop();
            else
                return "No";
        }

        else if (x == ']')
        {
            if (c.empty())
                return "No";
            else if (c.top() == '[')
                c.pop();
            else
                return "No";
        }
        else if (x == '}')
        {
            if (c.empty())
                return "No";
            else if (c.top() == '{')
                c.pop();
            else
                return "No";
        }
        
        else 
        {
            c.emplace(x);
        }
    }
    
    if (c.empty())
        return "Yes";
    else
        return "No";

    
    
}
int main()
{
    std::string s1 = "(()())";
    std::string s2 = ")(";
    std::string s3 = "([{}])";
    

    std::cout << s1 << " " << PSP(s1) << std::endl;
    std::cout << s2 << " " << PSP(s2) << std::endl;
    std::cout << s3 << " " << PSP(s3) << std::endl;
    
}