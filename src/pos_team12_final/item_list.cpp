#include "item_list.h"

namespace pos {
	// Constructor
	item_list::item_list() {
		this->item_count = 0;
	}

	// Destructor: itee_list���� item_array�� ��� item ��ü�� delete
	item_list::~item_list() {
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;

		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++) {
			item = *iter;
			delete(item);
		}
	}

	// Public method

	// ���� ������ŭ total_count ������Ʈ
	void item_list::update_item_count(int update_count) {
		this->item_count += update_count;
	}

	// ���� item�� �����ϴ� ���� �ٽ� ������ total_count ������Ʈ
	void item_list::update_item_count() {
		int total_item_count = 0;
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			total_item_count += item->get_total_count();
		}
		this->item_count = total_item_count;
	}

	// name �޾Ƽ� �̸��� ������ item ��ȯ
	abstract_item* item_list::search_item(string name) {
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item = NULL;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			if (item->get_name() == name) break;
		}
		return item;
	}

	// ��ǰ �߰�
	void item_list::item_push(cart_item* cart_item) {
		abstract_item* item = search_item(cart_item->get_name());
		// cart_item ���� ��ǰ�� item�� ���� �� ����
		item->get_identifier_array().merge(cart_item->get_identifier_array());
		item->get_identifier_array().sort();
		// ��ǰ ���� ����
		item->update_total_count(cart_item->get_total_count());
		this->update_item_count(cart_item->get_total_count());

		delete(cart_item);
	}

	// ��ǰ �߰�
	void item_list::item_push(string name, list<int>& identifier_array) {
		abstract_item* item = search_item(name);
		item->get_identifier_array().merge(identifier_array);
		item->update_total_count();
	}

	// ��ǰ �߰�
	void item_list::item_push(abstract_item* new_item) {
		this->item_array.push_back(new_item);
		new_item->update_total_count();
	}

	// list_item���� name�� ������ item ã�� ���� ������ŭ pop
	cart_item* item_list::item_pop(string name, int count) {
		abstract_item* item = search_item(name);
		// cart item ����
		cart_item* my_cart = new cart_item;
		my_cart->set_name(item->get_name());
		my_cart->set_price(item->get_price());
		my_cart->set_total_count(count);
		my_cart->set_is_over_19(item->get_is_over_19());
		// cart item�� ��ǰ ���
		for (int item_count = 0; item_count < count; item_count++) {
			my_cart->get_identifier_array().push_back(item->item_pop());
		}
		// ���� ���� update
		item->update_total_count(-count);
		this->update_item_count(-count);

		return my_cart;
	}

	// name�� ������ item ���翩�� �Ǵ�
	bool item_list::is_exist_item(string name) {
		bool exist = false;
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;

		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			if (item->get_name() == name) {
				exist = true;
				break;
			}
		}
		return exist;
	}

	// ��� ���ǿ� �´� item ��� (��: ������� �ִ� item�� ���ó�¥�� ���� ���, guarantee �ִ� item�� ���ó�¥���� 5�� �̻� �������� ���)
	void item_list::item_disposal() {
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			item->item_disposal();
		}
		this->update_item_count();
	}

	// item_list ���ο� �ִ� ��� item �̸� ���
	void item_list::show_item_menu() {
		// �ݺ��� ���� 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		int count = 0;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			count = ++count;
			item = *iter;
			cout << count << ". " << item->get_name() << "	" << "����: " << item->get_price() << "	" << "���� ����: " << item->get_total_count() << endl;
		}
	}
}