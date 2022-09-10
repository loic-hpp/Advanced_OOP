#include <iostream>
#include <string>
#include <vector>
#define max(x,y) (((x) >= (y)) ? (x) : (y))
#define min(x,y) (((x) <= (y)) ? (x) : (y))
using namespace std;

int barrer(int a, int b) {//remplacer par 0 pour barrer
	if (a % 2 == 0 && b % 2 == 0)
		b = 0;
	return b;
}

int multiplication_russe(int a, int b) {
	int resultat=0, c; //resultat est le résultat de l'opération
	//c est une variable intermédiaire pour s'assurer que a est bien le min et b le max
	vector <int>valeurs_a, valeurs_b; //vecteurs dans lesquels seront stockés les itérations
	c = min(a, b);
	b = max(a, b);
	a = c;
	valeurs_a.push_back(a);//ajouter les valeurs initiales
	valeurs_b.push_back(b);
	while (a!=1)// tant qu'on est pas à un on divise et multiplie par 2
	{
		a = a / 2;
		b = b * 2;
		valeurs_a.push_back(a);
		valeurs_b.push_back(b);
	}
	int i = 0;
	for (int valeur : valeurs_a) {//barrer les valeurs à barrer dans b
		valeurs_b[i]=barrer(valeur, valeurs_b[i]);
		resultat += valeurs_b[i];
		i++;
	}
	return resultat;
}

struct test_mul
{
	int a, b, c;
	test_mul(int a1, int b1, int c1) : a(a1), b(b1), c(c1) //constructeur avec 3 paramètres
	{
	}
	test_mul(int a1,int b1)//constructeur avec 2 paramètres
	{
		a = a1; b = b1; c = multiplication_russe(a1,b1);
	}
};

int main() {
	int compteur_test=0;
	test_mul valeurs_obtenue[3] = { test_mul(10,5), test_mul(37,129), test_mul(17,7)};
	test_mul valeurs_attendues[3] = {test_mul(10,5,50), test_mul(37,129,4773), test_mul(17,7,119)};
	for (int i = 0; i < 3; i++) {
		if (valeurs_obtenue[i].c == valeurs_attendues[i].c)
			compteur_test++;
	}
	cout << compteur_test << "/3 tests passent" << endl;

	return 0;
}