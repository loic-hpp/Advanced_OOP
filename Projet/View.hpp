#pragma once
#include "Controller.hpp"
class View
{
public:
	void setUpView();
	void actualizeView();
	std::string getCommand();
	void playGame();
	bool isPlaying() { return world_->isPlaying();}

private:
	std::unique_ptr<Controller> controller_;
	std::shared_ptr<World> world_;
};

