// App1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double a = 1.5, b = -7.1;
	double x=0.3, y;
		
	do{
			y = b*pow(tan(x), 2)+ pow(log(a+pow(x,2)),2);
			cout << "X=" << x << '\t' << "Y=" << y << endl;
			x = x + 0.1;
		
	} while (x <= 1.0);
	return 0;
}

