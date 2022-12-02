#include "Modele.hpp"

namespace Modele {
	std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory = {};
	std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated = {};
	double totalBeforeTaxes = 0;

std::string doubleToStr(double value) {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << value;
	return stream.str();
}

double curentTotal()
{
	double total = 0.0;
	if(listItemCreated == nullptr){}
	else {
		if(listItemCreated->empty()){}
		else {
			for (auto it = listItemCreated->begin(); it != listItemCreated->end(); ++it)
				total += (*it)->price;
		}
	}
	return total;
}

}
