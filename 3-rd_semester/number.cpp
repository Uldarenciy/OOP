#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include <cstring>

/*
    Класс Number -- класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи

    Значение 100 для системы счисления выбрано как компромис между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9, 
    изменив при этом тип элементов c char на int

    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity

    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number 
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]
        
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }


    ~Number() 
    {
        delete [] data;
    }

    Number()
    {
        capacity = 1;
        size = capacity;
        data = new char[capacity];
        data[0] = 0;
    }

    Number (const Number& n)
    {
        this->capacity = n.capacity;
        this->size = n.size;
        this->data = new char[capacity];
         for (int i = 0; i < capacity; ++i) 
        {
            this->data[i] = n.data[i];
        }


    }

    Number (const char* str)
    {
        int str_length = strlen(str);
        if (str_length % 2 == 0)
        {
            this->capacity = str_length / 2;
        }
        else
        {
            this->capacity = str_length / 2 + 1;
        }
        
        
        this->data = new char[capacity];
        this->size = capacity;
        int j = 0;

        for (int i = str_length - 1; i >= 0; i -= 2)
        {
            if (i == 0)
            {
                data[j] = str[i] - '0';
                break;
            }

            data[j] = str[i] - '0' + (str[i - 1] - '0') * 10;
            j++;

        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};



std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}



int main() 
{
    Number x = 12345;
    Number y(x);
    Number a = Number("1234567");
    std::cout << x << " " << y << std::endl << a;
    

    
}