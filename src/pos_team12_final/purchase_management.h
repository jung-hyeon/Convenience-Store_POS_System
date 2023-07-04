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

		account_management* account_management; //account_management�� �����ϴ� ������
		stock_management* stock_management; //stock_management�� �����ϴ� ������
		order_management* order_management; //account_management�� �����ϴ� ������
	public:

		//setter
		void set_stock_management(pos::stock_management* stock_management);
		void set_account_management(pos::account_management* account_management);
		void set_order_management(pos::order_management* order_management);

		//�޴� �����ִ� �Լ�
		void show_menu();

		//�Է°� purcahse_item_name(�����ϰ��� �ϴ� ��ǰ �̸�)���� �����ϴ� �Լ�
		string get_purchase_item_name();

		//�Է°� purchase_item_count(�����ϰ��� �ϴ� ��ǰ�� ����)���� �����ϴ� �Լ�
		int get_purchase_item_count();

		//�ǸŸ� ���� �� �۵� �Լ�
		void purchase_run();

		//�ֹ� ������ �޾ƿͼ� shopping_cart���� 
		//�Է°��� 0�϶� shopping_cart ���� ����!
		void put_in_shopping_cart(shopping_cart& cart);

		//�����ϴ� ���� -> account_management�� �����Ͽ� ���� ������Ŵ 
		void purchase_pay(int payment, bool payment_type);

	};
}
