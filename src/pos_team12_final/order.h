#pragma once
#include <iostream>
#include <string>
#include <list> 
#include "shopping_cart.h"

using namespace std;

namespace pos {
	class order {

	private:
		//private property
		shopping_cart order_cart; // 구매 상품 목록
		int order_id; // 영수증 번호
		int coupon; // 쿠폰(금액 할인)
		int payment; //소비자 지불 금액
		int customer_age; // 구매자 나이
		int change; //거스름돈
		bool payment_type; //카드=0 현금=1
		bool is_refunded = false;//환불 여부 default = false


	public:

		//public method

		//setter
		void set_order_id(int order_id); // order_id. from order_management
		void set_payment(int payment);
		void set_shopping_cart(shopping_cart cart);
		void set_is_refunded(bool answer);
		void set_payment_type(bool payment_type);
		void set_coupon(int coupon);
		void set_customer_age(int age);
		void set_change(int change);
		//getter
		int get_order_id(void);
		int get_payment(void);
		shopping_cart get_shopping_cart(void);
		bool get_is_refunded(void);
		bool get_payment_type(void);


	};
}