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
		<< description_;
	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o <<"\n" << value->name_ << " se trouve à la position: " << key;
	}
}

std::shared_ptr<class Room> Room::getNorthneighbour()
{
	return neighbour_["Nord (N)"];
}

std::shared_ptr<class Room> Room::getSouthneighbour() 
{
	return neighbour_["Sud (S)"];
}

std::shared_ptr<class Room> Room::getEastneighbour() 
{
	return neighbour_["Est (E)"];
}

std::shared_ptr<class Room> Room::getWestneighbour() 
{
	return neighbour_["Ouest (O)"];
}

void Room::setNeighbour(std::shared_ptr<class Room> northNeighbour, std::shared_ptr<class Room> southNeighbour, std::shared_ptr<class Room> eastNeighbour, std::shared_ptr<class Room> westNeighbour)
{
	neighbour_["Nord (N)"] = northNeighbour;
	neighbour_["Sud (S)"] = southNeighbour;
	neighbour_["Est (E)"] = eastNeighbour;
	neighbour_["Ouest (O)"] = westNeighbour;
}
