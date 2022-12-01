#include "Caisse.hpp"
namespace Modele {
	std::string Caisse::doubleToStr(double value)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << value;
		return stream.str();
	}

	double Caisse::curentTotal()
	{
		double total = 0.0;
		if (listItemCreated_ == nullptr) {}
		else {
			if (listItemCreated_->empty()) {}
			else {
				for (auto it = listItemCreated_->begin(); it != listItemCreated_->end(); ++it)
					total += (*it)->price;
			}
		}
		return total;
	}

	void addItem(Article& article) {
		if (listItemCreated_ == nullptr)
			listItemCreated_ = std::make_shared<std::list<std::shared_ptr<Article>>>();
		listItemCreated_->push_back(std::make_shared<Article>(article));
	}
}