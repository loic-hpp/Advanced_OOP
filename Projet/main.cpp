﻿// Exemple de mauvais code qui répond aux exigences fonctionnelles du livrable 1.
// Par Francois-R.Boyer@PolyMtl.ca .
// Le code est mauvais, il ne répond pas du tout aux critères de bonne conception.
// Il a été écrit en moins de 20 minutes (à partir du Projet VS/VSCode "vide" disponible sur Moodle), excluant les commentaires.
// Ça permet de voir que la fonctionnalité demandée est très simple, c'est la conception qui est importante.
// Les commentaires //? expliquent pourquoi c'est mauvais.

#pragma region "Bibliothèques"//{

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <gsl/span>
#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>

//#if __has_include("gtest/gtest.h")
//#include "gtest/gtest.h"
//#endif

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	// bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
}

using namespace std;
using namespace std::literals;
using namespace iter;
using namespace gsl;

#pragma endregion//}



int main(int argc, char* argv[])
{
	initialiserBibliothequeCours(argc, argv);

	//? Tout a été mis dans le main, aucun orienté-objet.
	cout << "Ceci est mon super jeu mal programmé.\n\n";

	//? Tout peux modifier ces variables (aucune encapsulation).
	int salle = 0;  //? Quelle valeur est quelle salle?
	string commande;
	bool look = true;  //? La logique pour fonctionnalité look n'est pas bien séparée/regroupée (voir les plusieurs modifications et utilisations de look partout dans le code).

	while (true) {
		switch (salle) {  //? Un gros switch/case, imaginez s'il y avait des centaines de salles...
		case 0:
			if (look) //? Aucune séparation de la logique par rapport au contenu du jeu.
				cout << "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n"
				"Couloir est au nord (N)\n"  //? Les textes des directions sont "hard-codées", on peut se tromper et il faut modifier plusieurs endroits pour ajouter un lien.
				"Salon est à l'est (E)\n";  //? Aussi comment on fait pour pouvoir ajouter des liens pendant le jeu (demandé au livrable 2)?
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'N': salle = 2; look = true; break;  //? On remet look = true dans chaque direction, c'est clairement de la duplication de code; la logique qui fait l'affichage lorsqu'on entre dans une salle devrait être à un seul endroit dans le code.
				case 'E': salle = 1; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		//? Clairement de la duplication de code dans chaque 'case'.
		case 1:
			if (look)
				cout << "Vous êtes dans le salon.\n"
				"Entrée est à l'ouest (W)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'W': salle = 0; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;  //? Imaginez si on voulair ajouter d'autres commandes...
			else cout << "Je ne sais pas ça\n";
			break;

		case 2:
			if (look)
				cout << "Vous êtes dans le couloir.\n"
				"Cuisine est au nord (N)\n"
				"Petite chambre est à l'ouest (W)\n"
				"Entrée est au sud (S)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'N': salle = 4; look = true; break;
				case 'W': salle = 3; look = true; break;
				case 'S': salle = 0; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		case 3:
			if (look)
				cout << "Vous êtes dans une petite chambre. La seule autre chose qu'elle a rien de spécial que d'être petite est d'avoir une échelle dans le coin.\n"
				"Couloir est à l'est (E)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'E': salle = 2; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "utiliser") {  //? Justement une autre commande avec du code qui dupliqué et que sera dupliqué encore plus loin.
				// Notez que l'utilisation d'objet n'est demandée que dans le livrable 2, même si cet exemple le fait.
				string quoi; getline(cin, quoi);
				//? Ne peut pas être un objet pris dans une autre 'case'.
				if (quoi == " échelle") {  //? Doit être le texte exacte avec l'espace (notez qu'il n'est pas nécessaire que vous supportiez les accents; ici, entree_utf8.cpp/.hpp est ajouté à la bibliothque_cours pour les supporter).
					salle = 5;
					look = true;
				}
				else
					cout << "Je ne sais pas ça\n";
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		case 4:
			if (look)
				cout << "Vous êtes dans la cuisine. Elle est très jaune 'beurre' comme la mode d'une certaine époque.\n"
				"Couloir est au sud (S)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'S': salle = 2; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		case 5:  // Notez que cet exemple a 6 cases mais le minimum pour le livrable 1 est d'en avoir 5.
			if (look)
				cout << "Vous êtes dans le grenier, il est sombre.\n"
				"Une échelle permet de descendre.\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				cout << "Ne peut pas aller là\n";
			}
			else if (commande == "utiliser") {
				string quoi; getline(cin, quoi);
				if (quoi == " échelle") {
					salle = 3;
					look = true;
				}
				else
					cout << "Je ne sais pas ça\n";
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;
		}
	}
}
