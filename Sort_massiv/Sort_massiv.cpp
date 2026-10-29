#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rand(1, 100);

	int random_num, num, temp;
	int mas[10];
	int choice = 0;
	int iter = 0;

	cout << "1.Ввести самому\n2.Заполнить массив случайными числами\nВаш выбор: ";
	cin >> choice;
	if (choice == 1 || choice == 2)
	{
		for (int i = 0;i < 10;i++)
		{
			if (choice == 1)
			{
				cout << "\nВводите элементы поочередно: ";
				cin >> num;
				mas[i] = num;
			}
			else if (choice == 2)
			{
				random_num = rand(gen);
				mas[i] = random_num;
			}
		}
		cout << "Массив до сортировки: ";
		for (int i = 0;i < 10;i++)
		{
			cout << mas[i] << ' ';
		}

		for (int i = 0;i < 9;i++)
		{
			for (int j = 0;j < 9-i;j++)
			{
				if (mas[j] > mas[j + 1])
				{
					temp = mas[j];
					mas[j] = mas[j + 1];
					mas[j + 1] = temp;		
					iter++;
				}
				

			}
		}
		cout << "\nИтераций: " << iter << "\nМассив после сортировки: ";
		for (int i = 0;i < 10;i++)
		{
			cout << mas[i] << ' ';
		}
	}
	else
		cout << "Вы ввели неверное значение";
	return 0;
}
