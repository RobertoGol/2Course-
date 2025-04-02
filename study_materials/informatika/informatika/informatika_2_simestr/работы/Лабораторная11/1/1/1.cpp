// 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 3*10^-6;
	char b=0;
	double x;
	double z;

	cout << "Input b: ";
	cin >> b ;

	if (x < a / b) {
		z = sqrt(abs(a + exp(x)) + tan(x));
	}else{
		z = pow((x), 1.0 / 3)+(b^2)*pow(log(a+2),2);

	}
	cout << z << x << a;
	return 0;
}

