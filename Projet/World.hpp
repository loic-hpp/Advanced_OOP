//	Description: Definition de la classe World.
//	Fichier: World.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#pragma once
#include "Room.hpp"

class World
{
public:
	World(std::string name, std::string header);
	void display(std::ostream& o);
	void displayCurrentRoom(std::ostream& o);
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void look(const std::vector<std::string>& command);
	void use(const std::vector<std::string>& command);
	void take(const std::vector<std::string>& command);
	void restart();
	std::shared_ptr<class Item> searchItemWithCommand(const std::vector<std::string>& command, std::vector<std::shared_ptr<class Item>> itemsInInventory);
	bool isPlaying() { return isRunning_; }
	void setPlaying(bool status);
private:
	void createRooms();
	void createSecretRoom(std::shared_ptr<Item> item);
	Room* currentRoom_;
	Room* beginRoom_;
	std::vector<std::shared_ptr<class Room>> roomList_;
	std::string name_;
	std::string header_;
	bool isRunning_ = true;
	Inventory inventoryInstance_ = Inventory();
	std::vector<std::shared_ptr<class Item>> totalItemsList_ = inventoryInstance_.getTotalItemslist();
};