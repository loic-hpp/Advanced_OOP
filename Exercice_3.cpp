#include <iostream>
#include <string>
using namespace std;

void insertion(int nombre) {
	const int taille = 4;
	int index=taille;
	int donnees[taille]={1,3,4,5};
	int donnees_2[taille+1];
	for (int i = 0; i < taille; i++)
	{
		if (nombre < donnees[i]) {
			index = i;
			break;
		}
	}
		for (int i = taille - 1; i >= index; i--)
		{
			donnees_2[i + 1] = donnees[i];
		}
		for (int i = 0; i <= index; i++)
		{
			donnees_2[i] = donnees[i];
		}
		donnees_2[index] = nombre;
}

int main() {
	insertion(0);
	return 0;
}