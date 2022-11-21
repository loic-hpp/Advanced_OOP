#include "Personnage.hpp"
#include "Heros.hpp"
#include "Vilain.hpp"
#include "VilainHeros.hpp"
#include "lireVectorDuFichier.hpp"
#include "lectureBinaire.hpp"
#include "ListeLiee.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <functional>
#include <memory>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include"ListeLiee.hpp"
#include <list>
#include <set>
#include <map>
using namespace std;
using namespace iter;

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


// versReferenceAffichable permet d'avoir une référence à l'affichable, que le paramètre soit un unique_ptr ou une référence.  On aurait pu faire un template plus générique pour const/non const, et même utiliser un concept, mais ce n'est pas nécessaire pour que ça fonctionne.
// lireFichier aurait aussi pu retourner un vector de unique_ptr pour ne pas avoir besoin de versReferenceAffichable pour supporter à la fois les références et les unique_ptr.
const Affichable& versReferenceAffichable(const Affichable& p) { return p; }
template <typename T>
const Affichable& versReferenceAffichable(const unique_ptr<T>& p) { return *p; }


// Trait de separation
static const string trait =
	"═════════════════════════════════════════════════════════════════════════";

// On ne demande pas particulièrement la surcharge de << dans ce TD.
template <typename T>
void afficherAffichables(const vector<T>& affichables)
{
	static const string separateurElements = "\033[33m" + trait + "\033[0m\n";
	for (auto&& a : affichables) {
		cout << separateurElements;
		auto& x = versReferenceAffichable(a);
		x.changerCouleur(cout, 0);
		x.afficher(cout);
	}
}

// Permet d'avoir une référence non-const à un objet temporaire.
template <typename T> T& temporaireModifiable(T&& objet) { return objet; }

template <typename T>
vector<T> lireVectorDuFichier(const string& nomFichier)
{
	return lireVectorDuFichier<T>(temporaireModifiable(ouvrirFichierBinaire(nomFichier)));
}

template <typename T>
ListeLiee<T>::iterator trouverParNom(ListeLiee<T>& liste, const string& nom)
{
	//? Quand on accède à un membre dans un type qui n'est pas encore connu (ici T n'est pas connu donc ListeLiee<T> n'est pas connu non plus) lors de l'analyse syntaxique du programme, dans le cas général il ne peut pas savoir si ce membre est un type.  Pour cette raison on doit ajouter le mot typename devant pour lui dire.
	typename ListeLiee<T>::iterator fin = liste.end();
	for (typename ListeLiee<T>::iterator pos = liste.begin(); pos != fin; pos.avancer()) {
		if ((*pos).getNom() == nom)
			return pos;
	}
	return fin;
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
	
	static const string separateurSections = "\033[95m" + trait + "\033[0m\n";

	//{ Solutionnaire du TD4:
	vector<Heros> heros = lireVectorDuFichier<Heros>("heros.bin");
	vector<Vilain> vilains = lireVectorDuFichier<Vilain>("vilains.bin");
	vector<unique_ptr<Personnage>> peronnages;  // Doit être des pointeurs pour le polymorphisme, l'énoncé ne force pas les unique_ptr.

	#if 0 //TODO: Vous n'avez pas à conserver ces affichages pour le TD5, ils sont pour le solutionnaire du TD4:
	cout << separateurSections << "Heros:" << endl;
	afficherAffichables(heros);

	cout << separateurSections << "Vilains:" << endl;
	afficherAffichables(vilains);

	for (auto& h : heros)
		peronnages.push_back(make_unique<Heros>(h));

	for (auto& v : vilains)
		peronnages.push_back(make_unique<Vilain>(v));

	peronnages.push_back(make_unique<VilainHeros>(vilains[1], heros[2]));

	cout << separateurSections << "Personnages:" << endl;
	afficherAffichables(peronnages);

	cout << separateurSections << "Un autre vilain heros (exemple de l'énoncé du TD), d'une autre couleur:" << endl;
	VilainHeros kefkaCrono(vilains[2], heros[0]);
	kefkaCrono.changerCouleur(cout,3);
	kefkaCrono.afficher(cout);
	
	for (int i : range(5)) { // Pour la couverture de code des couleurs (on aurait aussi pu éliminer le code pour les couleurs non utilisées).
		kefkaCrono.changerCouleur(cout,i);
		cout << "=";
	}
	#endif
	//}

	//TODO: Transférez les héros du vecteur heros dans une ListeLiee.
	ListeLiee<Heros> listeHeros;
	for (int i = 0; i < heros.size(); i++)
		listeHeros.push_back(heros[i]);

	//TODO: Créez un itérateur sur la liste liée à la position du héros Alucard.  Servez-vous de la fonction trouverParNom définie plus haut.
	ListeLiee<Heros>::iterator iterAlucard = trouverParNom(listeHeros, "Alucard");
	//TODO: Servez-vous de l'itérateur créé précédemment pour trouver l'héroine Aya Brea, en sachant qu'elle se trouve plus loin dans la liste, en itérant sur les éléments.
	ListeLiee<Heros>::iterator iterAya;
	for (ListeLiee<Heros>::iterator it = iterAlucard; it != listeHeros.end(); ++it) {
		if ((*it).getNom() == "Aya Brea") {
			iterAya = it;
			break;
		}
	}
	//TODO: Ajouter un hero bidon à la liste avant Aya Brea en vous servant de l'itérateur.
	listeHeros.insert(iterAya, Heros("Bidon", "Bidon", "Bidon"));
	//TODO: Assurez-vous que la taille de la liste est correcte après l'ajout.
	cout << "\nLanouvelle devrait être 10 et sa valeur est:\t"<<listeHeros.size() << endl;
	//TODO: Reculez votre itérateur jusqu'au héros Mario et effacez-le en utilisant l'itérateur, puis affichez le héros suivant dans la liste (devrait êter "Naked Snake/John").
	ListeLiee<Heros>::iterator iterMario = trouverParNom(listeHeros, "Mario");
	iterMario = listeHeros.erase(iterMario);
	cout << "\n" << (*iterMario).getNom() << endl;
	//TODO: Assurez-vous que la taille de la liste est correcte après le retrait.
	cout << "\nLanouvelle devrait être 9 et sa valeur est:\t" << listeHeros.size() << endl;
	cout << "\n";
	//TODO: Effacez le premier élément de la liste.
	listeHeros.erase(listeHeros.begin());

	//TODO: Affichez votre liste de héros en utilisant un itérateur. La liste débute avec le héros Randi, n'a pas Mario, et le précédent de "Aya Brea" est ce que vous avez inséré. Servez-vous des methodes begin et end de la liste...
	for (ListeLiee<Heros>::iterator it = listeHeros.begin(); it != listeHeros.end(); ++it) {
		(*it).afficher(cout);
		cout << "\n";
	}
	//TODO: Refaite le même affichage mais en utilisant une simple boucle "for" sur intervalle.
	cout << "\n" << trait << "\n";
	ListeLiee<Heros>::iterator it = listeHeros.begin();
	for (unsigned i = 0; i < listeHeros.size(); i++) {
		(*it).afficher(cout);
		cout << "\n";
		++it;
	}

	//TODO: Utilisez un conteneur pour avoir les héros en ordre alphabétique (voir point 2 de l'énoncé).
	struct MaComparaison {
		bool operator() (const Heros& h1, const Heros& h2) const
		{
			return h1.getNom() < h2.getNom();
		}
	};

	set<Heros, MaComparaison> ensembleHeros;
	for (int i = 0; i < heros.size(); i++)
		ensembleHeros.insert(heros[i]);

	cout << "\n" << trait << "\n";

	// 2-1) Retchercher un Heros dans mon set, pour cela, on besoin
	// passer un personnage à la fonction find de notre Set
	//Uniquement les nom sont comparés donc nous passons un héros bidon
	(ensembleHeros.find(Heros("Mario", "bidon", "bidon")))->afficher(cout);
	

// 2-2) La complexité moyenne de la recherche dans un ensemble trié est O(log(n)) lorsqu'on utilise la fonction find
// Car vu que l'ensemble est trié, l'ensemble utilise l'algorithme de dichotomie pour la recherche
// L'ensemble est divisé en plusieurs noeud et en partant d'une tête on suit un chemin pour retrouver l'élément 
// la recherche dans l'ensemble avec la méthode find n'itère pas sur tous les éléments
// ce n'est donc pas une complexité O(n) et ce n'est pas
// non plus une complexité O(1) par élimination, on conclut donc qu'il s'agit d'une 
// complexité O(log(n))
// 
// 2-3) C'est l'ensemble qui permet de faire une recherche plus rapide par nom
// Car l'ensemble est trié alors que la liste n'est pas triée et est non contigue donc la probabilité
// d'avoir a itérer plusieurs fois sur la liste pour retrouver le héros est plus grande
	//TODO: Assurez-vous de n'avoir aucune ligne non couverte dans les classes pour la liste liée.  Il peut y avoir des lignes non couvertes dans les personnages...
}
