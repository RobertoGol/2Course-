#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  
  enum unit{millimeter=1, centimeter, decimeter, meter, kilometer};
  
  int unit_input = 0;
  double logger;
  
  cout << "Введите длину: ";
  cin >> logger;
  
  cout << "Введите единицу измерения (1 - мм, 2 - см, 3 - дм, 4 - м, 5 - км):(по сотношению к километрам) ";
  cin >> unit_input;
    
  switch(unit_input){
    case 1:
      cout << "миллиметр: ";
      cout << logger * pow(10, -6) << endl;
      break;
    case 2:
      cout << "сантиметр: ";
      cout << logger * pow(10, -5) << endl;
      break;
    case 3:
      cout << "дециметр: ";
      cout << logger * pow(10, -4) << endl;
      break;
    case 4:
      cout << "метр: ";
      cout << logger * pow(10, -3) << endl;
      break;
    case 5:
      cout << "километр: ";
      cout << logger << endl;
      break;
  }
  
  return 0;
}
