#pragma once
#include "Personnage.hpp"
class Heros :
    virtual public Personnage
{
public:
    Heros(const std::string& nom, const std::string& parution, const std::string& ennemi,
        const std::vector<std::string> &allies);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur) const override;
    virtual ~Heros() = default;

private:
    std::string ennemi_;
    std::vector<std::string>allies_;
};

