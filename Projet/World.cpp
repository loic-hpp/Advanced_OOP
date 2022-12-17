//	Description: Implementation de la classe World.
//	Fichier: World.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

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
	if (isRunning_) 
	{
		currentRoom_->display(o);
	}
	else
	{
		std::cout << "Fin de jeu, va t'en etre productif!" << std::endl;
	}
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
	//if ()
	//{
	//	// look suivi d'un autre mot (inspecter item)
	//}
}

void World::use()
{

}

void World::take()
{

}

void World::restart()
{
	currentRoom_ = beginRoom_;
}

void World::setPlaying(bool status)
{
	isRunning_ = status;
}

void World::createRoom()
{
	roomList_.push_back(std::make_shared<Room>("Balcon", "Petit coin ou profiter de l'air frais avec des chaises et tables"));
	roomList_.push_back(std::make_shared<Room>("Salle de billard", "Sallon de jeux avec comme activité principale le billard"));
	roomList_.push_back(std::make_shared<Room>("Chambre a coucher", "Chambre avec lit Queen de qualite superieure"));
	roomList_.push_back(std::make_shared<Room>("Grand couloir", "Allee reliant plusieurs pieces dans l'hotel"));
	roomList_.push_back(std::make_shared<Room>("Vestiaire", "Entree de l'hotel pour laisser manteaux et bottes"));
	roomList_.push_back(std::make_shared<Room>("Salle de reception", "Salle pour check-in et recuperer ses cles"));
	roomList_.push_back(std::make_shared<Room>("Salle secrete", "Salle ou se trouve le secret le plus grande de Poly"));

	roomList_[1]->setNeighbour(nullptr, roomList_[3].get());
	roomList_[3]->setNeighbour(roomList_[1].get(), roomList_[4].get(),nullptr, roomList_[2].get());
	roomList_[4]->setNeighbour(roomList_[3].get(), nullptr, roomList_[5].get());
	roomList_[5]->setNeighbour(nullptr, nullptr, nullptr, roomList_[4].get());
	roomList_[2]->setNeighbour(nullptr, nullptr, roomList_[3].get());
	
	if (true /* Condition pour verifier si joueur possede diamant pour afficher acces */)
	{
		roomList_[6]->setNeighbour(nullptr, nullptr, nullptr, roomList_[3].get());
	}

	//	TODO : Ajouter setNeighbour du balcon pour utiliser tobogan
	//	roomList_[0]->setNeighbour(nullptr, nullptr, nullptr, roomList_[3].get());
	//	Verifier quoi faire avec exactement

	currentRoom_ = roomList_[4].get();
	beginRoom_ = roomList_[4].get();
}