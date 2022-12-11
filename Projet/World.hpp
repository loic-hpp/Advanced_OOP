#pragma once
#include "Room.hpp"
class World
{
public:
	World();
	void display(std::ostream& o);
	void displayCurrentRoom(std::ostream& o);
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void look();
	void restart();
private:
	void createRoom();
	std::shared_ptr<class Room> currentRoom_;
	std::shared_ptr<class Room> beginRoom_;
	std::vector<std::shared_ptr<class Room>> rommList_;
	std::string name_;
	std::string header_;

};



