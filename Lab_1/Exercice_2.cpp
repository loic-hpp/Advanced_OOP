/*
Programme qui retourne une approximation de la limite de la suite Un+1 = sqrt(2+Un)
avec une précision de epsilon
Fichier   Exercice_2.cpp
Auteurs Rodrigo A. Merino Martel et Loïc Nguemegne Temena
Date	14 septembre 2022
Créé le 6 septembre 2022
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double limit(int precision) {
	int i = 0;
	vector <double> datas(1,1);
	do
	{
		datas.push_back(sqrt(2+datas[i]));
		i++;
	} while ((datas[i] - datas[i-1])>=pow(10,-1*precision));
	
	// the limit is Un+1 it is the first term which does not respect the condition it is the last term of the list
	return datas[i];
}

int main() {

	int precision;
	cout << "Veuillez entrer une precision:\t";
	cin >> precision;
	cout << setprecision(precision) << "La limite de la suite avec une precision de: " << precision << " est: " << limit(precision)-99* pow(10, -1 * (precision+1)) << endl;
	return 0;
}