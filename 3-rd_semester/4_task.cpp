#include <iostream>
#include <cstring>

void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther)
{
    int i = 0;
    numLetters = 0, numDigits = 0, numOther = 0;
    int length = strlen(str);

    while (i < length)
    {
        if ((str[i] - '0' >= 0) && (str[i] - '0' <= 9))
        {
            numDigits += 1;
        }

        else if ((str[i] >= 65) && (str[i] <= 90))
        {
            numLetters += 1;
        }
        else
        {
            numOther += 1;
        }
        i++;
        
    }
    

}

int main()
{
    int numLetters1 = 0, numDigits1 = 0, numOther1 = 0;
    int& numLetters = numLetters1;
    int& numDigits = numDigits1;
    int& numOther = numOther1;
    const char* str = "A12345BCD'[A";
    
    //char* strp = str;
    //char* str1 = *str;
    countLetters(str, numLetters, numDigits, numOther);
    std::cout << "число букв - " << numLetters << "\nчисло цифр - " <<numDigits << "\nчисло других символов - " << numOther << "\n";


}