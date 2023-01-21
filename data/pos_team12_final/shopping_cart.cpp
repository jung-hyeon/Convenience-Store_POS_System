#include "shopping_cart.h"

namespace pos {

	//constructor
	shopping_cart::shopping_cart() {
		cart_total_count = 0;
		cart_total_price = 0;

	}
	//destructor
	shopping_cart::~shopping_cart() { //cart_list 내의 cart_item 하나씩 delete
		list<cart_item*>::iterator iter = this->cart_list.begin();
		cart_item* cart_item;
		for (iter = this->cart_list.begin(); iter != this->cart_list.end(); iter++) {
			cart_item = &(**iter);
			delete(cart_item);
		}
	}
	//public method
	int shopping_cart::get_cart_total_count() {
		return this->cart_total_count;
	}
	int shopping_cart::get_cart_total_price() {
		return this->cart_total_price;
	};

	void shopping_cart::add_item(cart_item* item) {
		cart_list.push_back(item);
		int count = item->get_total_count();
		cart_total_count += count; //개수 더해주기 
		cart_total_price += count * item->get_price(); //개수*가격
	};

	list<cart_item*> shopping_cart::get_cart_list() { //getter of cart_list
		return this->cart_list;
	}
}