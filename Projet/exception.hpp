//	Description: Definition de la classe Exception.
//	Fichier: Exception.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	12 decembre 2022
//	Créé le 11 décembre 2022

#pragma once
#include <iostream>

class InvalidPosition : public std::invalid_argument {
public:
	using invalid_argument::invalid_argument;
};

class Invalidcommand : public std::domain_error {
public:
	using domain_error::domain_error;
};