#pragma once
#include "gsl/gsl_assert"
#include "gsl/pointers"

template<typename T> class ListeLiee;
template<typename T> class Iterateur;

template<typename T>
struct Noeud
{
	friend class ListeLiee<T>;
	friend class Iterateur<T>;
public:	
	//TODO: Constructeur(s)
	Noeud(const Noeud& autre) : 
		donnee_(autre.donnee_),
	suivant_(autre.suivant_),
	precedent_(autre.precedent_)
	{	
	}
	Noeud(const T& donnee = T()) {
		donnee_ = donnee;
		suivant_ = passeFin;
		precedent_ = passeFin;
	}

private:
	//TODO: Attributs d'un noeud
	T donnee_;
	Noeud* suivant_;
	Noeud* precedent_;
	inline static constexpr Noeud* passeFin = nullptr;
};

template<typename T>
class Iterateur
{
	friend class ListeLiee<T>;
public:
	//TODO: Constructeur(s).
	Iterateur(const Iterateur& autre) : position_(autre.position_){}
	Iterateur(Noeud<T>* position = Noeud<T>::passeFin): position_(position){}
	Iterateur& operator++ () {
		avancer();
		return *this;
	}

	Iterateur& operator-- () {
		avancer();
		return *this;
	}

	T& operator*()
	{
		return position_->donnee_;
	}
	//TODO: Ajouter ce qu'il manque pour que les boucles sur intervalles fonctionnent sur une ListeLiee.
	bool operator==(const Iterateur<T>& it) const = default;

	void avancer()
	{
		Expects(position_ != nullptr);
		//TODO: Changez la position de l'itérateur pour le noeud suivant
		position_ = position_->suivant_;
	}
	void reculer()
	{
		//NOTE: On ne demande pas de supporter de reculer à partir de l'itérateur end().
		Expects(position_ != nullptr);
		//TODO: Changez la position de l'itérateur pour le noeud précédent
		position_ = position_->precedent_;
	}

private:
	Noeud<T>* position_;
};

template<typename T>
class ListeLiee
{
	friend class Iterateur<T>;
public:
	using iterator = Iterateur<T>;  // Définit un alias au type, pour que ListeLiee<T>::iterator corresponde au type de son itérateur.

	//TODO: La construction par défaut doit créer une liste vide valide.
	ListeLiee() {
		tete_ = Noeud<T>::passeFin;
		queue_ = Noeud<T>::passeFin;
		taille_ = 0;
	}
	
	~ListeLiee()
	{
		//TODO: Enlever la tête à répétition jusqu'à ce qu'il ne reste aucun élément.
		// Pour enlever la tête, 
		// 1. La tête doit devenir le suivant de la tête actuelle.
		// 2. Ne pas oublier de désallouer le noeud de l'ancienne tête (si pas fait automatiquement).
		for (iterator it= begin(); it!=end(); ++it) {
		tete_ = it.position_;
		auto sauvegardeSuivant = tete_->suivant_;
		delete tete_;
		it.position_->suivant_ = sauvegardeSuivant;
		}
	}

	bool estVide() const  { return taille_ == 0; }
	unsigned size() const { return taille_; }
	//NOTE: to_address (C++20) permet que ce même code fonctionne que vous utilisiez des pointeurs bruts ou intelligents (ça prend le pointeur brut associé au pointeur intelligent, s'il est intelligent).
	iterator begin()  { return {to_address(tete_)}; }
	iterator end()    { return {to_address(queue_->suivant_)}; }

	// Ajoute à la fin de la liste.
	void push_back(const T& item)
	{
		//TODO: Vous devez créer un nouveau noeud en mémoire.
		//TODO: Si la liste était vide, ce nouveau noeud est la tête et la queue;
		// autrement, ajustez la queue et pointeur(s) adjacent(s) en conséquence.
		Noeud<T>* noeud = new Noeud<T>(item);
		if (estVide())
			tete_ = noeud;
		else {
			queue_->suivant_ = noeud;
			//queue_-­>suivant_ = noeud;
			noeud->precedent_ = queue_;
		}
		queue_ = noeud;
		taille_++;
	}

	// Insère avant la position de l'itérateur.
	iterator insert(iterator it, const T& item)
	{
		//NOTE: Pour simplifier, vous n'avez pas à supporter l'insertion à la fin (avant "past the end"),
		// ni l'insertion au début (avant la tête), dans cette méthode.
		//TODO:
		// 1. Créez un nouveau noeud initialisé avec item.
		// 2. Modifiez les attributs suivant_ et precedent_ du nouveau noeud
		//    afin que le nouveau noeud soit lié au noeud précédent et suivant
		//    à l'endroit où il est inséré selon notre itérateur.
		// 3. Modifiez l'attribut precedent_ du noeud après la position d'insertion
		//    (l'itérateur) afin qu'il pointe vers le noeud créé.
		// 4. Modifiez l'attribut suivant_ du noeud avant la position d'insertion
		//    (précédent de l'itérateur) afin qu'il point vers le noeud créé.
		// 5. Incrémentez la taille de la liste.
		// 6. Retournez un nouvel itérateur initialisé au nouveau noeud.
		if (it.position_ == Noeud<T>::passeFin) {
			push_back(item);
			return iterator(queue_);
		}
		else{
		Noeud<T>* apres = it.position_;
		Noeud<T>* avant = apres->precedent_;
		Noeud<T>* noeud = new Noeud<T>(item);
		noeud->suivant_ = apres;
		noeud->precedent_ = avant;
		apres->precedent_ = noeud;
		if (avant == Noeud<T>::passeFin)
			tete_ = noeud;
		else
			avant->suivant_ = noeud;
		taille_++;
		return iterator(noeud);
		}
	}

	// Enlève l'élément à la position it et retourne un itérateur vers le suivant.
	iterator erase(iterator it)
	{
		//TODO: Enlever l'élément à la position de l'itérateur.
		//  1. Le pointeur vers le Noeud à effacer est celui dans l'itérateur.
		//  2. Modifiez l'attribut suivant_ du noeud précédent pour que celui-ci
		//     pointe vers le noeud suivant la position de l'itérateur (voir 1.).
		//  3. Modifiez l'attribut precedent_ du noeud suivant la position de
		//     l'itérateur pour que celui-ci pointe vers le noeud précédent
		//     de la position de l'itérateur (voir 1.).
		//  4. Désallouez le Noeud à effacer (voir 1.).
		//  5. Décrémentez la taille de la liste
		//  6. Retournez un itérateur vers le suivant du Noeud effacé.
		//TODO: On veut supporter d'enlever le premier élément de la liste,
		//  donc en 2. il se peut qu'il n'y ait pas de précédent et alors c'est
		//  la tête de liste qu'il faut ajuster.
		//NOTE: On ne demande pas de supporter d'effacer le dernier élément (c'est similaire au cas pour enlever le premier).
		Noeud<T>* apres = it.position_->suivant_;
		Noeud<T>* avant = it.position_->precedent_;
		apres->precedent_ = avant;
		if (avant == Noeud<T>::passeFin)
			tete_ = apres;
		else
			avant->suivant_ = apres;
		gsl::owner<Noeud<T>*> proprietaire = it.position_;
		delete proprietaire;
		taille_--;
		return iterator(apres);
	}

private:
	gsl::owner<Noeud<T>*> tete_;  //NOTE: Vous pouvez changer le type si vous voulez.

	Noeud<T>* queue_;
	unsigned taille_;
};
