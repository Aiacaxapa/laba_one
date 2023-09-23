// Тут только точки вызова. Сами задания в соответсвующих файлах

#include <iostream>
#include "taskOne.h"
#include "taskTwo.h"

int main()
{
    //Меняю кодировку
    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "rus");

    std::cout << "Задание 1\n";
    taskOne();
    std::cout << "Задание 2\n";
    taskTwo();
}