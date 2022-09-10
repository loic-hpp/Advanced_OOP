#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector <vector<char>> lectureGrille(string fname) {
	vector <vector<char>> grilles;
	ifstream RFlux(fname.c_str());
	string ligne;
	while (getline(RFlux, ligne)) {
		// de https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
		std::string::iterator end_pos = remove(ligne.begin(), ligne.end(), ' ');
		ligne.erase(end_pos, ligne.end());
		grilles.push_back(vector<char> (ligne.begin(), ligne.end()));
	}
	RFlux.close();
	return grilles;
}
int gagnant(vector<vector<char>> grilles) {
	int gagnant = 0;
	if ((grilles[0][0] == 'x' and grilles[0][1] == 'x' and grilles[0][2] == 'x') or (grilles[0][0] == 'x' and grilles[1][0] == 'x' and grilles[2][0] == 'x')
		or (grilles[0][0] == 'x' and grilles[1][1] == 'x' and grilles[2][2] == 'x') or (grilles[0][2] == 'x' and grilles[1][1] == 'x' and grilles[2][0] == 'x')
		or (grilles[2][0] == 'x' and grilles[2][1] == 'x' and grilles[2][2] == 'x') or (grilles[0][2] == 'x' and grilles[1][2] == 'x' and grilles[2][2] == 'x')
		or (grilles[1][0] == 'x' and grilles[1][1] == 'x' and grilles[1][2] == 'x') or (grilles[0][1] == 'x' and grilles[1][1] == 'x' and grilles[2][1] == 'x'))
		gagnant = 1;
	else
		if ((grilles[0][0] == 'o' and grilles[0][1] == 'o' and grilles[0][2] == 'o') or (grilles[0][0] == 'o' and grilles[1][0] == 'o' and grilles[2][0] == 'o')
		or (grilles[0][0] == 'o' and grilles[1][1] == 'o' and grilles[2][2] == 'o') or (grilles[0][2] == 'o' and grilles[1][1] == 'o' and grilles[2][0] == 'o')
		or (grilles[2][0] == 'o' and grilles[2][1] == 'o' and grilles[2][2] == 'o') or (grilles[0][2] == 'o' and grilles[1][2] == 'o' and grilles[2][2] == 'o')
		or (grilles[1][0] == 'o' and grilles[1][1] == 'o' and grilles[1][2] == 'o') or (grilles[0][1] == 'o' and grilles[1][1] == 'o' and grilles[2][1] == 'o'))
			gagnant = 2;
	return gagnant;
}
void affichage(int vainceur) {
	if (vainceur == 0)
		cout << "\nEgalite";
	if (vainceur == 1)
		cout << "\nLe joueur 1 gagne.";
	if (vainceur == 2)
		cout << "\nLe joueur 2 gagne." << endl;

}
int main() {
	affichage(gagnant(lectureGrille("grille1.txt")));
	return 0;
}