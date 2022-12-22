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
	Item(std::string searchKey, std::string name_, std::string description_, bool isTakeable = true);
	std::string getName(void);
	std::string getDescription(void);
	void setIsUsed(bool boolean);
	bool getIsUsed(void);
	void setIsTaken(bool boolean);
	bool getIsTaken(void);
	bool getIsTakeable(void) {return isTakeable_;}
	std::string getSearchKey(void) { return searchKey_; }
	void display(std::ostream& o);
private:
	std::string name_;
	std::string description_;
	std::string searchKey_;
	bool isUsed_ = false;
	bool isTaken_ = false;
	bool isTakeable_ = true;
};