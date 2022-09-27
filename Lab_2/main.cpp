﻿#include "Jeu.hpp"
#include <iostream>
#include <fstream>
#include <cstdint>
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include "gsl/span"
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.

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
	case enteteTailleVariableDeBase+0: return lireType<uint8_t>(fichier);
	case enteteTailleVariableDeBase+1: return lireType<uint16_t>(fichier);
	case enteteTailleVariableDeBase+2: return lireType<uint32_t>(fichier);
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

#pragma region "fonctions nécessaires écrites par nous"

ListeJeux ajouterJeuListeJeux(ListeJeux listeJeux, Jeu* jeuParamètre) {
	if (listeJeux.capacite == listeJeux.nElements) {
		ListeJeux nouvelleListeJeux = ListeJeux{};
		nouvelleListeJeux.capacite = (listeJeux.capacite + 1) * 2;
		nouvelleListeJeux.nElements = listeJeux.nElements + 1;
		nouvelleListeJeux.elements = new Jeu*[nouvelleListeJeux.capacite];
		int i = 0;
		for (Jeu* jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
			nouvelleListeJeux.elements[i] = jeu;
			i++;
		}
		nouvelleListeJeux.elements[i] = jeuParamètre;
		for (int j : iter::range((int)listeJeux.nElements)) {
			delete[] listeJeux.elements[j];
		}
		delete[] listeJeux.elements;
		listeJeux.elements = 0;
		return nouvelleListeJeux;
	}
	else{
		listeJeux.elements[listeJeux.nElements+1] = jeuParamètre;
		listeJeux.nElements++;
		return listeJeux;
	}
}

void supprimerJeuListeJeux(ListeJeux listeJeux, Jeu* jeuParametre) {
	int i = 0;
	for (Jeu* jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
		if (jeuParametre == jeu)
			break;
		i++;
	}
	for (int j : iter::range(i, (int)listeJeux.nElements)) {
		listeJeux.elements[j] = listeJeux.elements[j + 1];
	}
	listeJeux.nElements--;
}

//TODO: Fonction qui cherche un concepteur par son nom dans une ListeJeux.
// Cette fonction renvoie le pointeur vers le concepteur si elle le trouve dans
// un des jeux de la ListeJeux. En cas contraire, elle renvoie un pointeur nul.
Concepteur* trouverConcepteurJeu(Jeu* jeu, string nom) {
	for (Concepteur* concepteur : gsl::span(jeu->concepteurs.elements, jeu->concepteurs.nElements)) {
		if (concepteur->nom == nom)
			return concepteur;
	}
	return nullptr;
}

Concepteur* trouverConcepteurListeJeux(ListeJeux listeJeux, string nom) {
	for (Jeu* jeu : gsl::span(listeJeux.elements, listeJeux.nElements)) {
		if (trouverConcepteurJeu(jeu, nom) != nullptr)
			return trouverConcepteurJeu(jeu, nom);
	}
	return nullptr;
}

#pragma endregion


Concepteur* lireConcepteur(ListeJeux listeJeux , istream& fichier)
{
	Concepteur concepteur = {}; // On initialise une structure vide de type Concepteur.
	concepteur.nom = lireString(fichier);
	concepteur.anneeNaissance = int(lireUintTailleVariable(fichier));
	concepteur.pays = lireString(fichier);
	// Rendu ici, les champs précédents de la structure concepteur sont remplis
	// avec la bonne information.

	//TODO: Ajouter en mémoire le concepteur lu. Il faut revoyer le pointeur créé.
	// Attention, valider si le concepteur existe déjà avant de le créer, sinon
	// on va avoir des doublons car plusieurs jeux ont des concepteurs en commun
	// dans le fichier binaire. Pour ce faire, cette fonction aura besoin de
	// la liste de jeux principale en paramètre.
	// Afficher un message lorsque l'allocation du concepteur est réussie.
	cout << "\nLa lecture du concepteur: " << concepteur.nom << " est terminé" << endl;
	if (trouverConcepteurListeJeux(listeJeux, lireString(fichier)) == nullptr) {
		Concepteur* concepteurResultat = new Concepteur(concepteur);
		return concepteurResultat;
	}
	else
		return trouverConcepteurListeJeux(listeJeux, lireString(fichier)); //TODO: Retourner le pointeur vers le concepteur crée.
}

//TODO: Fonction qui change la taille du tableau de jeux de ListeJeux.
// Cette fonction doit recevoir en paramètre la nouvelle capacité du nouveau
// tableau. Il faut allouer un nouveau tableau assez grand, copier ce qu'il y
// avait dans l'ancien, et éliminer l'ancien trop petit. N'oubliez pas, on copie
// des pointeurs de jeux. Il n'y a donc aucune nouvelle allocation de jeu ici !

//TODO: Fonction pour ajouter un Jeu à ListeJeux.
// Le jeu existant déjà en mémoire, on veut uniquement ajouter le pointeur vers
// le jeu existant. De plus, en cas de saturation du tableau elements, cette
// fonction doit doubler la taille du tableau elements de ListeJeux.
// Utilisez la fonction pour changer la taille du tableau écrite plus haut.

//TODO: Fonction qui enlève un jeu de ListeJeux.
// Attention, ici il n'a pas de désallocation de mémoire. Elle enlève le
// pointeur de la ListeJeux, mais le jeu pointé existe encore en mémoire.
// Puisque l'ordre de la ListeJeux n'a pas être conservé, on peut remplacer le
// jeu à être retiré par celui présent en fin de liste et décrémenter la taille
// de celle-ci.

Jeu* lireJeu(istream& fichier)
{
	Jeu jeu = {}; // On initialise une structure vide de type Jeu
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = int(lireUintTailleVariable(fichier));
	jeu.developpeur = lireString(fichier);
	jeu.concepteurs = ListeConcepteurs{};
		//jeu.concepteurs = ListeConcepteurs();
	jeu.concepteurs.nElements = 0;
	jeu.concepteurs.capacite = lireUintTailleVariable(fichier);
			//jeu.concepteurs.capacite = jeu.concepteurs.nElements;
	jeu.concepteurs.elements = new Concepteur * [jeu.concepteurs.capacite];
	// Rendu ici, les champs précédents de la structure jeu sont remplis avec la
	// bonne information.

	//TODO: Ajouter en mémoire le jeu lu. Il faut revoyer le pointeur créé.
	// Attention, il faut aussi créer un tableau dynamique pour les concepteurs
	// que contient un jeu. Servez-vous de votre fonction d'ajout de jeu car la
	// liste de jeux participé est une ListeJeu. Afficher un message lorsque
	// l'allocation du jeu est réussie.
				//Concepteur* tempConcept = lireConcepteur(ListeJeux{}, fichier);

	for ([[maybe_unused]] size_t i : iter::range(jeu.concepteurs.capacite)) {
				//jeu.concepteurs.elements[i]->jeuxConcus.nElements = 0;
				//jeu.concepteurs.elements[i]->jeuxConcus.capacite = 0;
		jeu.concepteurs.elements[i] = new Concepteur{}; // LA CLÉ IL ME FAUT UN CONCEPTEUR
		//jeu.concepteurs.elements[i]->jeuxConcus = ListeJeux{};
		//jeu.concepteurs.elements[i]->jeuxConcus.nElements = 0;
		//jeu.concepteurs.elements[i]->jeuxConcus.capacite = 0;
		//jeu.concepteurs.elements[i]->jeuxConcus = ajouterJeuListeJeux(jeu.concepteurs.elements[i]->jeuxConcus, &jeu);



		ListeJeux lTest = ajouterJeuListeJeux(ListeJeux{}, &jeu);
		//Concepteur* cTest = lireConcepteur(jeu.concepteurs.elements[i]->jeuxConcus, fichier);

		jeu.concepteurs.elements[i] = lireConcepteur(lTest, fichier);
		lTest.elements[i]->concepteurs = jeu.concepteurs;
		jeu.concepteurs.elements[i]->jeuxConcus = lTest;
		jeu.concepteurs.nElements++;



		//PROBLÈME ICI
		//jeu.concepteurs.elements[i] = lireConcepteur(jeu.concepteurs.elements[i]->jeuxConcus ,fichier);  //TODO: Mettre le concepteur dans la liste des concepteur du jeu.

		//TODO: Ajouter le jeu à la liste des jeux auquel a participé le concepteur.

	}
	cout << "\nLa lecture du jeu: " << jeu.titre << " est terminé" << endl;
	Jeu* jeuResultat = new Jeu(jeu);
	return jeuResultat; //TODO: Retourner le pointeur vers le nouveau jeu.
}



ListeJeux creerListeJeux(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	size_t nElements = lireUintTailleVariable(fichier);
	ListeJeux listeJeux = {};
	listeJeux.capacite = 0;
	listeJeux.nElements = 0;
	for([[maybe_unused]] size_t n : iter::range(nElements))
	{
		listeJeux = ajouterJeuListeJeux(listeJeux, lireJeu(fichier)); //TODO: Ajouter le jeu à la ListeJeux.
	}

	return listeJeux; //TODO: Renvoyer la ListeJeux.
}

//TODO: Fonction pour détruire un concepteur (libération de mémoire allouée).
// Lorsqu'on détruit un concepteur, on affiche son nom pour fins de débogage.
void supprimerConcepteur(Concepteur* concepteur) {
	cout << "\nLa destruction de: " << concepteur->nom << " est terminée" << endl;
	delete concepteur;
	concepteur = 0;
}

//TODO: Fonction qui détermine si un concepteur participe encore à un jeu.
bool estParticipant(Jeu* jeu, Concepteur* concepteurParametre) {
	for (Concepteur* concepteur : gsl::span(jeu->concepteurs.elements, jeu->concepteurs.nElements)) {
		if (concepteur->nom == concepteurParametre->nom)
			return true;
	}
	return false;
}

//TODO: Fonction pour détruire un jeu (libération de mémoire allouée).
// Attention, ici il faut relâcher toute les cases mémoires occupées par un jeu.
// Par conséquent, il va falloir gérer le cas des concepteurs (un jeu contenant
// une ListeConcepteurs). On doit commencer par enlever le jeu à détruire des jeux
// qu'un concepteur a participé (jeuxConcus). Si le concepteur n'a plus de
// jeux présents dans sa liste de jeux participés, il faut le supprimer.  Pour
// fins de débogage, affichez le nom du jeu lors de sa destruction.

//TODO: Fonction pour détruire une ListeJeux et tous ses jeux.

void afficherConcepteur(const Concepteur& d)
{
	cout << "\t" << d.nom << ", " << d.anneeNaissance << ", " << d.pays
			  << endl;
}

//TODO: Fonction pour afficher les infos d'un jeu ainsi que ses concepteurs.
// Servez-vous de la fonction afficherConcepteur ci-dessus.

//TODO: Fonction pour afficher tous les jeux de ListeJeux, séparés par un ligne.
// Servez-vous de la fonction d'affichage d'un jeu crée ci-dessus. Votre ligne
// de séparation doit être différent de celle utilisée dans le main.


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion

	//int* fuite = new int;  // Pour vérifier que la détection de fuites fonctionne; un message devrait dire qu'il y a une fuite à cette ligne.

	ListeJeux listejeux = creerListeJeux("jeux.bin"); //TODO: Appeler correctement votre fonction de création de la liste de jeux.

	static const string ligneSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";
	cout << ligneSeparation << endl;
	cout << "Premier jeu de la liste :" << endl;
	//TODO: Afficher le premier jeu de la liste (en utilisant la fonction).  Devrait être Chrono Trigger.

	cout << ligneSeparation << endl;

	//TODO: Appel à votre fonction d'affichage de votre liste de jeux.
	
	//TODO: Faire les appels à toutes vos fonctions/méthodes pour voir qu'elles fonctionnent et avoir 0% de lignes non exécutées dans le programme (aucune ligne rouge dans la couverture de code; c'est normal que les lignes de "new" et "delete" soient jaunes).  Vous avez aussi le droit d'effacer les lignes du programmes qui ne sont pas exécutée, si finalement vous pensez qu'elle ne sont pas utiles.

	//TODO: Détruire tout avant de terminer le programme.  Devrait afficher "Aucune fuite detectee." a la sortie du programme; il affichera "Fuite detectee:" avec la liste des blocs, s'il manque des delete.
}
