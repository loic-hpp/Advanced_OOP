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
	else {
		auto& [key, value] = *it;
		value("");
	}

}

void Controller::initializeMapCommand()
{
	commandMap_["N"] = [&](const std::string& argument) {world_->moveNorth(); };
	commandMap_["S"] = [&](const std::string& argument) {world_->moveSouth(); };
	commandMap_["E"] = [&](const std::string& argument) {world_->moveEast(); };
	commandMap_["O"] = [&](const std::string& argument) {world_->moveWest(); };
	commandMap_["look"] = [&](const std::string& argument) {world_->look(argument); };
	commandMap_["use"] = [&](const std::string& argument) {world_->use(argument); };
	commandMap_["take"] = [&](const std::string& argument) {world_->take(argument); };
	commandMap_["restart"] = [&](const std::string& argument) {world_->restart(); };
	commandMap_["exit"] = [&](const std::string& argument) {world_->setPlaying(false); };
}