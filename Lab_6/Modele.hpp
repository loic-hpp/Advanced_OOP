#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <list>
#include <vector>


namespace Modele {
	struct Article
	{
		std::string description;
		double price;
		bool taxable;
		~Article() = default;
		std::string displayArticle() {
			return (description + "\t"
				+ displayPrice() + "\t"
				+ (taxable ? "Taxable" : "Non taxable"));
		}
		std::string displayPrice() {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(2) << price;
			return stream.str();
		}
	};

	std::string doubleToStr(double value);
	double curentTotal();
	extern std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory;
	extern std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated;
	extern double totalBeforeTaxes;
}