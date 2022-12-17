//	Description: Definition de la classe Controller.
//	Fichier: Controller.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

#pragma once
#include "World.hpp"

class Controller
{
public:
	Controller(std::shared_ptr<World> world);
	void execute(std::string command);
private:
	std::shared_ptr<World> world_;
	 enum CommandEnum_ 
	 {
		NORTH,
		SOUTH,
		EAST,
		WEST,
		LOOK,
		USE,
		TAKE,
		RESTART,
		EXIT,
		DEFAULTCASE,
	};
	inline static std::map<std::string, CommandEnum_> commandMap_;
	void initializeMapCommand();
};