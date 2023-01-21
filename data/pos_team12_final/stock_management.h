#pragma once
#include<iostream>
#include<string>
#include "item_list_management.h"
#include "cart_item.h"
#include "order.h"
#include "shopping_cart.h"

namespace pos {
	class stock_management {
	private:
		//Private property
		item_list_management* item_list_management;
	public:
		//Public method
		// item_llist_management 객체 setter
		void set_item_list_management(pos::item_list_management*);
		//환불시 shopping_cart에 담겨있던 상품을 다시 item_list에 push
		void item_push(cart_item*);
		//구매시 item의 이름과 수량만큼 item_list에서 pop
		cart_item* item_pop(string, int);
		//재고를 직접 추가
		void add_item(string);
		//상품 폐기처리
		void item_disposal();
		//환불 상품 재고에 다시 추가
		void refund(order*);
		//item_list에 담겨있는 모든 item의 이름 출력
		void show_item_menu();
		//재고관리 기능 실행
		bool stock_run();
	};
}