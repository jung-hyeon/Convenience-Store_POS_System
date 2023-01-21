#include "cart_item.h"

namespace pos {
	// Constructor
	cart_item::cart_item() {
		this->name = "";
		this->price = 0;
		this->total_count = 0;
		this->is_over_19 = false;
	}

	// Destructor
	cart_item::~cart_item() {}

	// Public pure virtual method
	std::string cart_item::get_name() {
		return this->name;
	}

	int cart_item::get_price() {
		return this->price;
	}

	int cart_item::get_total_count() {
		return this->total_count;
	}

	bool cart_item::get_is_over_19() {
		return this->is_over_19;
	}

	list<int> cart_item::get_identifier_array() {
		return this->identifier_array;
	}

	void cart_item::set_name(std::string name) {
		this->name = name;
	}

	void cart_item::set_price(int price) {
		this->price = price;
	}

	void cart_item::set_total_count(int total_count) {
		this->total_count = total_count;
	}

	void cart_item::set_is_over_19(char answer) {
		int age = answer - '0';
		if (age > 19) {
			this->is_over_19 = true;
		}
		else {
			this->is_over_19 = false;
		}
	}

}