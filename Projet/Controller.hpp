#pragma once
#include "World.hpp"
class Controller
{
public:
	Controller();
	void execute(const std::string& command);
private:
	std::unique_ptr<World> world;
	 enum CommandEnum_ {
		NORTH,
		SOUTH,
		EAST,
		WEST,
		LOOK,
		RESTART,
	};
	inline static std::map<std::string, CommandEnum_> commandMap_;
	void initializeMapCommand();
};

