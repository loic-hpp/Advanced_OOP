#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include "Affichable.hpp"
#include "Personnage.hpp"
#include "Heros.hpp"
#include "Vilain.hpp"
#include "VilainHeros.hpp"

using namespace std;

ostream& operator<< (ostream& os, const Personnage& personnage) {
	personnage.afficher(os);
	return os;
}

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

void lireVilain() {
	ifstream fichier = ouvrirFichierBinaire("vilains.bin");
	size_t nElements = lireUintTailleVariable(fichier);
	vector <unique_ptr< Vilain >> listeVilain;
	for (size_t i = 0; i < nElements; i++)
		listeVilain.push_back(make_unique<Vilain>(Vilain(lireString(fichier),
			lireString(fichier), lireString(fichier))));

	for (size_t i = 0; i < nElements; i++) {
		cout << *listeVilain[i].get() << endl;
	}
}

void lireHeros() {
	ifstream fichier = ouvrirFichierBinaire("heros.bin");
	size_t nElements = lireUintTailleVariable(fichier);
	vector <unique_ptr< Heros >> listeHero;
	for (size_t i = 0; i < nElements; i++) {
		vector<string> alies;
		listeHero.push_back(make_unique<Heros>(Heros(lireString(fichier),
			lireString(fichier), lireString(fichier))));
		size_t nAlie = lireUintTailleVariable(fichier);
		for (size_t j = 0; j < nAlie; j++) {
			alies.push_back(lireString(fichier));
		}
		listeHero[i].get()->setListeAlie(alies);
	}

	for (size_t i = 0; i < nElements; i++) {
		cout << *listeHero[i].get() << endl;
	}
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	//lireVilain();
	lireHeros();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)

}
