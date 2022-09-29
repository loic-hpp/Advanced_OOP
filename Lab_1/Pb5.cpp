// Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
// Description ???
// 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void numRiddle(string text, double min, double max)
{
	int numTries = 0;
	double num = rand() % int(max) + int(min);
	double guess = 0;

	while (guess != num)
	{
		cout << text;
		cin >> guess;
		while (cin.fail()) {// Ici on veut détecter si ce n'est pas un entier qui est rentré.
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Veuillez entrer un nombre entier: ";
			cin >> guess;
		}
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
	numRiddle("Entrez un nombre entier: ", 0, 1001);
}