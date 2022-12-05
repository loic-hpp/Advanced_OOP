//	Description: Implementation de la classe register.
//	Fichier: Register.cpp
//	Auteurs: Rodrigo A. Merino Martel et Loïc Nguemegne Temena
//	Date	6 decembre 2022
//	Créé le 25 novembre 2022

#include "Register.hpp"
namespace Modele {
	std::string Register::doubleToStr(double value)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << value;
		return stream.str();
	}

	void Register::curentTotal()
	{
		double total = 0.0;
		if (listItemCreated_ == nullptr) {}
		else {
			if (listItemCreated_->empty()) {}
			else {
				for (auto it = listItemCreated_->begin(); it != listItemCreated_->end(); ++it)
					total += (*it)->price;
			}
		}
		totalBeforeTaxes_ = total;
		updateTotal();
	}

	void Register::addItem(std::shared_ptr<Article>& article) {
		if (listItemCreated_ == nullptr)
			listItemCreated_ = std::make_shared<std::list<std::shared_ptr<Article>>>();
		if (article->description == "" or article->price == 0.0) {
			throw std::invalid_argument("Champs requis vide(s)");
		}
		else {
			listItemCreated_->push_back(article);
			emit itemAdded(article);
		}
	}

	void Register::removeItem(std::shared_ptr<Article>& article) {
		listItemCreated_->remove(article);
		updateTotal();
		emit itemDeleted(article);
	}

	bool Register::empty() {
		bool isEmpty = true;
		if (listItemCreated_ != nullptr) {
			if (!(listItemCreated_->empty()))
				isEmpty = false;
		}
		return isEmpty;
	}

	void Register::removeAllItems() {
		if (!empty()) {
			int size = (int)listItemCreated_->size();
			for (int i = 0; i < size; i++)
				listItemCreated_->pop_back();
		}
		updateTotal();
	}

	void Register::createNewCommand() {
		billHistory_.push_back(std::move(listItemCreated_));
		listItemCreated_ = std::make_shared<std::list<std::shared_ptr<Article>>>();
	}

	void Register::updateTotal() {
		taxesTotal_ = 0.0;
		auto a = std::count_if(listItemCreated_->begin(), listItemCreated_->end(),
			[&](auto item) {if ((item)->taxable) { taxesTotal_ += (item)->price * TAXES_VALUE; }
		return item->taxable; });
		totalToPay_ = totalBeforeTaxes_ + taxesTotal_;
	}
}
