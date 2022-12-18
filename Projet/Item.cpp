//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#include "Item.hpp"

Item::Item(std::string name, std::string description):
	name_(name), description_(description)
{
}

void Item::createVectorListItems(void)
{
	itemList_.push_back(std::make_shared<Item>("Un diamant bleue",  "Ce diamant brillant sert comme cle"));
	itemList_.push_back(std::make_shared<Item>("Un manteau brun", "Ce manteau est plein de neige"));
	itemList_.push_back(std::make_shared<Item>("Une chaise antique", "Cette chaise est a l'envers"));
	itemList_.push_back(std::make_shared<Item>("Un misterieux tobogan", "Ce tobogan est mauve"));
	itemList_.push_back(std::make_shared<Item>("Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
	itemList_.push_back(std::make_shared<Item>("Un oreiller blanc", "Cet oreiller a une tache de sang"));
	itemList_.push_back(std::make_shared<Item>("Une boite de monopoly", "Cette boite est vide"));
}

void Item::takeItem(std::string item)
{
	takenItemsList_.push_back(item);
}

void Item::useItem(std::string item)
{
	// TODO: implementer

}

std::vector<std::shared_ptr<class Item>> Item::getTakenItemsList(void)
{
	// TODO : Regler ce retour ci
	return itemList_;
}

std::vector<std::shared_ptr<class Item>> Item::getItemsFoundInRoom(void)
{
	// TODO : comment connecter ceci a Room?
	return itemList_;
}

std::string Item::getName(void)
{
	return name_;
}

std::string Item::getDescription()
{
	return description_;
}