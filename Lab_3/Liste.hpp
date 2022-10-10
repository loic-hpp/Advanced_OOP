#pragma once
#include <iostream>
#include <string>
template <class T>
class Liste {
public:
	Liste(int nElements = 0, int capacite = 0){
		nElements_ = nElements;
		capacite_ = capacite;
		elements_ = std::unique_ptr<std::shared_ptr<T>[]>(new std::shared_ptr<T>[capacite]);
	}
	~Liste(){}

	void ajouterElement(std::shared_ptr<T> element) {
		
	}
	
	void afficher() {
		std::cout << "\nVoici la liste des éléments:\n" << std::endl;
		for (int i = 0; i < (int)nElements_; i++)
			elements_[i]->afficher();
	}
	
	void retirerElement(std::shared_ptr<T> element);

private:
	std::size_t nElements_, capacite_;
	std::unique_ptr<std::shared_ptr<T>[]> elements_;
	bool estDansListe(std::string nom);

	void changerTailleListe() {
		if (capacite_ == 0)
			capacite_ = 1;
		else
			capacite_ *= 2;
		std::unique_ptr<std::shared_ptr<T>[]> nouveauxElements(new std::shared_ptr<T>[capacite]);
		for (int i = 0; i < (int)nElements_; i++)
			nouveauxElements[i] = elements_[i];
		valeurs = move(nouveauxElements);
	}
};