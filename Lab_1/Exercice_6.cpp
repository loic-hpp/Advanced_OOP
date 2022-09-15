#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
const int winningNumber = 3;
enum class Finality {EQUALITY, PLAYER1, PLAYER2};

vector <vector<char>> loadData(string fileName) {
	vector <vector<char>> datas;
	vector<char> lines;
	ifstream readFlux(fileName.c_str());
	char letter;
	if (readFlux) {
		while (readFlux.get(letter)) {
			//RFlux.get(lettre);
			if (letter != ' ')
				lines.push_back(letter);
			if (letter == '\n') {
				lines.pop_back();
				datas.push_back(lines);
				lines.clear();
			}
		}
		datas.push_back(lines);
	}
	else
		cout << "\n Veuillez mettre le fichier txt dans le même dossier que le cpp et reessayer";
	return datas;
}

Finality findWinner(vector <vector<char>> datas) {
	Finality winner = Finality::EQUALITY;
	int numberODiagonal = 0, numberXDiagonal = 0;
	int numberOAntiDiagonal = 0, numberXAntiDiagonal = 0;
	for (int i = 0; i < winningNumber ; i++) {
		int numberOVertical = 0, numberXVertical = 0;
		for (int j = 0; j < winningNumber ; j++) {
			int numberOHorizontal = 0, numberXHorizontal = 0;
			if (datas[i][j] == 'o')
				numberOVertical++;
			if (datas[i][j] == 'x')
				numberXVertical++;
			if (datas[j][i] == 'o')
				numberOHorizontal++;
			if (datas[j][i] == 'x')
				numberXHorizontal++;
			if (i==j){
				if (datas[i][j] == 'o')
					numberODiagonal++;
				if (datas[i][j] == 'x')
					numberXDiagonal++;
			}
			if (i+j==2) {// We are on the antidiagonal only when i+j=2
				if (datas[i][j] == 'o')
					numberOAntiDiagonal++;
				if (datas[i][j] == 'x')
					numberXAntiDiagonal++;
			}
			if (numberOVertical == winningNumber  or numberOHorizontal == winningNumber )
				winner = Finality::PLAYER2;
			if (numberXVertical == winningNumber  or numberXHorizontal == winningNumber )
				winner = Finality::PLAYER1;

		}
	}
	if (numberOAntiDiagonal == winningNumber  or numberODiagonal == winningNumber )
		winner = Finality::PLAYER2;
	if (numberXAntiDiagonal == winningNumber  or numberXDiagonal == winningNumber )
		winner = Finality::PLAYER2;
	return winner;
}

void printing(Finality winner) {
	switch (winner)
	{
	case Finality::EQUALITY:
		cout << "\nEgalite";
		break;
	case Finality::PLAYER1:
		cout << "\nLe joueur 1 gagne.";
		break;
	case Finality::PLAYER2:
		cout << "\nLe joueur 2 gagne." << endl;
		break;
	default:
		break;
	}

}

int main() {
	printing(findWinner(loadData("grille1.txt")));
	return 0;
}