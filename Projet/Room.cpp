//	Description: Implementation de la classe Room.
//	Fichier: Room.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#include "Room.hpp"

Room::Room(std::string name, std::string description) :
	name_(name), description_(description)
{
}

Room::Room(std::string name, std::string description, std::vector<std::shared_ptr<Item>> items) :
	name_(name), description_(description), items_(items)
{
}

// TODO: peut etre bouger cette methode dans vue pour pouvoir afficher 
// items dans la chambre presente ou c'est sense 
void Room::display(std::ostream& o)
{
	o << "\n-- " << name_ << " --" << std::endl
		<< description_ << std::endl;

	// Affichage ici supossement
	o << "\n" << "Tu remarques:" << std::endl;
	//std::vector<std::shared_ptr<Item>> itemsInCurrentRoom = item_.getItemsInRoomList();
	for (int i = 0; i <= items_.size(); i++)
	{
		if (items_.empty())
		{
			o << "\t" << "Rien dans cette chambre" << std::endl;
		}
		else
		{
			o << "\t" << items_[i]->getName() << std::endl;
		}
	}

	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o << "\n" << value->name_ << " se trouve à la position: " << key;
	}

	o << "\n" << "Tu as:" << std::endl;
	Item item = Item();
	std::vector<std::shared_ptr<Item>> inventory = item.getInventoryList();
	for (int i = 0; i <= inventory.size(); i++)
	{
		if (inventory.empty())
		{
			o << "\t" << "Rien dans ton inventaire" << std::endl;
		}
		else
		{
			o << "\t" << inventory[i]->getName() << std::endl;
		}
	}
}

void Room::addItem(Item item)
{
	items_.push_back(std::make_shared<Item>(item));
}

//std::vector<std::shared_ptr<Item>> Room::getItemsList()
//{
//}

std::vector<std::shared_ptr<Item>> Room::getItemsInRoomList(void)
{
	return items_;
}

Room* Room::getNorthNeighbour()
{
	return neighbour_["Nord (N)"];
}

Room* Room::getSouthNeighbour()
{
	return neighbour_["Sud (S)"];
}

Room* Room::getEastNeighbour()
{
	return neighbour_["Est (E)"];
}

Room* Room::getWestNeighbour()
{
	return neighbour_["Ouest (O)"];
}

void Room::setNeighbour(Room* northNeighbour, Room* southNeighbour, Room* eastNeighbour, Room* westNeighbour)
{
	neighbour_["Nord (N)"] = northNeighbour;
	neighbour_["Sud (S)"] = southNeighbour;
	neighbour_["Est (E)"] = eastNeighbour;
	neighbour_["Ouest (O)"] = westNeighbour;
}

std::string Room::getName(Room room)
{
	return room.name_;
}

std::string Room::getDescription(void)
{
	return description_;
}