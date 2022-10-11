#pragma once
#include <iostream>
#include <string>
template <class T>
class Liste {
public:
	Liste(int nElements = 0, int capacite = 0){
		nElements_ = nElements;
		capacite_ = capacite;
		elements_ = std::make_unique<std::shared_ptr<T>[]>(capacite);
	}
	//~Liste(){}

	void afficher() {
		std::cout << "\nVoici la liste des éléments:\n" << std::endl;
		for (int i = 0; i < (int)nElements_; i++)
			elements_[i]->afficher();
	}

	void ajouterElement(std::shared_ptr<T> element) {
		if (!(this->estDansListe(element->getNom()))) {
			size_t index = nElements_;
			if (nElements_ == capacite_) {
				index = 0;
			this->changerTailleListe();
			}
			elements_[nElements_] = element;
			nElements_++;
		}
	}
	
	
	void retirerElement(std::shared_ptr<T> element) {
		for (int i = 0; i < nElements_; i++) {
			if (elements_[i]->getNom() == element->getNom())
				elements_[i] = move(elements_[nElements_ - 1]);
		}
		elements_[nElements_ - 1] = nullptr;
		nElements_--;
	}

	std::shared_ptr<T>& operator[] (int index) { return elements_[index]; }
	friend std::ostream& operator<< (std::ostream& o, const Liste& foo);

private:
	std::size_t nElements_, capacite_;
	std::unique_ptr<std::shared_ptr<T>[]> elements_;

	bool estDansListe(std::string nom) {
		bool estDansListe = false;
		for (int i = 0; i < (int)nElements_; i++) {
				if (elements_[i]->getNom() == nom)
					estDansListe = true;
		}
		return estDansListe;
	}

	void changerTailleListe() {
		if (capacite_ == 0)
			capacite_ = 1;
		else
			capacite_ *= 2;
		std::unique_ptr<std::shared_ptr<T>[]> nouveauxElements = std::make_unique<std::shared_ptr<T>[]>(capacite_);
		for (int i = 0; i < (int)nElements_; i++)
			nouveauxElements[i] = elements_[i];
		elements_ = move(nouveauxElements);
	}
};