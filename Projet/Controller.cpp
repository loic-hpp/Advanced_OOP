//	Description: Implementation de la classe Controller.
//	Fichier: Controller.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Controller.hpp"

Controller::Controller(std::shared_ptr<World> world) :
	world_(world)
{
	initializeMapCommand();
}

void Controller::execute(const std::vector<std::string>& command)
{
	auto it = commandMap_.find(command[0]);
	if (it == commandMap_.end())
		throw Invalidcommand("\nCommande non reconnue");
	else 
	{
		auto& [key, value] = *it;
		value(command);
	}
}

void Controller::initializeMapCommand()
{
	commandMap_["N"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->moveNorth(); };
	commandMap_["S"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->moveSouth(); };
	commandMap_["E"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->moveEast(); };
	commandMap_["O"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->moveWest(); };
	commandMap_["look"] = [&](const std::vector<std::string>& command) {world_->look(command); };
	commandMap_["use"] = [&](const std::vector<std::string>& command) {world_->use(command); };
	commandMap_["take"] = [&](const std::vector<std::string>& command) {world_->take(command); };
	commandMap_["restart"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->restart(); };
	commandMap_["exit"] = [&](const std::vector<std::string>& command) {if (command.size() != 1)
		throw Invalidcommand("\nCommande non reconnue");
	else
		world_->setPlaying(false); };
}