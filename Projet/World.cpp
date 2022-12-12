#include "World.hpp"

World::World(std::string name, std::string header):
	name_(name), header_(header)
{
	createRoom();
}

void World::display(std::ostream& o)
{
	o << "\n>>>>>>>> " << header_ << " <<<<<<<<<<"
		<< "\n> > > > > " << name_ << " < < < < <";
}

void World::displayCurrentRoom(std::ostream& o)
{
	currentRoom_->display(o);
}

void World::moveNorth()
{
	if (currentRoom_->getNorthneighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getNorthneighbour();
}

void World::moveSouth()
{
	if (currentRoom_->getSouthneighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getSouthneighbour();
}

void World::moveEast()
{
	if (currentRoom_->getEastneighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getEastneighbour();
}

void World::moveWest()
{
	if (currentRoom_->getWestneighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getWestneighbour();
}

void World::look()
{
}

void World::restart()
{
	currentRoom_ = beginRoom_;
}

void World::createRoom()
{
	rommList_.push_back(std::make_shared<Room>("Balcon", "Petite coin ou profiter de l'air frais avec chaises et tables"));
	rommList_.push_back(std::make_shared<Room>("Salle de billard", "Sallon de jeux avec comme activité principale le billard"));
	rommList_.push_back(std::make_shared<Room>("Chambre a coucher", "Chambre avec lit Queen de qualite superieure"));
	rommList_.push_back(std::make_shared<Room>("Grand couloir", "Allee reliant plusieurs pieces dans l'hotel"));
	rommList_.push_back(std::make_shared<Room>("vestiaire", "Entree de l'hotel pour laisser menteaux et bottes"));
	rommList_.push_back(std::make_shared<Room>("salle de reception", "Salle pour check-in et recuperer ses cles"));

	rommList_[1]->setNeighbour(nullptr, rommList_[3]);
	rommList_[3]->setNeighbour(rommList_[1], rommList_[4],nullptr, rommList_[2]);
	rommList_[4]->setNeighbour(rommList_[3], nullptr, rommList_[5]);
	rommList_[5]->setNeighbour(nullptr, nullptr, nullptr, rommList_[4]);
	rommList_[2]->setNeighbour(nullptr, nullptr, rommList_[3]);

	currentRoom_ = rommList_[4];
	beginRoom_ = rommList_[4];
}
