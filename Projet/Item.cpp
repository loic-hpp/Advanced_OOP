//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Item.hpp"

Item::Item()
{
}

Item::Item(std::string name, std::string description):
	name_(name), description_(description)
{
}

std::string Item::getName(void)
{
	return name_;
}

std::string Item::getDescription()
{
	return description_;
}

void Item::setIsUsed(bool boolean)
{
	isUsed_ = boolean;
}

bool Item::getIsUsed()
{
	return isUsed_;
}

void Item::setIsTaken(bool boolean)
{
	isTaken_ = boolean;
}

bool Item::getIsTaken()
{
	return isTaken_;
}

// TODO : Ces deux methodes peuvent etre directement dans World
// mais te force a appeler getInventoryList() avec un vector local aux fonctions
// 
//void Item::takeItem(std::string command)
//{
//	if (isItemInInvetory(command))
//	{
//		itemsInInventory_.push_back(totalItemList_[currentItemIndex_]);
//	}
//	// TODO : enlever items affiches dans la chambre pour seulement afficher dans inventaire (comme image example)
//}
//
//void Item::useItem(std::string command)
//{
//	if (isItemInInvetory(command))
//	{
//		// TODO: unlock room with tobogan ou diamant cle
//	}
//}