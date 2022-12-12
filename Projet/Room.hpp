#pragma once
#include "inclusion.hpp"
class Room
{
public:
	Room(std::string name, std::string description_);
	 void display(std::ostream& o);
	 std::shared_ptr<class Room> getNorthneighbour();
	 std::shared_ptr<class Room> getSouthneighbour();
	 std::shared_ptr<class Room> getEastneighbour();
	 std::shared_ptr<class Room> getWestneighbour();
	 void setNeighbour(std::shared_ptr<class Room> northNeighbour = nullptr,
		 std::shared_ptr<class Room> southNeighbour = nullptr,
		 std::shared_ptr<class Room> eastNeighbour = nullptr,
		 std::shared_ptr<class Room> westNeighbour = nullptr);
private:
	std::string name_;
	std::string description_;
	std::map<std::string, std::shared_ptr<class Room>> neighbour_;
};
