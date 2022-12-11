#include "Room.hpp"

void Room::display(std::ostream& o)
{
	o << "-- " << name_ << " --" << std::endl
		<< description_ << std::endl;
	for (auto it = neighbour_.begin(); it != neighbour_.end(); ++it) {
		const auto& [key, value] = *it;
		if (value != nullptr)
			o << value->name_ << " se trouve à la position: " << key;
	}
}

std::shared_ptr<class Room> Room::getNorthneighbour()
{
	return neighbour_["North (N)"];
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
