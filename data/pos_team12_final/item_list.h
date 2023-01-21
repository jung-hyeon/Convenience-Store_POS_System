#pragma once
#include <iostream>
#include <string>
#include <list>
#include "abstract_item.h"
#include "cart_item.h"
using namespace std;

namespace pos {
	class item_list {
	protected:
		// Protected property
		int item_count;

	public:
		// Constructor & Destructor
		item_list();
		~item_list();

		// Public property
		list<abstract_item*> item_array;

		// Public method

		// ���� ������ŭ total_count ������Ʈ
		void update_item_count(int);
		// ���� item�� �����ϴ� ���� �ٽ� ������ total_count ������Ʈ
		void update_item_count();
		// name �޾Ƽ� �̸��� ������ item ��ȯ
		abstract_item* search_item(string);
		// ��ǰ �߰�
		void item_push(cart_item*);
		// ��ǰ �߰�
		void item_push(string, list<int>&);
		// ��ǰ �߰�
		void item_push(abstract_item*);
		// list_item���� name�� ������ item ã�� ���� ������ŭ pop
		cart_item* item_pop(std::string, int);
		// name�� ������ item ���翩�� �Ǵ�
		bool is_exist_item(string);
		// ��� ���ǿ� �´� item ��� (��: ������� �ִ� item�� ���ó�¥�� ���� ���, guarantee �ִ� item�� ���ó�¥���� 5�� �̻� �������� ���)
		void item_disposal();
		// item_list ���ο� �ִ� ��� item �̸� ���
		void show_item_menu();
	};
}