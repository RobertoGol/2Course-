#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int minNumber = 0;
    int maxNumber = 0;
    double sum = 0;

    cout << "������ 5 楫�� �ᥫ: ";
    for (int i = 0; i < 5; ++i)
    {
        cin >> numbers[i];

        sum += numbers[i];

        if (i == 0)
        {
            minNumber = maxNumber = numbers[0];
        }
        else
        {
            if (numbers[i] < minNumber)
            {
                minNumber = numbers[i];
            }
            if (numbers[i] > maxNumber)
            {
                maxNumber = numbers[i];
            }
        }
    }

    double average = sum / 5;
    cout << "�������쭮� �᫮: " << minNumber << endl;
    cout << "���ᨬ��쭮� �᫮: " << maxNumber << endl;
    cout << "�।��� ���祭��: " << average << endl;
    cout << "�������� ���祭��: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
