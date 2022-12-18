//	Description: Implementation de la classe Room.
//	Fichier: Room.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#include "Room.hpp"

Room::Room(std::string name, std::string description):
	name_(name), description_(description)
{
}

void Room::display(std::ostream& o)
{
	o << "\n-- " << name_ << " --" << std::endl
		<< description_ << std::endl;

	// TODO: afficher items dans cette room (Reste a connecter quels items dans quels Rooms)
	// Item::displayItemsFoundInRoom();

	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o <<"\n" << value->name_ << " se trouve à la position: " << key;
	}

	// TODO: appeler methode display de Item
	// Item::displayItemsInInventory();
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