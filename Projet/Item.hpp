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
	std::string getName(void);
	std::string getDescription(void);
	void displayItemsInInventory(std::ostream& o);
	void displayItemsFoundInRoom(std::ostream& o);
	void createItemsList(void);
	bool isItemInInvetory(std::string word);
	void takeItem(std::shared_ptr<class Item> item, std::string word);
	void useItem(std::shared_ptr<class Item> item, std::string word);
	/*std::vector<std::shared_ptr<class Item>> getItemsInInvetory(void);
	std::vector<std::shared_ptr<class Item>> getItemsFoundInRoom(void);*/
private:
	std::string name_;
	std::string description_;
	std::vector<std::shared_ptr<class Item>> totalItemList_;
	std::vector<std::shared_ptr<class Item>> itemsInInventory_;
};