#pragma once
#include "Controller.hpp"
class View
{
public:
	View(std::shared_ptr<Controller> controller, std::shared_ptr<World> world);
	void setUpView();
	void actualizeView();
	std::string getCommand();
	void playGame();
	bool isPlaying() { return world_->isPlaying();}

private:
	std::shared_ptr<Controller> controller_;
	std::shared_ptr<World> world_;
};

