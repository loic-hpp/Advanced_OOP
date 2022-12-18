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

std::string Item::getName(void)
{
	return name_;
}

std::string Item::getDescription()
{
	return description_;
}

bool Item::isKeyInInventory(void)
{
	/*if ()
	{
	
	}*/
	return false;
}

void Item::createItemsList(void)
{
	// Salle de reception
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

void Item::takeItem(std::shared_ptr<class Item> item, std::string word)
{
	if (isItemInInvetory(word))
	{
		itemsInInventory_.push_back(item);
	}
}

void Item::useItem(std::shared_ptr<class Item> item, std::string word)
{
	if (isItemInInvetory(word))
	{
		
	}
}

// Cette methode aide a implementer les methodes des commandes look, use et take
bool Item::isItemInInvetory(std::string word)
{
	/*for (auto& item : itemList_)
	{*/
	for (int i = 0; i < totalItemList_.size(); i++)
	{
		// Pourquoi appel de getName marche pas?
		/*if (itemList_.at(i).getName() == word)
		{
			return true;
		}*/
	}
	return false;
}

std::vector<std::shared_ptr<class Item>> Item::getTakenItemsList(void)
{
	// TODO : Regler ce retour ci
	return totalItemList_;
}

std::vector<std::shared_ptr<class Item>> Item::getItemsFoundInRoom(void)
{
	// TODO : comment connecter ceci a Room?
	return totalItemList_;
}

