//	Description: Definition de la classe Item.
//	Fichier: Item.hpp
//	Auteurs: Rodrigo A. Merino Martel et Lo�c Nguemegne Temena
//	Date	12 decembre 2022
//	Cr�� le 11 d�cembre 2022

#include <string>
#include <vector>
#include <memory>

class Item
{
public:
	Item(std::string description_);
	void createVectorListItems(void);
	std::vector<Item> getVectorListItems(void);
	std::string getDescription();
	// TODO: methode pour trouver mots cles de la description d'un item a partir de la commande pass�e
private:
	std::string description_;
	std::vector<std::shared_ptr<class Item>> itemList_;
};