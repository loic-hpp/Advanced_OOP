#pragma once
#include "Modele.hpp"
using Modele::Article;
namespace Modele {
	class Caisse
	{
	public:
		std::string doubleToStr(double value);
		double curentTotal();
	private:
		std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory;
		std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated;
		double totalBeforeTaxes;
	};
}

