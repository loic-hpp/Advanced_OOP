//	Programme qui génère un chiffre entier au hazard et demande à l'usager 
//	d'entrer un nombre entier jusqu'à ce que le nombre généré est rentré.
//  Ce programme ne prend que des nombres entiers comme entré.
//	\file   Pb5.cpp
//	\author Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	\date	14 septembre 2022
//	Créé le 6 septembre 2022

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
		// Inspiré sur https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c/19696468#19696468
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
	srand(time(NULL)); // On utilise le temps actuel comme seed pour générer un chiffre aléatoire.
	const int nMin = 0;
	const int nMax = 1000;
	numRiddle("Entrez un nombre entier: ", nMin, nMax);
}