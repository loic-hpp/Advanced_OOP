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

std::string View::getCommand()
{
	std::string command;
	std::cout << std::endl << "> ";
	std::getline(std::cin, command);
	return command;
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