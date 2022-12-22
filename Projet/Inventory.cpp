//	Description: Implementation de la classe Inventory.
//	Fichier: Inventory.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Inventory.hpp"

Inventory::Inventory()
{
}

void Inventory::addItemToInventoryList(Item item)
{
	itemsInInventory_.push_back(std::make_shared<Item>(item));
}

std::vector<std::shared_ptr<Item>> Inventory::getInventoryList(void)
{
	return itemsInInventory_;
}

bool Inventory::IsInventoryEmpty()
{
	if (itemsInInventory_.empty())
	{
		return true;
	}
	return false;
}

// TODO: Crois qu'il a un bogue
bool Inventory::isItemInInvetory(std::string command)
{
	for (int i = 0; i < totalItemList_.size(); i++)
	{
		std::string name = totalItemList_[i]->getName();
		if (name.contains(command.substr(4, command.size())) ||
			name.contains(command.substr(5, command.size())))
		{
			currentItemIndex_ = i;
			return true;
		}
	}
	return false;
}