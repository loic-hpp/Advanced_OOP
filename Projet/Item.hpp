//	Description: Definition de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
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
	//void createItemsList(void);
	std::vector<std::shared_ptr<Item>> getInventoryList(void);
	std::vector<std::shared_ptr<Item>> getTotalItemList(void);
	bool IsInventoryEmpty();
	bool isItemInInvetory(std::string word);
	void takeItem(std::string word);
	void useItem(std::string word);
	void setIsUsed(bool boolean);
	bool getIsUsed();
private:
	std::string name_;
	std::string description_;
	int currentItemIndex_;
	bool isUsed_ = false;
	std::vector<std::shared_ptr<class Item>> totalItemList_;
	std::vector<std::shared_ptr<class Item>> itemsInInventory_;
};