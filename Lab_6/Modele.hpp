//	Description: Definition de la classe modele.
//	Fichier: Modele.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	6 decembre 2022
//	Créé le 25 novembre 2022

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
}