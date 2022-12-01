#pragma once
#include "Modele.hpp"
#include <QObject>
using Modele::Article;

namespace Modele {
	class Register : public QObject
	{
		Q_OBJECT
	public:
		std::string doubleToStr(double value);
		void curentTotal();
		void addItem(std::shared_ptr<Article>& article);
		void removeItem(std::shared_ptr<Article>& article);
		void removeAllItems();
		void createNewCommand();
		int getItemNumber() { return (int)listItemCreated_->size(); }
		double getTotalBeforeTaxes() { return totalBeforeTaxes_; }
		std::list<std::shared_ptr<Article>>::iterator getFirstItemIterator() {return listItemCreated_->begin();}
		std::list<std::shared_ptr<Article>>::iterator getLastItemIterator() { return listItemCreated_->end(); }
		bool empty();
	signals:
		void itemAdded(std::shared_ptr<Article>& article);
		void itemDeleted(std::shared_ptr<Article>& article);
		void invalidData();
	private:
		std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory_ = {};
		std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated_ = {};
		double totalBeforeTaxes_;
	};
}

