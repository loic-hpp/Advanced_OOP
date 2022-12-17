//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#include "Item.hpp"

Item::Item(std::string description):
	description_(description)
{
}

void Item::createVectorListItems(void)
{
	itemList_.push_back(std::make_shared<Item>("Un diamant bleue brillant qui sert comme cle"));
	itemList_.push_back(std::make_shared<Item>("Un manteau brun plein de neige"));
	itemList_.push_back(std::make_shared<Item>("Une chaise a l'envers"));
	itemList_.push_back(std::make_shared<Item>("Un misterieux tobogan mauve"));
	itemList_.push_back(std::make_shared<Item>("Une carte contenant le secret de Poly"));
	itemList_.push_back(std::make_shared<Item>("Un oreiller avec une tache de sang"));
	itemList_.push_back(std::make_shared<Item>("Une boite de monopoly vide"));
}

std::vector<Item> Item::getVectorListItems(void)
{
	// TODO : Regler ce retour ci
	/*return itemList_;*/
}

std::string Item::getDescription()
{
	return description_;
}