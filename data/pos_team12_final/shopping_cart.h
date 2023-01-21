#pragma once
#include <list>
#include <iostream>
#include "cart_item.h"

using namespace std;

namespace pos {
	class shopping_cart {

	private:
		//private property
		list<cart_item*>cart_list; //cart_item이 담기는 리스트
		int cart_total_count; //카트 내 총 물건의 개수
		int cart_total_price; //카트 내 물건의 총 가격

	public:

		//constructor
		shopping_cart();
		~shopping_cart();

		//public method
		void add_item(cart_item* item); //cart_item 객체 추가
		//getter
		int get_cart_total_count();
		int get_cart_total_price();
		list<cart_item*> get_cart_list();
	};
}