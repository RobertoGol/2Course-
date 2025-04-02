// лабораторная_7_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h> //получение языковой бибилиотеки
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");//функции для использования кириллицы в комментариях
	cout << "Привет" << endl;
	return 0;
}

