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
	void displayItemsInInventory(std::ostream& o);
	void displayItemsFoundInRoom(std::ostream& o);
	void createItemsList(void);
	std::vector<std::shared_ptr<Item>> getInventoryList(void);
	void addItemsToRooms();
	bool isItemInInvetory(std::string word);
	void takeItem(std::string word);
	void useItem(std::string word);
private:
	std::string name_;
	std::string description_;
	int currentItemIndex_;
	std::vector<std::shared_ptr<class Item>> totalItemList_;
	std::vector<std::shared_ptr<class Item>> itemsInInventory_;
	std::vector<std::shared_ptr<class Item>> itemsInCurrentRoom_;
};