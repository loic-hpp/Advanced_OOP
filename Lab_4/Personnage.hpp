#pragma once
#include "Affichable.hpp"
const std::string CODE_COULEUR_FIN = "\033[0m";
class Personnage :
    public Affichable
{
public:
    Personnage(const std::string& nom, const std::string& parution);
    void afficher(std::ostream& os) const override;
    void changerCouleur(std::ostream& os, const std::string&) const override;
private:
    std::string nom_;
    std::string parution_;

};

