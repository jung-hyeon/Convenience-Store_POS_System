#include "item_with_guarantee.h"
extern int today;

namespace pos {
	// Constructor
	item_with_guarantee::item_with_guarantee() {
		this->name = "";
		this->price = 0;
		this->total_count = 0;
		this->is_over_19 = false;
	}

	// Destructor
	item_with_guarantee::~item_with_guarantee() {}

	// Public pure virtual method
	std::string item_with_guarantee::get_name() {
		return this->name;
	}

	int item_with_guarantee::get_price() {
		return this->price;
	}

	int item_with_guarantee::get_total_count() {
		return this->total_count;
	}

	bool item_with_guarantee::get_is_over_19() {
		return this->is_over_19;
	}

	list<int> item_with_guarantee::get_identifier_array() {
		return this->identifier_array;
	}

	void item_with_guarantee::set_name(std::string name) {
		this->name = name;
	}

	void item_with_guarantee::set_price(int price) {
		this->price = price;
	}

	void item_with_guarantee::set_total_count(int total_count) {
		this->total_count = total_count;
	}

	void item_with_guarantee::set_is_over_19(char answer) {
		if (answer == 'y' || answer == 'Y') {
			this->is_over_19 = true;
		}
		else if (answer == 'n' || answer == 'N') {
			this->is_over_19 = false;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}

	void item_with_guarantee::set_identifier_array(list<int>& identifier_array) {
		this->identifier_array = identifier_array;
	}

	// ���� ������ŭ total_count ������Ʈ
	void item_with_guarantee::update_total_count(int update_count) {
		this->total_count += update_count;
	}

	// ���� ������ŭ total_count ������Ʈ
	void item_with_guarantee::update_total_count() {
		this->total_count = this->identifier_array.size();
	}

	// ���� item�� �����ϴ� ��� ���ǿ� �´� �͵� ���
	void item_with_guarantee::item_disposal() {
		list<int>::iterator it; //�ݺ��� ����
		for (it = this->identifier_array.begin(); it != this->identifier_array.end(); it++) {
			// ���������� ���� ��¥���� 5�������̸� ���
			if (*it < today - 50000) {
				this->identifier_array.remove(*it);
			}
		}
	}

	// ���� ������ item pop & pick
	int item_with_guarantee::item_pop() {
		int item = this->identifier_array.front();
		this->identifier_array.pop_front();
		return item;
	}
}