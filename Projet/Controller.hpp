#pragma once
#include "World.hpp"
class Controller
{
public:
	Controller(std::shared_ptr<World> world);
	void execute( std::string command);
private:
	std::shared_ptr<World> world_;
	 enum CommandEnum_ {
		NORTH,
		SOUTH,
		EAST,
		WEST,
		LOOK,
		RESTART,
		EXIT,
		DEFAULTCASE,
	};
	inline static std::map<std::string, CommandEnum_> commandMap_;
	void initializeMapCommand();
};

