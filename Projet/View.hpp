//	Description: Definition de la classe View.
//	Fichier: View.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

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

