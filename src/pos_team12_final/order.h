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
		shopping_cart order_cart; // ���� ��ǰ ���
		int order_id; // ������ ��ȣ
		int coupon; // ����(�ݾ� ����)
		int payment; //�Һ��� ���� �ݾ�
		int customer_age; // ������ ����
		int change; //�Ž�����
		bool payment_type; //ī��=0 ����=1
		bool is_refunded = false;//ȯ�� ���� default = false


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