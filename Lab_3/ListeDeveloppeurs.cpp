//	Implementation de la classe ListeDeveloppeurs.
//	Fichier:  ListeDeveloppeurs.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	2 octobre 2022
//	Créé le 26 septembre 2022

#include "ListeDeveloppeurs.hpp"

//NOTE: Le code sera principalement copié de certaines fonctions écrites pour la partie 1, mais mises dans une classe.
ListeDeveloppeurs::~ListeDeveloppeurs()
{
	delete[] elements_;
}

ListeDeveloppeurs::ListeDeveloppeurs(int nElements, int capacite, Developpeur** elements) : nElements_(nElements), capacite_(capacite), elements_(elements)
{
}

void ListeDeveloppeurs::afficher()
{
	std::cout << "\nVoici la liste des développeurs:\n" << std::endl;
	for (int i = 0; i < nElements_; i++) {
		elements_[i]->afficherDeveloppeur();
	}
}

bool ListeDeveloppeurs::estDansListeDeveloppeur(std::string nom) {
	bool estDansListe = false;
	for (int i = 0; i < nElements_; i++) {
		if (elements_[i]->nomDeveloppeur() == nom)
			estDansListe = true;
	}
	return estDansListe;
}

void ListeDeveloppeurs::ajouterDeveloppeur(Developpeur* developpeur)
{
	if (!(this->estDansListeDeveloppeur(developpeur->nomDeveloppeur()))) {
		size_t index = nElements_;
		if (nElements_ == capacite_) {
			if (capacite_ == 0)
				index = 0;
			this->changerTailleListeDeveloppeurs();
		}
		elements_[index] = developpeur;
		nElements_++;
	}
}

void ListeDeveloppeurs::changerTailleListeDeveloppeurs()
{
	if (capacite_ == 0)
		capacite_ = 1;
	else
		capacite_ *= 2;
	Developpeur** nouvelleListe = new Developpeur * [capacite_];
	for (int i = 0; i < nElements_; i++)
		nouvelleListe[i] = elements_[i];
	delete[] elements_;
	elements_ = nullptr;
	elements_ = nouvelleListe;
}

void ListeDeveloppeurs::retirerDeveloppeur(Developpeur* developpeurParametre)
{
	int i = 0;
	for (Developpeur*& developpeur : gsl::span(elements_, nElements_)) {
		if (developpeurParametre->nomDeveloppeur() == developpeur->nomDeveloppeur())
			elements_[i] = elements_[nElements_ - 1];
		i++;
	}
	elements_[nElements_ - 1] = nullptr;
	nElements_--;
}