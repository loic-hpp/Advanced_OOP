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
	Item(std::string name_, std::string description_);
	void createItemsList(void);
	void takeItem(std::string item);
	void useItem(std::string item);
	bool isInItemList(std::string word);
	std::vector<std::shared_ptr<class Item>> getTakenItemsList(void);
	std::vector<std::shared_ptr<class Item>> getItemsFoundInRoom(void);
	std::string getName(void);
	std::string getDescription(void);
	bool isKeyInInventory(void);

private:
	std::string name_;
	std::string description_;
	std::vector<std::shared_ptr<class Item>> itemList_;
	std::vector<std::string> takenItemsList_;
};