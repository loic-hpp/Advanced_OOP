﻿//	Description: Nous avons créé en plus de ce qui a été demandé, une Liste<Concepteur> 
//	qui va contenir un pointeur vers tous nos concepteurs ceci dans le but de faciliter 
//	la recherche en effet on ne souhaite pas que le même concepteur soit créé 2 fois en 
//	mémoire et pour éviter de parcourir la liste de jeux ainsi que chaque jeu notre 
//	alternative est donc cette grande liste de concepteurs qui va contenir un pointeur 
//	vers tous les concepteurs.
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
#include "debogage_memoire.hpp"  
//NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si 
//vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
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

shared_ptr<Concepteur> lireConcepteur(istream& fichier, Liste<Concepteur>& listeConcepteur)
{
	Concepteur concepteur = {}; // On initialise une structure vide de type Concepteur.
	concepteur.nom = lireString(fichier);
	concepteur.anneeNaissance = int(lireUintTailleVariable(fichier));
	concepteur.pays = lireString(fichier);
	shared_ptr<Concepteur> ptrConcepteur = make_shared<Concepteur>(concepteur);

	if (!(listeConcepteur.estDansListeElementQuelconque([&](auto v) { return v->nom == concepteur.nom; })))
		listeConcepteur.ajouterElement(ptrConcepteur);
	else
		ptrConcepteur = listeConcepteur.trouverElementQuelconque([&](auto v)
			{ return v->nom == concepteur.nom; });

	cout << "\nLa lecture du concepteur: " << concepteur.nom << " est terminé" << endl;
	return ptrConcepteur; //TODO: Retourner le pointeur vers le concepteur crée.

}

shared_ptr<Jeu> lireJeu(istream& fichier, Liste<Concepteur>& listeConcepteur)
{
	Jeu jeu = {}; // On initialise une structure vide de type Jeu
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = int(lireUintTailleVariable(fichier));
	jeu.developpeur = lireString(fichier);
	size_t nElements = lireUintTailleVariable(fichier);

	jeu.concepteurs = Liste<Concepteur>();
	Liste<Concepteur> j1(jeu.concepteurs);
	
	shared_ptr<Jeu> nouveauJeu = make_shared<Jeu>(move(jeu));
	for ([[maybe_unused]] size_t i : iter::range(nElements)) {
		shared_ptr<Concepteur> ptrConcepteur = lireConcepteur(fichier, listeConcepteur);
		nouveauJeu->concepteurs.ajouterElement(ptrConcepteur);
	}

	return nouveauJeu; //TODO: Retourner le pointeur vers le nouveau jeu.
}

Liste<Jeu> creerListeJeux(const string& nomFichier, Liste<Concepteur>& listeConcepteur)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	size_t nElements = lireUintTailleVariable(fichier);
	Liste<Jeu> listeJeux = {};
	for ([[maybe_unused]] size_t n : iter::range(nElements))
	{
		listeJeux.ajouterElement(lireJeu(fichier, listeConcepteur));
	}

	return listeJeux; //TODO: Renvoyer la ListeJeux.
}

std::ostream& afficherConcepteur(std::ostream& o, const shared_ptr<Concepteur>& concepteur)
{
	return o << "\t" << concepteur->nom << ", " << 
		concepteur->anneeNaissance << ", " << concepteur->pays<< endl;
}

std::ostream& operator<< (std::ostream& o, const Liste<Concepteur>& listeConcepteur) {
	for (int i = 0; i < listeConcepteur.nElements_; i++)
		afficherConcepteur(o, listeConcepteur[i]);
	return o;
}

std::ostream& afficherJeu(std::ostream& o, const shared_ptr<Jeu>& jeu) {
	o << "\nInformations du jeu" << endl;
	o << "\n\t" << jeu->titre << "\t" << jeu->anneeSortie << "\n\nCONCEPTEURS\n" << endl;
	o << jeu->concepteurs;
	return o;
}

std::ostream& operator<< (std::ostream& o, const Liste<Jeu>& listeJeux) {
	for(int i = 0; i< listeJeux.nElements_; i++)
		afficherJeu(o, listeJeux[i]) 
		<< "\n_____________________________________________________\n" << std::endl;
	return o;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	Liste<Concepteur> listeConcepteurs = {};
	Liste<Jeu> listeJeux = creerListeJeux("jeux.bin", listeConcepteurs); 
	//TODO: Appeler correctement votre fonction de création de la liste de jeux.
	
	static const string ligneSeparation = 
		"\n\033[35m════════════════════════════════════════\033[0m\n";
	ofstream("sortie.txt") << listeJeux;
	cout << "\n____________________________________________________________________________\n";

	//Question 4 surcharge d'opérateurs[]
	cout << listeJeux[2]->titre << endl;
	cout << listeJeux[2]->concepteurs[1]->nom << endl;
	
	//Question 5 Fonction lambda
	std::shared_ptr<Concepteur> concepteur = 
		listeJeux[0]->trouverConcepteur([&](auto v)
			{ return v->nom == "Yoshinori Kitase"; });
	//Bon concepteur trouvé
	cout << "\t" << concepteur->nom << ", " << concepteur->anneeNaissance
		<< ", " << concepteur->pays << endl
		// Montrer que les 2 on la même adresse
		<< concepteur.get() << "--------------" << endl
		<< (listeJeux[1]->trouverConcepteur([&](auto v)
			{ return v->nom == "Yoshinori Kitase"; })).get() << "-------------" << endl;

	 // Question 7 copie
	 Jeu copieJeu = *(listeJeux[2].get());
	 copieJeu.concepteurs[2] = copieJeu.concepteurs[0];
	 cout << "\nInformations du jeu" << endl
		 << "\n\t" << listeJeux[2]->titre << "\t" 
		 << listeJeux[2]->anneeSortie << "\n\nCONCEPTEURS\n" << endl
		 << listeJeux[2]->concepteurs
		 << "\n____________________________________________________________________________\n"
		 << "\nInformations du jeu" << endl
		 << "\n\t" << copieJeu.titre << "\t" << copieJeu.anneeSortie 
		 << "\n\nCONCEPTEURS\n" << endl
		 << copieJeu.concepteurs << endl;
}
