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

void Inventory::createTotalItemsList(void)
{
	totalItemsList_.push_back(std::make_shared<Item>("diamant", "Un diamant bleue", "Ce diamant brillant sert comme cle", true, true));
	totalItemsList_.push_back(std::make_shared<Item>("manteau", "Un manteau brun", "Ce manteau est plein de neige", false, true));
	totalItemsList_.push_back(std::make_shared<Item>("chaise", "Une chaise antique", "Cette chaise est a l'envers", false, true));
	totalItemsList_.push_back(std::make_shared<Item>("tobogan", "Un misterieux tobogan", "Ce tobogan est mauve", true, false));
	totalItemsList_.push_back(std::make_shared<Item>("oreiller", "Un oreiller blanc", "Cet oreiller a une tache de sang", false, true));
	totalItemsList_.push_back(std::make_shared<Item>("monopoly", "Une boite de monopoly", "Cette boite est vide", false, true));
	totalItemsList_.push_back(std::make_shared<Item>("carte", "Une carte dans une enveloppe", "Cette carte contient le secret de Poly", false, true));
}

std::vector<std::shared_ptr<class Item>> Inventory::getTotalItemslist(void)
{
	return totalItemsList_;
}

int Inventory::getCurrentItemIndex(void)
{
	return currentItemIndex_;
}

void Inventory::eraseItemInInventory(std::shared_ptr<Item> item)
{
	auto it = std::find(itemsInInventory_.begin(), itemsInInventory_.end(), item);
	if (it != itemsInInventory_.end())
		itemsInInventory_.erase(it);
}