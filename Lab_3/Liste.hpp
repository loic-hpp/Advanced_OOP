#pragma once
#include <iostream>
#include <string>
template <typename T>
class Liste {
public:
	Liste(int nElements = 0, int capacite = 0){
		nElements_ = nElements;
		capacite_ = capacite;
		elements_ = std::make_unique<std::shared_ptr<T>[]>(capacite);
	}

	Liste& operator=(const Liste& autreListe) {
		nElements_ = autreListe.nElements_;
		capacite_ = autreListe.capacite_;
		elements_ = std::make_unique<std::shared_ptr<T>[]>(capacite_);
		for (int i = 0; i < nElements_; i++) {
			//elements_[i] = std::make_shared<T>(*autreListe[i].get());
			elements_[i] = autreListe[i];
		}
		return *this;

	}

	Liste(const Liste& autreListe) {
		*this = autreListe;
	}

	/*Liste(const Liste& autreListe) {
		nElements_ = autreListe.nElements_;
		capacite_ = autreListe.capacite_;
		elements_ = std::make_unique<std::shared_ptr<T>[]>(capacite_);
		for (int i = 0; i < nElements_; i++) {
			elements_[i] = std::make_shared<T>(*autreListe[i].get());
		}
		return *this;

	}*/


	void afficher() {
		std::cout << "\nVoici la liste des éléments:\n" << std::endl;
		for (int i = 0; i < (int)nElements_; i++)
			elements_[i]->afficher();
	}

	void ajouterElement(std::shared_ptr<T> element) {
			if (nElements_ == capacite_)
				this->changerTailleListe();
			elements_[nElements_] = move(element);
			nElements_++;
	}

	template<typename F>
	int trouverElementQuelconque(const F fonction) {
		static const int indexe_pas_trouve = -1;
		for (int i = 0; i < nElements_; i++) {
			if (fonction(elements_[i]))
				return i;
		}
		return indexe_pas_trouve;
	}

	template<typename F>
	bool estDansListeElementQuelconque(const F fonction) {
		bool estDansListe = false;
		for (int i = 0; i < nElements_; i++) {
			if (fonction(elements_[i]))
				return true;
		}
		return estDansListe;
	}
	
	
	void retirerElement(std::shared_ptr<T> element) {
		for (int i = 0; i < nElements_; i++) {
			if (elements_[i]->getNom() == element->getNom())
				elements_[i] = elements_[nElements_ - 1];
		}
		elements_[nElements_ - 1] = nullptr;
		nElements_--;
	}

	std::shared_ptr<T>& operator[] (int index) { return elements_[index]; }
	const std::shared_ptr<T>& operator[] (int index) const { return elements_[index]; } 
	friend std::ostream& operator<< (std::ostream& o, const Liste& foo);

private:
	std::size_t nElements_, capacite_;
	std::unique_ptr<std::shared_ptr<T>[]> elements_;

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