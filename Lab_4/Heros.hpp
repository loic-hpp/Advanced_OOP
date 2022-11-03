#pragma once
#include "Personnage.hpp"
class Heros :
    virtual public Personnage
{
public:
    Heros(const std::string& nom, const std::string& parution, const std::string& ennemi);
    Heros(const Heros& hero);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur = "\033[94m") const override;
    virtual void setListeAlie(const std::vector<std::string>& allies) { allies_=allies; }
    virtual void affichageSansCouleur(std::ostream& os) const;
    virtual ~Heros() = default;

private:
    std::string ennemi_;
    std::vector<std::string>allies_;
};

