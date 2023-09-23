/*
А) Перед main() в комментариях ответьте на вопросы и напишите соответствия С – С++ для
следующих функций(причем соответствия необязательно будут в виде функций) :
	1) strlen - string::length
	2) strcpy - нет аналога (пишем a=b)
	3) strcmp - не имеет аналога
	4) strcat - someString.append
	5) someString[index] - someString.at(index)
	6) не имеет точного аналога (возможно использовать strcat/ctrncat) - push_back
	7) не имеет аналога - pop_back
	Функции могут не иметь точного аналога в библиотеке другого языка.Почему ? – объясните главную
	разницу строк в С и С++.

	Строки в C - массив элементов char с null-байтом в окончании
	Строки в C++ - объект класса String с динамической памятью

	Б) Теперь напишите программу на С++, которая будет сортировать буквы в алфавитном порядке в
	веденной пользователем строке.Причем программа должна удалять пробелы и пунктуационные
	знаки.
	NB: Используйте только библиотеку <string>.
*/	

#include "taskOne.h"
#include <string>


// беру из С printf
extern "C"
{
	int printf(const char* format, ...);
}
//тут перечисляю символы, которые надо убрать
const std::string notLetters = "( ) ` ~ ! @ # $ % ^ & * - + = | \\ { } [ ] : ; \" ' < > , . ? / _ … \n";

void taskOne() {
	char inputString[128]; 

	
	printf("Введите строку:\n");
	fgets(inputString, _countof(inputString), stdin);

	//конвертирую строку С в string
	std::string unfilteredString(inputString);

	//фильтруем
	std::string filteredString = "";
	for (int i = 0; i < unfilteredString.length(); i++) {
		if (!letterOrNotLetter(unfilteredString.at(i))) {
			filteredString += unfilteredString.at(i);
		}
	}

	//сортируем отфильтрованную строку
	std::string sortedString = sortString(filteredString);

	//выводим 
	printf("Отсортированная строка:\n");
	printf(sortedString.c_str());
	printf("\n\n");
}

//Определяет, нужно ли фильтровать символ
bool letterOrNotLetter(char testedChar) {
	//Сравниваем символ с каждым элементов массива notLetters
	for (int i = 0; i < notLetters.length(); i++) {
		if (testedChar == notLetters[i])
			return true;
	}
	return false;
}
//Пузырьковая сортировка
std::string sortString(std::string s) {
	std::string sortedString = s;
	bool swapped;

	for (int i = 0; i < sortedString.length(); i++) {
		swapped = false;

		for (int j = 0; j < sortedString.length() - i - 1; j++) {
			if (sortedString.at(j) < sortedString.at(j + 1)) continue;

			char buf = sortedString.at(j);
			sortedString.at(j) = sortedString.at(j + 1);
			sortedString.at(j + 1) = buf;
			swapped = true;
		}
		if (!swapped) break;
	}

	return sortedString;
}