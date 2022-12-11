#include "Controller.hpp"

Controller::Controller()
{
	initializeMapCommand();
}

void Controller::execute(const std::string& command)
{
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
	commandMap_["E"] = CommandEnum_::WEST;
	commandMap_["look"] = CommandEnum_::LOOK;
	commandMap_["restart"] = CommandEnum_::RESTART;
	commandMap_["exit"] = CommandEnum_::EXIT;
}
