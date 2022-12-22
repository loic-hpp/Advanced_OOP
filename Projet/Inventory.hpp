//	Description: Definition de la classe Inventory.
//	Fichier: Inventory.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include "Item.hpp"

class Inventory
{
public:
	Inventory();
	std::vector<std::shared_ptr<Item>> getInventoryList(void);
	void addItemToInventoryList(Item item);
	bool IsInventoryEmpty(void);
	bool isItemInInvetory(std::string word);

private:
	std::vector<std::shared_ptr<class Item>> itemsInInventory_;
	int currentItemIndex_;
};