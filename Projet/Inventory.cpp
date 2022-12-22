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
	totalItemsList_.push_back(std::make_shared<Item>("diamant", "Un diamant bleue", "Ce diamant brillant sert comme cle"));
	totalItemsList_.push_back(std::make_shared<Item>("manteau", "Un manteau brun", "Ce manteau est plein de neige"));
	totalItemsList_.push_back(std::make_shared<Item>("chaise", "Une chaise antique", "Cette chaise est a l'envers"));
	totalItemsList_.push_back(std::make_shared<Item>("tobogan", "Un misterieux tobogan", "Ce tobogan est mauve"));
	totalItemsList_.push_back(std::make_shared<Item>("oreiller", "Un oreiller blanc", "Cet oreiller a une tache de sang"));
	totalItemsList_.push_back(std::make_shared<Item>("monopoly", "Une boite de monopoly", "Cette boite est vide"));
	totalItemsList_.push_back(std::make_shared<Item>("carte", "Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
}

std::vector<std::shared_ptr<class Item>> Inventory::getTotalItemslist(void)
{
	return totalItemsList_;
}

int Inventory::getCurrentItemIndex(void)
{
	return currentItemIndex_;
}