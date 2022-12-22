//	Description: Implementation de la classe Room.
//	Fichier: Room.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Room.hpp"

Room::Room(std::string name, std::string description) :
	name_(name), description_(description)
{
}

Room::Room(std::string name, std::string description, std::shared_ptr<Item> item) :
	name_(name), description_(description)
{
	addItemToRoomList(item);
}

void Room::display(std::ostream& o)
{
	o << "\n-- " << name_ << " --" << std::endl
		<< description_ << std::endl;

	o << "\n" << "Tu remarques:" << std::endl;
	if (itemsInRoom_.empty())
		o << "\t" << "Rien dans cette chambre" << std::endl;
	else {

		for (int i = 0; i < itemsInRoom_.size(); i++)
			o << "\t" << itemsInRoom_[i]->getName() << std::endl;
		}

	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o << "\n" << value->name_ << " se trouve à la position: " << key;
	}

}

// Besoin ?
void Room::addItemToRoomList(std::shared_ptr<Item> item)
{
	itemsInRoom_.push_back(item);
}

// TODO: besoin?
std::vector<std::shared_ptr<Item>> Room::getItemsInRoomList(void)
{
	return itemsInRoom_;
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

void Room::eraseItemInRoom(std::shared_ptr<Item> item) {
	auto it = std::find(itemsInRoom_.begin(), itemsInRoom_.end(), item);
	if(it != itemsInRoom_.end())
		itemsInRoom_.erase(it);
}