//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	21 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include "Item.hpp"

Item::Item()
{
}

Item::Item(std::string name, std::string description):
	name_(name), description_(description)
{
}

std::string Item::getName(void)
{
	return name_;
}

std::string Item::getDescription()
{
	return description_;
}

void Item::setIsUsed(bool boolean)
{
	isUsed_ = boolean;
}

bool Item::getIsUsed()
{
	return isUsed_;
}

void Item::setIsTaken(bool boolean)
{
	isTaken_ = boolean;
}

bool Item::getIsTaken()
{
	return isTaken_;
}