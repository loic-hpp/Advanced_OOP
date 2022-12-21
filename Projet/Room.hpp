//	Description: Definition de la classe Room.
//	Fichier: Room.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#pragma once
#include "inclusion.hpp"
#include "Item.hpp"

class Room
{
public:
	Room(std::string name, std::string description_);
	Room(std::string name, std::string description_, std::vector<std::shared_ptr<Item>> items_);
	void display(std::ostream& o);
	Room* getNorthNeighbour();
	Room* getSouthNeighbour();
	Room* getEastNeighbour();
	Room* getWestNeighbour();
	void addItemToRoomList(Item item);
	std::vector<std::shared_ptr<Item>> getItemsInRoomList(void);
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
	//std::vector<std::shared_ptr<class Item>> itemsInCurrentRoom_;
};