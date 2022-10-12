//	Test de toutes les classes et structs implementés.
//	Fichier:  main.cpp
//	Auteurs partiels (seulement des TODOS): Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	2 octobre 2022
//	Créé le 26 septembre 2022

#include "Jeu.hpp"
#include <iostream>
#include <fstream>
#include <cstdint>
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include "gsl/span"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#include "Developpeur.hpp"
#include "ListeDeveloppeurs.hpp"
#include "Liste.hpp"

using namespace std;
using namespace iter;
using namespace gsl;

#pragma region "Fonctions de base pour vous aider"
template <typename T>
T lireType(istream& fichier)
{
	T valeur{};
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}
#define erreurFataleAssert(message) assert(false&&(message)),terminate()
static const uint8_t enteteTailleVariableDeBase = 0xA0;
size_t lireUintTailleVariable(istream& fichier)
{
	uint8_t entete = lireType<uint8_t>(fichier);
	switch (entete) {
	case enteteTailleVariableDeBase + 0: return lireType<uint8_t>(fichier);
	case enteteTailleVariableDeBase + 1: return lireType<uint16_t>(fichier);
	case enteteTailleVariableDeBase + 2: return lireType<uint32_t>(fichier);
	default:
		erreurFataleAssert("Tentative de lire un entier de taille variable alors que le fichier contient autre chose à cet emplacement.");
	}
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUintTailleVariable(fichier));
	fichier.read((char*)&texte[0], streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
gsl::span<Jeu*> spanListeJeux(const ListeJeux& liste)
{
	return gsl::span(liste.elements, liste.nElements);
}
gsl::span<Concepteur*> spanListeConcepteurs(const ListeConcepteurs& liste)
{
	return gsl::span(liste.elements, liste.nElements);
}
#pragma endregion

//TODO: Fonction qui cherche un concepteur par son nom dans une ListeJeux.
// Cette fonction renvoie le pointeur vers le concepteur si elle le trouve dans
// un des jeux de la ListeJeux. En cas contraire, elle renvoie un pointeur nul.
/*Concepteur* rechercherConcepteur(ListeJeux& listeJeux, string nom) {
	if (listeJeux.nElements == 0)
		return nullptr;
	else {
		for (Jeu*& jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
			for (Concepteur*& concepteur : gsl::span(jeu->concepteurs.elements, jeu->concepteurs.nElements)) {
				if (concepteur->nom == nom)
					return concepteur;
			}
		}
	}
	return nullptr;
}*/


shared_ptr<Concepteur> lireConcepteur(istream& fichier)
{
	Concepteur concepteur = {}; // On initialise une structure vide de type Concepteur.
	concepteur.nom = lireString(fichier);
	concepteur.anneeNaissance = int(lireUintTailleVariable(fichier));
	concepteur.pays = lireString(fichier);

	cout << "\nLa lecture du concepteur: " << concepteur.nom << " est terminé" << endl;
	return make_shared<Concepteur>(concepteur); //TODO: Retourner le pointeur vers le concepteur crée.

	//return nullptr;
}

//TODO: Fonction qui change la taille du tableau de jeux de ListeJeux.
// Cette fonction doit recevoir en paramètre la nouvelle capacité du nouveau
// tableau. Il faut allouer un nouveau tableau assez grand, copier ce qu'il y
// avait dans l'ancien, et éliminer l'ancien trop petit. N'oubliez pas, on copie
// des pointeurs de jeux. Il n'y a donc aucune nouvelle allocation de jeu ici !

shared_ptr<Jeu> lireJeu(istream& fichier)
{
	Jeu jeu = {}; // On initialise une structure vide de type Jeu
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = int(lireUintTailleVariable(fichier));
	jeu.developpeur = lireString(fichier);
	size_t nElements = lireUintTailleVariable(fichier);
	jeu.concepteurs = Liste<Concepteur>();
	
	

	shared_ptr<Jeu> nouveauJeu = make_shared<Jeu>(move(jeu));
	for ([[maybe_unused]] size_t i : iter::range(nElements)) {
		nouveauJeu->concepteurs.ajouterElement(lireConcepteur(fichier));
	
	}

	return nouveauJeu; //TODO: Retourner le pointeur vers le nouveau jeu.
	//return nullptr;
}

Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	size_t nElements = lireUintTailleVariable(fichier);
	Liste<Jeu> listeJeux = {};
	for ([[maybe_unused]] size_t n : iter::range(nElements))
	{
		listeJeux.ajouterElement(lireJeu(fichier));
	}

	return listeJeux; //TODO: Renvoyer la ListeJeux.
}




/*std::ostream& operator<< (std::ostream& o, const Liste<Jeu>& foo) {
	for(int i = 0; i<foo.nElements_; i++)
	return o << foo[i]->titre << "\n_____________________________________________________\n" << std::endl;
}*/

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	Liste<Jeu> listeJeux = creerListeJeux("jeux.bin"); //TODO: Appeler correctement votre fonction de création de la liste de jeux.

	static const string ligneSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";
	cout << ligneSeparation << endl;
	cout << "Premier jeu de la liste :" << endl;
	cout << ligneSeparation << endl;

	cout << "\n____________________________________________________________________________\n";
}
