#pragma once
#include "Personnage.hpp"
class Vilain :
    virtual public Personnage
{
public:
    Vilain(const std::string& nom, const std::string& parution, const std::string& objectif);
    Vilain(const Vilain& vilain);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur ="\033[91m" ) const override;
    virtual std::string getObjectif()const { return objectif_; }
    virtual ~Vilain() = default;
private:
    std::string objectif_;
};

