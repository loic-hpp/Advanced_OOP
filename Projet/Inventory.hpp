//	Description: Definition de la classe Inventory.
//	Fichier: Inventory.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Item.hpp"

class Inventory
{
public:
	Inventory();
	int getCurrentItemIndex(void);
	void addItemToInventoryList(Item item);
	void createTotalItemsList(void);
	std::vector<std::shared_ptr<class Item>> getInventoryList(void);
	std::vector<std::shared_ptr<class Item>> getTotalItemslist(void);
	std::shared_ptr<class Item> searchItemInInventoryWithCommand(const std::vector<std::string>& command);
	std::shared_ptr<class Item> searchItemInTotalListWithCommand(const std::vector<std::string>& command);
	void eraseItemInInventory(std::shared_ptr<Item> item);
private:
	std::vector<std::shared_ptr<class Item>> itemsInInventory_;
	std::vector<std::shared_ptr<class Item>> totalItemsList_;
	int currentItemIndex_;
};