// zad 2 tema 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

struct SkiSustezatel {
	int number;
	string ime_familiq;
	double postijeniq;
	string durjava;
};

void Read(SkiSustezatel& b)
{
	cout << "Номер:";
	cin >> b.number;

	cout << "Име и фамилия:";
	cin >> b.ime_familiq;

	cout << "Постижения:";
	cin >> b.postijeniq;

	cout << "Държава: ";
	cin >> b.durjava;
};

void Print(SkiSustezatel& b)
{
	cout << "Номер:" << b.number << "\n" << "Име и фамилия:" << b.ime_familiq << "\n" << "Постижения" << b.postijeniq << "\n" << "Държава:" << b.durjava;
};

void sort(SkiSustezatel b[], int n) // по метода на мехурчето
{
	SkiSustezatel bb;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (b[j].postijeniq < b[j + 1].postijeniq ||
				(b[j].postijeniq == b[j + 1].postijeniq &&
					b[j].ime_familiq[0] > b[j + 1].ime_familiq[0]))
			{
				bb = b[j];
				b[j] = b[j + 1];
				b[j + 1] = bb;
			};

		}
	}
}

double AveragePostijeniq(SkiSustezatel b[], int n)
{
	double sum = 0;
	double average = 0;
	for (int i = 0; i < n; i++)
	{
		sum += b[i].postijeniq;
		if (n > 0)
		{
			average = sum / n;
		}
		else average = 0;
	}
	return average;
}

void spisukSustezateliSrPostijeniq(SkiSustezatel b[], int n, string& country)
{
	double avg = AveragePostijeniq(b, n);
	cout << "Средно постижение: " << avg << endl;
	bool found = false;
	cout << "Състезатели от" << " " << country << "с постижение по-ниско от средното:\n";
	for (int i = 0; i < n; i++)
	{
		if (b[i].durjava == country && b[i].postijeniq < avg)
		{
			cout << b[i].number << " " << b[i].ime_familiq << " "
				<< b[i].postijeniq << " " << b[i].durjava << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Няма такива състезатели.\n";
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n;
	cout << "Въведете брой състезатели: ";
	cin >> n;
	cin.ignore(); // премахваме остатъка от Enter-а в буфера

	SkiSustezatel b[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Състезател " << i + 1 << endl;

		cout << "Номер: ";
		cin >> b[i].number;
		cin.ignore(); // премахваме Enter-а след числото

		cout << "Име и фамилия: ";
		getline(cin, b[i].ime_familiq); // цял ред, включително интервали

		cout << "Постижение: ";
		cin >> b[i].postijeniq;
		cin.ignore(); // премахваме Enter-а

		cout << "Държава: ";
		getline(cin, b[i].durjava); // цял ред
	}

	// примерно извеждане
	for (int i = 0; i < n; i++)
	{
		cout << b[i].number << " " << b[i].ime_familiq << " "
			<< b[i].postijeniq << " " << b[i].durjava << endl;
	}


	string country;
	cout << "Въведете държава за филтър: ";
	cin >> country;

	spisukSustezateliSrPostijeniq(b, n, country);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
