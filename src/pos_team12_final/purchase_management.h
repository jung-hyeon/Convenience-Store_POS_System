#pragma once
#include <iostream>
#include <string>
#include "account_management.h"
#include "stock_management.h"
#include "order_management.h"
#include "shopping_cart.h"
#include "cart_item.h"

using namespace std;

namespace pos {

	class purchase_management {

	private:

		account_management* account_management; //account_management에 접근하는 포인터
		stock_management* stock_management; //stock_management에 접근하는 포인터
		order_management* order_management; //account_management에 접근하는 포인터
	public:

		//setter
		void set_stock_management(pos::stock_management* stock_management);
		void set_account_management(pos::account_management* account_management);
		void set_order_management(pos::order_management* order_management);

		//메뉴 보여주는 함수
		void show_menu();

		//입력값 purcahse_item_name(구매하고자 하는 상품 이름)으로 저장하는 함수
		string get_purchase_item_name();

		//입력값 purchase_item_count(구매하고자 하는 상품의 개수)으로 저장하는 함수
		int get_purchase_item_count();

		//판매를 위한 주 작동 함수
		void purchase_run();

		//주문 정보를 받아와서 shopping_cart생성 
		//입력값이 0일때 shopping_cart 생성 종료!
		void put_in_shopping_cart(shopping_cart& cart);

		//결제하는 과정 -> account_management에 접근하여 매출 증가시킴 
		void purchase_pay(int payment, bool payment_type);

	};
}
