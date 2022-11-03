#pragma once
#include "Heros.hpp"
#include "Vilain.hpp"
class VilainHeros :
    public Heros,
    public Vilain
{
public:
    VilainHeros(const Heros& hero, const Vilain& vilain);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur = "\033[95m") const override;

private:
    std::string missionSpeciale_;
};

