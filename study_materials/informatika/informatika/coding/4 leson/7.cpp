#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  
  enum unit{millimeter=1, centimeter, decimeter, meter, kilometer};
  
  int unit_input = 0;
  double logger;
  
  cout << "������ �����: ";
  cin >> logger;
  
  cout << "������ ������� ����७�� (1 - ��, 2 - �, 3 - ��, 4 - �, 5 - ��):(�� �⭮襭�� � �������ࠬ) ";
  cin >> unit_input;
    
  switch(unit_input){
    case 1:
      cout << "���������: ";
      cout << logger * pow(10, -6) << endl;
      break;
    case 2:
      cout << "ᠭ⨬���: ";
      cout << logger * pow(10, -5) << endl;
      break;
    case 3:
      cout << "��樬���: ";
      cout << logger * pow(10, -4) << endl;
      break;
    case 4:
      cout << "����: ";
      cout << logger * pow(10, -3) << endl;
      break;
    case 5:
      cout << "��������: ";
      cout << logger << endl;
      break;
  }
  
  return 0;
}
