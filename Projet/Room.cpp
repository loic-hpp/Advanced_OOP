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
			o <<"\n" << value->name_ << " se trouve � la position: " << key;
	}
}

Room* Room::getNorthneighbour()
{
	return neighbour_["Nord (N)"];
}

Room* Room::getSouthneighbour() 
{
	return neighbour_["Sud (S)"];
}

Room* Room::getEastneighbour() 
{
	return neighbour_["Est (E)"];
}

Room* Room::getWestneighbour() 
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
