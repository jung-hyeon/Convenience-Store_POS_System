#pragma once
#include <list>
#include <iostream>
#include "cart_item.h"

using namespace std;

namespace pos {
	class shopping_cart {

	private:
		//private property
		list<cart_item*>cart_list; //cart_item�� ���� ����Ʈ
		int cart_total_count; //īƮ �� �� ������ ����
		int cart_total_price; //īƮ �� ������ �� ����

	public:

		//constructor
		shopping_cart();
		~shopping_cart();

		//public method
		void add_item(cart_item* item); //cart_item ��ü �߰�
		//getter
		int get_cart_total_count();
		int get_cart_total_price();
		list<cart_item*> get_cart_list();
	};
}