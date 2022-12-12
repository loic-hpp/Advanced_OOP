//	Description: Implementation de la classe Controller.
//	Fichier: Controller.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#include "Controller.hpp"

Controller::Controller(std::shared_ptr<World> world) :
	world_(world)
{
	initializeMapCommand();
}

void Controller::execute( std::string command)
{
	auto it = commandMap_.find(command);
	if (it == commandMap_.end())
		command = "default";
	switch (commandMap_[command])
	{
	case NORTH:
		world_->moveNorth();
		break;
	case SOUTH:
		world_->moveSouth();
		break;
	case EAST:
		world_->moveEast();
		break;
	case WEST:
		world_->moveWest();
		break;
	case LOOK:
		world_->look();
		break;
	case RESTART:
		world_->restart();
		break;
	case EXIT:
		world_->setPlaying(false);
		break;
	case DEFAULTCASE:
	default:
		throw Invalidcommand("\nCommande non reconnue");
		break;
	}
}

void Controller::initializeMapCommand()
{
	commandMap_["N"] = CommandEnum_::NORTH;
	commandMap_["S"] = CommandEnum_::SOUTH;
	commandMap_["E"] = CommandEnum_::EAST;
	commandMap_["O"] = CommandEnum_::WEST;
	commandMap_["look"] = CommandEnum_::LOOK;
	commandMap_["restart"] = CommandEnum_::RESTART;
	commandMap_["exit"] = CommandEnum_::EXIT;
	commandMap_["default"] = CommandEnum_::DEFAULTCASE;
}
