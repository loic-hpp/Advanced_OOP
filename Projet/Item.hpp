//	Description: Definition de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include <string>
#include <vector>
#include <memory>

class Item
{
public:
	Item();
	Item(std::string name_, std::string description_);
	std::string getName(void);
	std::string getDescription(void);
	void takeItem(std::string word);
	void useItem(std::string word);
	void setIsUsed(bool boolean);
	bool getIsUsed(void);
	void setIsTaken(bool boolean);
	bool getIsTaken(void);
private:
	std::string name_;
	std::string description_;
	bool isUsed_ = false;
	bool isTaken_ = false;
};