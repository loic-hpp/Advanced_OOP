//	Description: Definition de la classe Controller.
//	Fichier: Controller.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#pragma once
#include "World.hpp"

class Controller
{
public:
	Controller(std::shared_ptr<World> world);
	void execute(const std::vector<std::string>& command);
private:
	std::shared_ptr<World> world_;
	inline static std::map<std::string, std::function<void(const std::string&)>> commandMap_;
	void initializeMapCommand();
};