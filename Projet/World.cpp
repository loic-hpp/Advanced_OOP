#include "World.hpp"

World::World()
{
	createRoom();
}

void World::display(std::ostream& o)
{
	o << "\n>>>>>>>> " << header_ << " <<<<<<<<<<\n"
		<< "> > > > > " << name_ << " < < < < <";
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
}
