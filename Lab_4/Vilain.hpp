//	Description: Définition de la classe Vilain
//	Fichier:  Vilain.hpp
//	Auteurs : Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	07 novembre 2022
//	Créé le 26 octobre 2022

#pragma once
#include "Personnage.hpp"
const std::string ROUGE = "\033[91m";
class Vilain :
    virtual public Personnage
{
public:
    Vilain(const std::string& nom, const std::string& parution, const std::string& objectif);
    Vilain(const Vilain& vilain);
    virtual void afficher(std::ostream& os) const override;
    virtual void changerCouleur(std::ostream& os, const std::string& couleur =ROUGE ) const override;
    virtual std::string getObjectif()const { return objectif_; }
    virtual ~Vilain() = default;
private:
    std::string objectif_;
};

