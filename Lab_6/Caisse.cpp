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
		if (listItemCreated == nullptr) {}
		else {
			if (listItemCreated->empty()) {}
			else {
				for (auto it = listItemCreated->begin(); it != listItemCreated->end(); ++it)
					total += (*it)->price;
			}
		}
		return total;
	}
}