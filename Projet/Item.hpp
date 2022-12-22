//	Description: Definition de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include <string>
#include <vector>
#include <memory>

class Item
{
public:
	Item();
	Item(std::string searchKey, std::string name_, std::string description_);
	std::string getName(void);
	std::string getDescription(void);
	void setIsUsed(bool boolean);
	bool getIsUsed(void);
	void setIsTaken(bool boolean);
	bool getIsTaken(void);
	std::string getSearchKey(void) { return searchKey_; }
private:
	std::string name_;
	std::string description_;
	std::string searchKey_;
	bool isUsed_ = false;
	bool isTaken_ = false;
};