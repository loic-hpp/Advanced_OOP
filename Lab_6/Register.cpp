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
	}

	void Register::addItem(std::shared_ptr<Article>& article) {
		if (listItemCreated_ == nullptr)
			listItemCreated_ = std::make_shared<std::list<std::shared_ptr<Article>>>();
		listItemCreated_->push_back(article);
		emit itemAdded(article);
	}

	void Register::removeItem(std::shared_ptr<Article>& article) {
		listItemCreated_->remove(article);
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
		if(!empty()) {
				int size = (int)listItemCreated_->size();
				for (int i = 0; i < size; i++)
					listItemCreated_->pop_back();
			}
		}

	void Register::createNewCommand() {
		billHistory_.push_back(std::move(listItemCreated_));
		listItemCreated_ = std::make_shared<std::list<std::shared_ptr<Article>>>();
	}

	}
