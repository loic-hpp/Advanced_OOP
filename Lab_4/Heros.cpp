#include "Heros.hpp"

Heros();
Heros(string& nom, string& parution, vector<string> nomAllies, string& nomEnnemi);
void afficher(std::ostream& os) const override;
void changerCouleur(std::ostream& os, const int couleurAffichage) const override;
virtual ~Heros() = default;
string obtenirNom() const override;
string obtenirParution() const override;
virtual void obtenirNomEnnemi() const;
virtual void afficherAllies(ostream& os, int& couleur) const;
virtual void poserAllies(const vector<string> nomAllies);