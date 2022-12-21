//	des classes Vilain, Hero et VilainHero dans un vecteur de personnages
//	Fichier:  main.cpp
//	Auteurs partiels (seulement des TODOS): Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 8 novembre 2022

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

const std::string TRAIT =
"═════════════════════════════════════════════════════════════════════════";
const std::string SEPARATION =
"-------------------------------------------------------------------------";

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

vector <unique_ptr< Vilain >> lireVilain() {
	ifstream fichier = ouvrirFichierBinaire("vilains.bin");
	size_t nElements = lireUintTailleVariable(fichier);
	vector <unique_ptr< Vilain >> listeVilain;
	string nom, parution, objectif;
	for (size_t i = 0; i < nElements; i++) {
		nom = lireString(fichier);
		parution = lireString(fichier);
		objectif = lireString(fichier);
		listeVilain.push_back(make_unique<Vilain>(Vilain(nom, parution, objectif)));
	}
	return listeVilain;
}

void afficherVilain(const vector<unique_ptr<Vilain>>& vilains) {
	for (size_t i = 0; i < vilains.size(); i++) {
		cout << *vilains[i].get() << endl << TRAIT << endl;
	}
}

vector <unique_ptr< Heros >> lireHeros() {
	ifstream fichier = ouvrirFichierBinaire("heros.bin");
	size_t nElements = lireUintTailleVariable(fichier);
	vector <unique_ptr< Heros >> listeHero;
	string nom, parution, ennemi;
	for (size_t i = 0; i < nElements; i++) {
		vector<string> alies;
		nom = lireString(fichier);
		parution = lireString(fichier);
		ennemi = lireString(fichier);
		listeHero.push_back(make_unique<Heros>(Heros(nom, parution, ennemi)));
		size_t nAlie = lireUintTailleVariable(fichier);
		for (size_t j = 0; j < nAlie; j++) {
			alies.push_back(lireString(fichier));
		}

		listeHero[i].get()->mettreListeAllies(alies);

	}
	return listeHero;
}

void afficherHero(const vector<unique_ptr<Heros>>& heros) {
	for (size_t i = 0; i < heros.size(); i++) {
		cout << *heros[i].get() << endl << TRAIT << endl;
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

	// CREATION DES INSTANCES
	vector <unique_ptr< Vilain >> listeVilain = lireVilain();
	vector <unique_ptr< Heros >> listeHero = lireHeros();
	VilainHeros vilainhero(*listeHero[0].get(), *listeVilain[2].get());

	// AFFICHAGE VILAINHERO SEUL
	cout << "AFFICHAGE VILAINHERO SEUL" << endl;
	cout << vilainhero;
	cout << endl << SEPARATION << endl;
	
	// AFFICHAGE VECTEUR DE VILAINS
	cout << endl << "AFFICHAGE VECTEUR DE VILAINS" << endl;
	afficherVilain(listeVilain);
	cout << endl << SEPARATION << endl;
	// AFFICHAGE VECTEUR DE HEROS
	cout << endl << "AFFICHAGE VECTEUR DE HEROS" << endl;
	afficherHero(listeHero);
	cout << endl << SEPARATION << endl;

	vector<Personnage*> listePersonnage;
	for (size_t i = 0; i < listeVilain.size(); i++)
		listePersonnage.push_back(listeVilain[i].get());
	for (size_t i = 0; i < listeHero.size(); i++)
		listePersonnage.push_back(listeHero[i].get());
	listePersonnage.push_back(&vilainhero);


	// AFFICHAGE POLYMORPHIQUE DES OBJETS DANS UN VECTEUR DE PERSONNAGES
	cout << "AFFICHAGE POLYMORPHIQUE DES OBJETS DANS UN VECTEUR DE PERSONNAGES"
		<< endl << "Vilain en rouge, Heros en bleu, VilainHero en mauve";
	for (size_t i = 0; i < listePersonnage.size(); i++)

		cout << *listePersonnage[i] << endl << TRAIT << endl;


}