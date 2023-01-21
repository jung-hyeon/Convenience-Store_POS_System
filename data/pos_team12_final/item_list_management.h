#pragma once
#include <iostream>
#include <string>
#include <list>
#include "item_list.h"
#include "cart_item.h"
#include "abstract_item.h"
#include "item_with_exdate.h"
#include "item_with_guarantee.h"

namespace pos {
	class item_list_management {
	private:
		//Private property
		item_list* item_list;
	public:
		//Public method
		//item_llist_management ��ü setter
		void set_item_list(pos::item_list&);
		//item_list�� ��ǰ �߰�
		void item_push(cart_item*);
		//item_list�� ��ǰ �߰�
		void item_push(string, list<int>&);
		//item_list�� ��ǰ �߰�
		void item_push(abstract_item*);
		//item_list���� ��ǰ ����
		cart_item* item_pop(string, int);
		// ���ڿ��� ������ �������� �߶� int�� �迭�� ��ȯ
		list<int> string_to_listint(string);
		// item_list�� name�� �̸��� ������ ��ǰ�� �����ϴ��� �Ǵ�
		bool is_exist_item(string);
		// ��ǰ �԰�
		void add_item(string);
		// ��ǰ �԰�� item_list�� �̹� �����ϴ� item�� ���, �� ��ǰ�� ���� ����(�������, �������� ��)�� �޾Ƽ� item�� �߰�
		void add_exist_item(string);
		// ��ǰ �԰�� item_list�� �������� �ʴ� item�� ���, item�� ��� ������ �޾� ���� ������ ��, item_list�� �߰�
		void create_new_item(string);
		//item_list�� �����ϴ� item �� ��� ���ǿ� �´� item ���									//item_list�� �����ϴ� �޴� ����� ������
		void item_disposal();
		//item_list�� �����ϴ� item ��� ����
		void show_item_menu();
	};
}