//	Programme qui demande à l'usager un entier pour l'insérer dans une liste
//	en ordre croissant ordonée et qui ne prend que des entiers comme entrée.
//	\file   Pb3.cpp
//	\author Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	\date	14 septembre 2022
//	Créé le 6 septembre 2022

#include <iostream>
using namespace std;

void printList(int list[], int length)
	{
	for (int i = 0; i < length; i++)
	{
		if (list[i] > 0)
		{
			cout << list[i] << " "; 
		}
	}
}

void insertInOrderedList(int num)
{
	const int LENGTH = 100;
	int index = LENGTH;
	int tempValues[LENGTH] = { 1, 3, 4, 7, 9 };
	int orderedValues[LENGTH + 1];

	for (int i = 0; i < LENGTH; i++)
	{
		if (num < tempValues[i])
		{
			index = i;
			break;
		}
	}
	for (int i = LENGTH - 1; i >= index; i--)
	{
		orderedValues[i + 1] = tempValues[i];
	}
	for (int i = 0; i <= index; i++)
	{
		orderedValues[i] = tempValues[i];
	}
	orderedValues[index] = num;

	cout << "Le tableau avant insertion est: ";
	printList(tempValues, LENGTH);
	cout << "\nLe tableau après insertion est: ";
	printList(orderedValues, LENGTH);
}


int main()
{
	int num = 0;
	cout << "Entrez un nombre entier: ";
	cin >> num;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Veuillez entrer un nombre entier: ";
		cin >> num;
	}
	insertInOrderedList(num);

	return 0;
}