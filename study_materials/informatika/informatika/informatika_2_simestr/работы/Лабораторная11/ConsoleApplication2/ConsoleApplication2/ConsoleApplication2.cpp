// ConsoleApplication2.cpp: определ€ет точку входа дл€ консольного приложени€.
//
//Number 5
#include "math.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
        int x = 4;
        int y = --x;
        int s = y - x++;
        x += 1;
        cout << x << " " << y << " " << s << endl;
   
    
}
/*ќтвет: 5 3 0 */

//Number 6
/*
log10(sin(fabs(sqrt(exp(X) Ц Y) + 1) Ц X) + 1) - в математическом виде
log^10(sin(|sqrt(exp(x)-y)+1 |-x )+1)

x=(log(tan(x),7)+5)/paw(exp(2x),1.0/3)
*/