//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

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
	itemList_.push_back(std::make_shared<Item>("Un diamant bleue",  "Ce diamant brillant sert comme cle"));
	// Vestiaire
	itemList_.push_back(std::make_shared<Item>("Un manteau brun", "Ce manteau est plein de neige"));
	itemList_.push_back(std::make_shared<Item>("Une chaise antique", "Cette chaise est a l'envers"));
	itemList_.push_back(std::make_shared<Item>("Un misterieux tobogan", "Ce tobogan est mauve"));
	itemList_.push_back(std::make_shared<Item>("Un oreiller blanc", "Cet oreiller a une tache de sang"));
	itemList_.push_back(std::make_shared<Item>("Une boite de monopoly", "Cette boite est vide"));
	// Salle secrete
	itemList_.push_back(std::make_shared<Item>("Une carte dans une enveloppe", "Cette carte contient le secret de Poly"));
}

void Item::takeItem(std::string item)
{
	takenItemsList_.push_back(item);
}

void Item::useItem(std::string item)
{
	// TODO: implementer

}

// Cette methode aide a implementer les methodes des commandes look, use et take
bool Item::isInItemList(std::string word)
{
	/*for (auto& item : itemList_)
	{*/
	for (int i = 0; i < itemList_.size(); i++)
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
	return itemList_;
}

std::vector<std::shared_ptr<class Item>> Item::getItemsFoundInRoom(void)
{
	// TODO : comment connecter ceci a Room?
	return itemList_;
}

