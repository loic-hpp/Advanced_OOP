//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena

#include <iostream>
#include <string>
using namespace std;

void getStringInfo(string text) {
	string tempWord = "";
	string shortestWord = "";
	string longestWord = "";

	double tempLen = 0;
	double sum = 0;
	double numOfWords = 0;

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

	double averageWordLength = sum / numOfWords; // print pas bon resultat???
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