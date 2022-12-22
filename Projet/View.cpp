//	Description: Implementation de la classe View.
//	Fichier: View.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "View.hpp"

View::View(std::shared_ptr<Controller> controller, std::shared_ptr<World> world):
	controller_(controller), world_(world)
{
	setUpView();
}

void View::setUpView()
{
	world_->display(std::cout);
	actualizeView();
}

void View::actualizeView()
{
	std::cout << std::endl;
	world_->displayCurrentRoom(std::cout);
}

std::vector<std::string> View::getCommand()
{
	std::string command;
	std::cout << std::endl << "> ";
	std::getline(std::cin, command);
	
	std::stringstream ss(command);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	
	return std::vector<std::string>(begin, end);
}

void View::playGame()
{
	try {
		controller_->execute(getCommand());
		actualizeView();
	}
	catch (InvalidPosition& e) {
		std::cout << std::endl << e.what() << std::endl;
	}
	catch (Invalidcommand& e) {
		std::cout << std::endl << e.what() << std::endl;
	}
}