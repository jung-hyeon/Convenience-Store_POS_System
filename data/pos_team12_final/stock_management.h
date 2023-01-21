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
		// item_llist_management ��ü setter
		void set_item_list_management(pos::item_list_management*);
		//ȯ�ҽ� shopping_cart�� ����ִ� ��ǰ�� �ٽ� item_list�� push
		void item_push(cart_item*);
		//���Ž� item�� �̸��� ������ŭ item_list���� pop
		cart_item* item_pop(string, int);
		//��� ���� �߰�
		void add_item(string);
		//��ǰ ���ó��
		void item_disposal();
		//ȯ�� ��ǰ ��� �ٽ� �߰�
		void refund(order*);
		//item_list�� ����ִ� ��� item�� �̸� ���
		void show_item_menu();
		//������ ��� ����
		bool stock_run();
	};
}