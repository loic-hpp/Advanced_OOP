// Exemple de mauvais code qui répond aux exigences fonctionnelles du livrable 1.
// Par Francois-R.Boyer@PolyMtl.ca .
// Le code est mauvais, il ne répond pas du tout aux critères de bonne conception.
// Il a été écrit en moins de 20 minutes (à partir du Projet VS/VSCode "vide" disponible sur Moodle), excluant les commentaires.
// Ça permet de voir que la fonctionnalité demandée est très simple, c'est la conception qui est importante.
// Les commentaires //? expliquent pourquoi c'est mauvais.

#pragma region "Bibliothèques"//{

#include "View.hpp"

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
	auto world = std::make_shared<World>("nom", "entête");
	auto controller = std::make_shared<Controller>(world);
	auto view = std::make_shared<View>(controller, world);
	do
	{
		view->playGame();

	} while (view->isPlaying());

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
