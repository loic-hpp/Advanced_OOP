#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

double limite(int precision) {
	int i = 0;
	vector <double> termes(1,1);
	do
	{
		termes.push_back(sqrt(2+termes[i]));
		i++;
	} while ((termes[i] - termes[i-1])>=pow(10,-1*precision));

	//la limite est Un+1 ie le 1er terme qui ne respecte pas la condition c'est donc le dernier terme de ma lsite
	return termes[i];
}

int main() {
	int precision;
	cout << "Veuillez entrer une précision:\t";
	cin >> precision;
	cout << "La limite de la suite avec une précision de: " << precision << " est: " << limite(precision) << endl;
	return 0;
}