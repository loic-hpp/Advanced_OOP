#pragma once
#include "Modele.hpp"
#include <QObject>
using Modele::Article;

namespace Modele {
	class Caisse : public QObject
	{
		Q_OBJECT
	public:
		std::string doubleToStr(double value);
		double curentTotal();
		void addItem(Article& article);
		void removeItem(std::shared_ptr<Article>& article);
		void removeAllItems();
		void createNewCommand();
	private:
		std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory = {};
		std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated = {};
		double totalBeforeTaxes;
	};
}

