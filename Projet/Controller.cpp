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
		world->moveNorth();
		break;
	case SOUTH:
		world->moveSouth();
		break;
	case EAST:
		world->moveEast();
		break;
	case WEST:
		world->moveWest();
		break;
	case LOOK:
		world->look();
		break;
	case RESTART:
		world->restart();
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
}
