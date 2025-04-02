#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int minNumber = 0;
    int maxNumber = 0;
    double sum = 0;

    cout << "Введите 5 целых чисел: ";
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
    cout << "Минимальное число: " << minNumber << endl;
    cout << "Максимальное число: " << maxNumber << endl;
    cout << "Среднее значение: " << average << endl;
    cout << "Введенные значения: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
