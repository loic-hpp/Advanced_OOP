//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
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

std::vector<std::shared_ptr<Item>> Item::getInventoryList(void)
{
	return itemsInInventory_;
}

bool Item::IsInventoryEmpty()
{
	if (itemsInInventory_.empty())
	{
		return true;
	}
	return false;
}

void Item::displayItemsFoundInRoom(std::ostream& o)
{
	// TODO: connecter avec les differentes chambres
}

bool Item::isItemInInvetory(std::string command)
{
	for (int i = 0; i < totalItemList_.size(); i++)
	{
		std::string name = totalItemList_[i]->getName();
		if (name.contains(command.substr(4,command.size())) || 
			name.contains(command.substr(5, command.size())))
		{
			currentItemIndex_ = i;
			return true;
		}
	}
	return false;
}

void Item::addItemsToRooms()
{
	// TODO :
}

void Item::takeItem(std::string command)
{
	if (isItemInInvetory(command))
	{
		itemsInInventory_.push_back(totalItemList_[currentItemIndex_]);
	}
}

void Item::useItem(std::string command)
{
	if (isItemInInvetory(command))
	{
		// TODO: unlock room with tobogan ou diamant cle
	}
}

void Item::createItemsList(void)
{
	//Salle de reception
	totalItemList_.push_back(std::make_shared<Item>("Un diamant bleue",  "Ce diamant brillant sert comme cle"));
	// Vestiaire
	totalItemList_.push_back(std::make_shared<Item>("Un manteau brun", "Ce manteau est plein de neige"));
	totalItemList_.push_back(std::make_shared<Item>("Une chaise antique", "Cette chaise est a l'envers"));
	totalItemList_.push_back(std::make_shared<Item>("Un misterieux tobogan", "Ce tobogan est mauve"));
	totalItemList_.push_back(std::make_shared<Item>("Un oreiller blanc", "Cet oreiller a une tache de sang"));
	totalItemList_.push_back(std::make_shared<Item>("Une boite de monopoly", "Cette boite est vide"));
	// Salle secrete
	totalItemList_.push_back(std::make_shared<Item>("Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
}