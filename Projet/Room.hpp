#pragma once
#include "inclusion.hpp"
class Room
{
public:
	Room(std::string name, std::string description_);
	 void display(std::ostream& o);
	 Room* getNorthneighbour();
	 Room* getSouthneighbour();
	 Room* getEastneighbour();
	 Room* getWestneighbour();
	 void setNeighbour(Room* northNeighbour = nullptr,
		 Room* southNeighbour = nullptr,
		 Room* eastNeighbour = nullptr,
		 Room* westNeighbour = nullptr);
private:
	std::string name_;
	std::string description_;
	std::map<std::string, Room*> neighbour_;
};

