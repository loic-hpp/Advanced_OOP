//	Programme qui g�n�re un chiffre entier au hazard et demande � l'usager 
//	d'entrer un nombre entier jusqu'� ce que le nombre g�n�r� est rentr�.
//  Ce programme ne prend que des nombres entiers comme entr�.
//	\file   Pb5.cpp
//	\author Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	\date	14 septembre 2022
//	Cr�� le 6 septembre 2022

#include <iostream>
using namespace std;

void numRiddle(string text, double min, double max)
{
	int numTries = 0;
	int num = rand() % (int(max) + 1) + int(min);
	int guess = 0;
	double guessTemp = 0;

	while (guess != num)
	{
		cout << text;
		cin >> guessTemp;
		// Inspir� sur https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c/19696468#19696468
		while (cin.fail()) {	
			cin.clear();		
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Veuillez entrer un nombre entier: ";
			cin >> guessTemp;
		}
		guess = (int)guessTemp;
		cout << guess << endl;
		numTries++;
		if (guess < num)
		{
			cout << "Trop bas.\n";
		}
		else if (guess > num)
		{
			cout << "Trop haut.\n";
		}
	}

	if (num == guess)
	{
		cout << "Bravo!Vous avez reussi en " << numTries << " tentatives!";
	}
}

int main()
{
	srand(time(NULL)); // On utilise le temps actuel comme seed pour g�n�rer un chiffre al�atoire.
	const int nMin = 0;
	const int nMax = 1000;
	numRiddle("Entrez un nombre entier: ", nMin, nMax);
}