//	Description: Definition de la classe World.
//	Fichier: World.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

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
	void look();
	void use();
	void take();
	void restart();
	bool isPlaying() {return isRunning_;}
	void setPlaying(bool status) { isRunning_ = status; }
private:
	void createRoom();
	Room* currentRoom_;
	Room* beginRoom_;
	std::vector<std::shared_ptr<class Room>> roomList_;
	std::string name_;
	std::string header_;
	bool isRunning_ = true;
};