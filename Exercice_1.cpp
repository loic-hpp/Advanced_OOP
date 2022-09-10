#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define max(x,y) (((x) >= (y)) ? (x) : (y))
#define min(x,y) (((x) <= (y)) ? (x) : (y))
//inspiré de https://stackoverflow.com/questions/21338215/library-function-for-finding-the-larger-of-two-numbers
using namespace std;
void traitement_phrase(string phrase) {
	double moyenne;
	vector <int>données{100,0,0,0};
	string plus_long, plus_court;
	istringstream iss(phrase);
	// inspiré de https://www.geeksforgeeks.org/how-to-iterate-through-a-string-word-by-word-in-c/
	do {
		string mot;
		iss >> mot;
		if (mot != "") {
			if (données[0] > min(données[0], mot.length())) {
				données[0] = mot.length();
				plus_court = mot;
			}
			if (données[1] < max(données[1], mot.length())) {
				données[1] = mot.length();
				plus_long = mot;
			}
			données[3] += mot.length();
			données[2]++;
		}
	} while (iss);
	moyenne = double(données[3]) / double(données[2]);
	cout << "Le mot le plus court est : " << plus_court << "\nLe mot le plus long est : " << plus_long;
	cout << "\nLa longueur moyenne est : " << moyenne << endl;
}
int main() {
	string str = "je teste mon code";
	cout << "Entrer une phrase\t";
	getline(cin, str);
	cout << endl;
	traitement_phrase(str);
	return 0;
}