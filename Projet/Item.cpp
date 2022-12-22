//	Description: Implementation de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	21 decembre 2022
//	Créé le 11 décembre 2022

#include "Item.hpp"

Item::Item()
{
}

Item::Item(std::string searchKey, std::string name, std::string description, bool isUsable, bool isTakeable):
	searchKey_(searchKey), name_(name), description_(description), isUsable_(isUsable), isTakeable_(isTakeable)
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

void Item::setIsTakeable(bool boolean)
{
	isTakeable_ = boolean;
}

bool Item::getIsTakeable(void)
{
	return isTakeable_;
}

void Item::setIsUsable(bool boolean)
{
	isUsable_ = boolean;
}

bool Item::getIsUsable(void)
{
	return isUsable_;
}

void Item::display(std::ostream& o)
{
	o << "\n" << description_ << std::endl;
}