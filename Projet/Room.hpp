//	Description: Definition de la classe Room.
//	Fichier: Room.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#pragma once
#include "Inclusion.hpp"
#include "Inventory.hpp"

class Room
{
public:
	Room(std::string name, std::string description_);
	Room(std::string name, std::string description_, std::shared_ptr<Item> item);
	void display(std::ostream& o);
	Room* getNorthNeighbour();
	Room* getSouthNeighbour();
	Room* getEastNeighbour();
	Room* getWestNeighbour();
	void addItemToRoomList(std::shared_ptr<Item> item);
	std::vector<std::shared_ptr<class Item>> getItemsInRoomList(void);
	void setNeighbour(Room* northNeighbour = nullptr,
		Room* southNeighbour = nullptr,
		Room* eastNeighbour = nullptr,
		Room* westNeighbour = nullptr);
	std::string getName(Room room);
	std::string getDescription(void);
private:
	std::string name_;
	std::string description_;
	std::vector<std::shared_ptr<Item>> itemsInRoom_;
	std::map<std::string, Room*> neighbour_;
};