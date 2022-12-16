//	Description: Implementation de la classe World.
//	Fichier: World.cpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

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
	if (currentRoom_->getNorthNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getNorthNeighbour();
}

void World::moveSouth()
{
	if (currentRoom_->getSouthNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getSouthNeighbour();
}

void World::moveEast()
{
	if (currentRoom_->getEastNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getEastNeighbour();
}

void World::moveWest()
{
	if (currentRoom_->getWestNeighbour() == nullptr)
		throw InvalidPosition("\nPas de case a cette position.\n");
	else
		currentRoom_ = currentRoom_->getWestNeighbour();
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
	rommList_.push_back(std::make_shared<Room>("Balcon", "Petit coin ou profiter de l'air frais avec des chaises et tables"));
	rommList_.push_back(std::make_shared<Room>("Salle de billard", "Sallon de jeux avec comme activit� principale le billard"));
	rommList_.push_back(std::make_shared<Room>("Chambre a coucher", "Chambre avec lit Queen de qualite superieure"));
	rommList_.push_back(std::make_shared<Room>("Grand couloir", "Allee reliant plusieurs pieces dans l'hotel"));
	rommList_.push_back(std::make_shared<Room>("Vestiaire", "Entree de l'hotel pour laisser menteaux et bottes"));
	rommList_.push_back(std::make_shared<Room>("Salle de reception", "Salle pour check-in et recuperer ses cles"));

	rommList_[1]->setNeighbour(nullptr, rommList_[3].get());
	rommList_[3]->setNeighbour(rommList_[1].get(), rommList_[4].get(),nullptr, rommList_[2].get());
	rommList_[4]->setNeighbour(rommList_[3].get(), nullptr, rommList_[5].get());
	rommList_[5]->setNeighbour(nullptr, nullptr, nullptr, rommList_[4].get());
	rommList_[2]->setNeighbour(nullptr, nullptr, rommList_[3].get());

	currentRoom_ = rommList_[4].get();
	beginRoom_ = rommList_[4].get();
}