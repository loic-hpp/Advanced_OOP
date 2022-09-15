//	Programme qui inspectionne un string et retourne le mot le plus petit,
//	le plus grand et la longueur moyenne des mots.
//	\file   Pb1.cpp
//	\author Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	\date	14 septembre 2022
//	Créé le 6 septembre 2022

#include <iostream>
#include <string>
using namespace std;

void getStringInfo(string text) {
	string tempWord = "";
	string shortestWord = "";
	string longestWord = "";

	double tempLen = 0.0;
	double sum = 0.0;
	double numOfWords = 0.0;

	for (int i = 0; i <= text.length(); i++)
	{
		if ((text[i] != ' ') && (i != text.length()))
		{
			tempWord += text[i];
			tempLen++;
		}
		else
		{
			sum += tempLen;
			tempLen = 0;
			numOfWords++;
			if (shortestWord.length() == 0)
			{
				shortestWord = tempWord;
			}
			else
			{
				if (tempWord.length() < shortestWord.length())
				{
				shortestWord = tempWord;
				}
				longestWord = tempWord;
			}
			tempWord = "";
		}
	}
	double averageWordLength = sum / numOfWords; 
	cout << "Le mot le plus court est : " << shortestWord;
	cout << "\nLe mot le plus long est : " << longestWord;
	cout << "\nLa longueur moyenne est : " << averageWordLength << " lettres";
}

int main()
{
	string text;
	cout << "Entrez une phrase quelconque: ";
	getline(cin, text);
	getStringInfo(text);
}