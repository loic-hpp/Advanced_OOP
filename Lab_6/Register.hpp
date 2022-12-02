#pragma once
#include "Modele.hpp"
#include <QObject>
const double TAXES_VALUE = 0.14975;
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
		void setTotalTaxes(double value) { taxesTotal_ = value; }
		void setTotalToPay(double value) { totalToPay_ = value; }
		double getTotalBeforeTaxes() { return totalBeforeTaxes_; }
		double getTotalTaxes() { return taxesTotal_; }
		double getTotalToPay() { return totalToPay_; }
		std::list<std::shared_ptr<Article>>::iterator getFirstItemIterator() {return listItemCreated_->begin();}
		std::list<std::shared_ptr<Article>>::iterator getLastItemIterator() { return listItemCreated_->end(); }
		bool empty();
		void updateTotal();
	signals:
		void itemAdded(std::shared_ptr<Article>& article);
		void itemDeleted(std::shared_ptr<Article>& article);
	private:
		std::vector<std::shared_ptr<std::list<std::shared_ptr<Article>>>> billHistory_ = {};
		std::shared_ptr<std::list<std::shared_ptr<Article>>> listItemCreated_ = {};
		double totalBeforeTaxes_, taxesTotal_, totalToPay_;

	};
}

