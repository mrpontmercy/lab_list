#include "list.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(0));
	cout << "\nЗадание 1\n";
	List S1;
	S1.AddToHead(1);
	S1.AddToTail(10);
	cout << "S1: ";
	S1.Print();

	cout << "\nЗадание 2\n";
	List S2(6);
	cout << "S2: " << S2 << endl;
	cout << "S2 max: " << S2.Max()->Key() << "\tS2 min: " << S2.Min()->Key() << endl;

	cout << "\nЗадание 3\n";
	cout << "Найти 2 элемент в S2: " << S2.FindPos(2)->Key() << endl;
	S2.Del(S2.FindPos(2));
	cout << "Удаление 2 элемента из S2: " << S2 << endl;

	cout << "\nЗадание 4\n";
	cout << "Поиск 6 элемента в S2: " << S2.FindPos(6) << endl;
	S2.DelTail();
	cout << "S2: " << S2;

	cout << "\nЗадание 5\n";
	List S3;
	S3 = S1;
	cout << "S3: " << S3;
	if (S1 == S2)
		cout << "S1 и S3 равны " << endl;
	if (S3.Inside(15))
		cout << "15 внутри S3 \n";
	else
		cout << "15 не внутри S3\n";

	cout << "\nЗадание 6\n";
	S3.DelHead();
	S3.Del(S3.FindKey(10));
	cout << S3;
	if (S3.Empty())
		cout << "S3 пустой\n";
	else
		cout << "S3 не пустой\n";

	cout << "\nЗадание 7\n";
	int m[6];
	for(auto i = 0; i < 6; i++)
		m[i] = rand() % 20;
	List S4(m, 6);
	cout << S4;
	if (S4.Inside(25))
		puts("25 внутри S4 ");
	else
		puts("25 не внутри S4");
	S4.AddAfter(25, S4.FindPos(3));
	cout << "Добавил 25 на 4 позицию в S4: " << S4;

	cout << "\nЗадание 8\n";
	List S5 = S2;
	cout << "S5: " << S5;
	if (S5.Inside(5))
	{
		S5.Del(S5.FindKey(5));
	}
	else
	{
		S5.AddToTail(4);
	}
	cout << "Изменненный S5: " << S5;


	cout << "\nЗадание 9\n";
	cin >> S5;
	cout << "S5: "; S5.Print();
	if (S5 != S4)
		puts("S5 и S4 не равны");
	else
		puts("S5 и S4 равны");

	cout << "\nЗадание 10\n";
	S5.AddToTail(S4);
	cout << "Измененный S5: " << S5;
	S5.AddToHead(S1);
	cout << "Измененный S5: " << S5 << endl << endl;
	return 0;
}
