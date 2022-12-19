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

std::vector<std::shared_ptr<Item>> Item::getItemsInRoomList(void)
{
	return itemsInCurrentRoom_;
}

std::vector<std::shared_ptr<Item>> Item::getTotalItemList(void)
{
	return totalItemList_;
}

void Item::clearItemsInRoomList()
{
	itemsInCurrentRoom_.clear();
}

bool Item::IsInventoryEmpty()
{
	if (itemsInInventory_.empty())
	{
		return true;
	}
	return false;
}

void Item::addItemToCurrentRoomList(std::string command)
{
	if (isItemInInvetory(command))
	{
		itemsInCurrentRoom_.push_back(totalItemList_[currentItemIndex_]);
	}
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

void Item::setIsUsed(bool boolean)
{
	isUsed_ = boolean;
}

bool Item::getIsUsed()
{
	return isUsed_;
}

// TODO : Ces deux methodes peuvent etre directement dans World
// mais te force a appeler getInventoryList() avec un vector locale aux fonctions
void Item::takeItem(std::string command)
{
	if (isItemInInvetory(command))
	{
		itemsInInventory_.push_back(totalItemList_[currentItemIndex_]);
	}
	// TODO : enlever items affiches dans la chambre pour seulement afficher dans inventaire (comme image example)
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
	// Balcon
	totalItemList_.push_back(std::make_shared<Item>("Une chaise antique", "Cette chaise est a l'envers"));
	// Salle de billard
	totalItemList_.push_back(std::make_shared<Item>("Un misterieux tobogan", "Ce tobogan est mauve"));
	// Chambre a coucher
	totalItemList_.push_back(std::make_shared<Item>("Un oreiller blanc", "Cet oreiller a une tache de sang"));
	// Grand couloir
	totalItemList_.push_back(std::make_shared<Item>("Une boite de monopoly", "Cette boite est vide"));
	// Salle secrete
	totalItemList_.push_back(std::make_shared<Item>("Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
}