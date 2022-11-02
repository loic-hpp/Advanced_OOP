#pragma once
#include <iostream>
#include <vector>
class Affichable
{
public:
	virtual void afficher(std::ostream& os) const = 0;
	virtual void changerCouleur(std::ostream& os,const std::string& couleur) const= 0;
	virtual ~Affichable() = default;
};

