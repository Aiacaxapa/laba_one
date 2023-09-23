/*
�) ����� main() � ������������ �������� �� ������� � �������� ������������ � � �++ ���
��������� �������(������ ������������ ������������� ����� � ���� �������) :
	1) strlen - string::length
	2) strcpy - ��� ������� (����� a=b)
	3) strcmp - �� ����� �������
	4) strcat - someString.append
	5) someString[index] - someString.at(index)
	6) �� ����� ������� ������� (�������� ������������ strcat/ctrncat) - push_back
	7) �� ����� ������� - pop_back
	������� ����� �� ����� ������� ������� � ���������� ������� �����.������ ? � ��������� �������
	������� ����� � � � �++.

	������ � C - ������ ��������� char � null-������ � ���������
	������ � C++ - ������ ������ String � ������������ �������

	�) ������ �������� ��������� �� �++, ������� ����� ����������� ����� � ���������� ������� �
	�������� ������������� ������.������ ��������� ������ ������� ������� � ��������������
	�����.
	NB: ����������� ������ ���������� <string>.
*/	

#include "taskOne.h"
#include <string>


// ���� �� � printf
extern "C"
{
	int printf(const char* format, ...);
}
//��� ���������� �������, ������� ���� ������
const std::string notLetters = "( ) ` ~ ! @ # $ % ^ & * - + = | \\ { } [ ] : ; \" ' < > , . ? / _ � \n";

void taskOne() {
	char inputString[128]; 

	
	printf("������� ������:\n");
	fgets(inputString, _countof(inputString), stdin);

	//����������� ������ � � string
	std::string unfilteredString(inputString);

	//���������
	std::string filteredString = "";
	for (int i = 0; i < unfilteredString.length(); i++) {
		if (!letterOrNotLetter(unfilteredString.at(i))) {
			filteredString += unfilteredString.at(i);
		}
	}

	//��������� ��������������� ������
	std::string sortedString = sortString(filteredString);

	//������� 
	printf("��������������� ������:\n");
	printf(sortedString.c_str());
	printf("\n\n");
}

//����������, ����� �� ����������� ������
bool letterOrNotLetter(char testedChar) {
	//���������� ������ � ������ ��������� ������� notLetters
	for (int i = 0; i < notLetters.length(); i++) {
		if (testedChar == notLetters[i])
			return true;
	}
	return false;
}
//����������� ����������
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