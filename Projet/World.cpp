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
	if (currentRoom_->getSouthneighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getSouthneighbour();
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
	rommList_.push_back(std::make_shared<Room>("Room1", "Description Room1"));
	rommList_.push_back(std::make_shared<Room>("Room2", "Description Room2"));
	rommList_.push_back(std::make_shared<Room>("Room3", "Description Room3"));
	rommList_[1]->setNeighbour(rommList_[0], rommList_[2]);
	currentRoom_ = rommList_[1];
	beginRoom_ = rommList_[1];
}
