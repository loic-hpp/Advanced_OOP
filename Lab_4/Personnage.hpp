#pragma once
#include "Affichable.hpp"
const std::string CODE_COULEUR_FIN = "\033[0m";
class Personnage :
    public Affichable
{
public:
    Personnage() = default;
    Personnage(const std::string& nom, const std::string& parution);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur = "\033[0m") const override;
    virtual ~Personnage() = default;
    virtual std::string getNom()const { return nom_; }
    virtual std::string getParution()const { return parution_; }
private:
    std::string nom_;
    std::string parution_;

};

