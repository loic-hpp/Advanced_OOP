//	Description: Definition de la classe Room.
//	Fichier: Room.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

#pragma once
#include "inclusion.hpp"

class Room
{
public:
	Room(std::string name, std::string description_);
	 void display(std::ostream& o);
	 Room* getNorthNeighbour();
	 Room* getSouthNeighbour();
	 Room* getEastNeighbour();
	 Room* getWestNeighbour();
	 void setNeighbour(Room* northNeighbour = nullptr,
		 Room* southNeighbour = nullptr,
		 Room* eastNeighbour = nullptr,
		 Room* westNeighbour = nullptr);
	 std::string getName(Room room);
	 enum roomEnum_
	 {
		 VESTIAIRE,
		 SALLE_DE_RECEPTION,
		 GRAND_COULOIR,
		 SALLE_DE_BILLIARD,
		 CHAMBRE_A_COUCHER,
		 BALCON,
		 SALLE_SECRETE
	 };
private:
	std::string name_;
	std::string description_;
	std::map<std::string, Room*> neighbour_;
};