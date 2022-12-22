//	Description: Implementation de la classe Inventory.
//	Fichier: Inventory.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Inventory.hpp"

Inventory::Inventory()
{
	createTotalItemsList();
}

void Inventory::addItemToInventoryList(Item item)
{
	itemsInInventory_.push_back(std::make_shared<Item>(item));
}

std::vector<std::shared_ptr<class Item>> Inventory::getInventoryList(void)
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

void Inventory::createTotalItemsList(void)
{
	totalItemsList_.push_back(std::make_shared<Item>("Un diamant bleue", "Ce diamant brillant sert comme cle"));
	totalItemsList_.push_back(std::make_shared<Item>("Un manteau brun", "Ce manteau est plein de neige"));
	totalItemsList_.push_back(std::make_shared<Item>("Une chaise antique", "Cette chaise est a l'envers"));
	totalItemsList_.push_back(std::make_shared<Item>("Un misterieux tobogan", "Ce tobogan est mauve"));
	totalItemsList_.push_back(std::make_shared<Item>("Un oreiller blanc", "Cet oreiller a une tache de sang"));
	totalItemsList_.push_back(std::make_shared<Item>("Une boite de monopoly", "Cette boite est vide"));
	totalItemsList_.push_back(std::make_shared<Item>("Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
}

std::vector<std::shared_ptr<class Item>> Inventory::getTotalItemslist(void)
{
	return totalItemsList_;
}

// TODO: Utiliser find avec vector que Loic disait
bool Inventory::isItemInInvetory(std::string command)
{
	for (int i = 0; i < totalItemsList_.size(); i++)
	{
		std::string name = totalItemsList_[i]->getName();
		if (name.contains(command.substr(4, command.size())) ||
			name.contains(command.substr(5, command.size())))
		{
			currentItemIndex_ = i;
			return true;
		}
	}
	return false;
}

int Inventory::getCurrentItemIndex(void)
{
	return currentItemIndex_;
}

//std::shared_ptr<class Item> Inventory::searchItemWithCommand(std::string command)
//{
//	
//	return ;
//}