#pragma once
#include "World.hpp"
class Controller
{
public:
	Controller();
	void execute(const std::string& command);
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
	};
	inline static std::map<std::string, CommandEnum_> commandMap_;
	void initializeMapCommand();
};

