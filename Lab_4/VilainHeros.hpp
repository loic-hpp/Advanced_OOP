#pragma once
#include "Heros.hpp"
#include "Vilain.hpp"
class VilainHeros :
    public Heros,
    public Vilain
{
    void afficher(std::ostream& os) const override;
    void changerCouleur(std::ostream& os, const std::string& couleur) const override;
};

