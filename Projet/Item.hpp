//	Description: Definition de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Inclusion.hpp"
#include <vector>
#include <memory>

class Item
{
public:
	Item();
	Item(std::string searchKey, std::string name, std::string description, bool isUsable, bool isTakeable);
	std::string getName(void);
	std::string getDescription(void);
	void setIsUsed(bool boolean);
	bool getIsUsed(void);
	void setIsTaken(bool boolean);
	bool getIsTaken(void);
	std::string getSearchKey(void) { return searchKey_; }
	void setIsTakeable(bool boolean);
	bool getIsTakeable(void);
	void setIsUsable(bool boolean);
	bool getIsUsable(void);
	void display(std::ostream& o);
private:
	std::string name_;
	std::string description_;
	std::string searchKey_;
	bool isUsable_;
	bool isTakeable_;
	bool isUsed_ = false;
	bool isTaken_ = false;
};