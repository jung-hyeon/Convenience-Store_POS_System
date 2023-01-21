#include "order.h"

namespace pos {
	//public method
	//setter
	void order::set_order_id(int order_id) {
		this->order_id = order_id;
	}

	void order::set_payment(int payment) {
		this->payment = payment;
	}

	void order::set_payment_type(bool payment_type) {
		this->payment_type = payment_type;
	}

	void order::set_shopping_cart(shopping_cart cart) {
		this->order_cart = cart;
	}

	void order::set_is_refunded(bool answer) {
		this->is_refunded = answer;
	}
	void order::set_coupon(int coupon) {
		this->coupon = coupon;
	}
	void order::set_customer_age(int age) {
		this->customer_age = age;
	}
	void order::set_change(int change) {
		this->change = change;
	}

	//getter
	int order::get_order_id(void) {
		return this->order_id;
	}
	int order::get_payment(void) {
		return this->payment;
	}

	bool order::get_payment_type(void) {
		return this->payment_type;
	}
	shopping_cart order::get_shopping_cart(void) {
		return this->order_cart;
	}

	bool order::get_is_refunded(void) {
		return this->is_refunded;
	}

}