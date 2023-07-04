#include "item_list_management.h"
#include <sstream>

namespace pos {
	//Public method

	//item_llist_management ��ü setter
	void item_list_management::set_item_list(pos::item_list& item_list) {
		this->item_list = &item_list;
	}

	//item_list�� ��ǰ �߰�
	void item_list_management::item_push(cart_item* cart_item) {
		this->item_list->item_push(cart_item);
	}

	//item_list�� ��ǰ �߰�
	void item_list_management::item_push(string name, list<int>& item_array) {
		this->item_list->item_push(name, item_array);
	}

	//item_list�� ��ǰ �߰�
	void item_list_management::item_push(abstract_item* new_item) {
		this->item_list->item_push(new_item);
	}

	//item_list���� ��ǰ ����
	cart_item* item_list_management::item_pop(string name, int count) {
		return this->item_list->item_pop(name, count);
	}

	// ���ڿ��� ������ �������� �߶� int�� �迭�� ��ȯ
	list<int> item_list_management::string_to_listint(string st) {
		istringstream ss(st);
		string strBuffer;
		list<int> identifier_list;
		//ss���� ���ڿ� ���ۿ� ������(' ')�� �ڸ��� ���� ���ڿ��� �����
		while (getline(ss, strBuffer, ' ')) {
			identifier_list.push_back(stoi(strBuffer));
		}
		//
		list<int>::iterator it; //�ݺ��� ����

		for (it = identifier_list.begin(); it != identifier_list.end(); it++) {
			//it�� li.begin()�� ����Ŵ, it�� li.end()�� ����Ű�� ���������� �ݺ�, it�� �������� ����Ŵ
			printf("%d ", *it); //���� ������ *it�� �̿�
		}
		//
		return identifier_list;
	}

	// item_list�� name�� �̸��� ������ ��ǰ�� �����ϴ��� �Ǵ�
	bool item_list_management::is_exist_item(string name) {
		return this->item_list->is_exist_item(name);
	}

	// ��ǰ �԰�
	void item_list_management::add_item(string name) {
		//�̹� �����ϸ� item������ update
		if (this->is_exist_item(name)) {
			this->add_exist_item(name);
		}
		//�������� ������ ���� item ���� item_list�� push
		else {
			this->create_new_item(name);
		}
	}

	// ��ǰ �԰�� item_list�� �̹� �����ϴ� item�� ���, �� ��ǰ�� ���� ����(�������, �������� ��)�� �޾Ƽ� item�� �߰�
	void item_list_management::add_exist_item(string name) {
		int count;
		string identifier;
		cout << name << "�� ������ �Է��ϼ���. (�Է� ����: 1) ";		//count ����ŭ �ݺ��� ������
		cin >> count;
		cout << name << " " << count << "���� " << "���� ���� �Ǵ� ǰ�� ���� ������ �Է��ϼ���. (�Է� ����: 20221219 20221219 20221224)" << endl;
		cout << "(���� ������ ���� ��쿡�� ���� �Է�, �Է� �� Enter)" << endl;
		cin >> identifier;

		// ���� ���� �迭�� item�� push
		list<int> identifier_list = this->string_to_listint(identifier);
		this->item_push(name, identifier_list);

		cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl;
	}

	// ��ǰ �԰�� item_list�� �������� �ʴ� item�� ���, item�� ��� ������ �޾� ���� ������ ��, item_list�� �߰�
	void item_list_management::create_new_item(string name) {
		int price, count;				//��ǰ�� ���ݰ� ����
		char is_over_19;				//19�� �̻� �Ǹ� ��ǰ���θ� ���� ����
		int identifier;				//���� ����

		cout << name << "��(��) 19�� �̸� �Ǹű��� ��ǰ�Դϱ�? (Y / N) ";
		cin >> is_over_19;

		cout << name << "�� ������ �Է��ϼ���. (�Է� ����: 2000) ";
		cin >> price;

		cout << name << "�� ������ �Է��ϼ���. (�Է� ����: 3) ";		//count ����ŭ �ݺ��� ������
		cin >> count;

		cout << name << "�� ���� ������ �����Դϱ�? (1. ���� ���� 2. ���� ����) (�Է� ����: 1) ";
		cin >> identifier;
		if (identifier == 1) {
			int ex_date;
			list<int> ex_date_list;
			cout << name << " "<< count << "���� "<< "���� ������ �Է��ϼ���. (���� ������ ���� ��쿡�� ���� �Է�)" << endl;
			cout << "(�Է� ����: 20221219 20221219 20221224)(�Է� �� Enter)" << endl;
			for (int i = 1; i <= count; i++) {
				cin >> ex_date;
				ex_date_list.push_back(ex_date);
			}

			item_with_exdate* new_item = new item_with_exdate;
			new_item->set_name(name);
			new_item->set_price(price);
			new_item->set_is_over_19(is_over_19);
			new_item->set_identifier_array(ex_date_list);
			this->item_push(new_item);
		}
		else if (identifier == 2) {
			int guarantee;
			list<int> guarantee_list;
			cout << name << " " << count << "���� " << "ǰ�� ���� ������ �Է��ϼ���. (ǰ�� ���� ������ ���� ��쿡�� ���� �Է�)" << endl;
			cout << "(�Է� ����: 20301219 20301219 20301224)(�Է� �� Enter)" << endl;

			for (int i = 1; i <= count; i++) {
				cin >> guarantee;
				guarantee_list.push_back(guarantee);
			}

			item_with_guarantee* new_item = new item_with_guarantee;
			new_item->set_name(name);
			new_item->set_price(price);
			new_item->set_is_over_19(is_over_19);
			new_item->set_identifier_array(guarantee_list);
			this->item_push(new_item);
			new_item->set_total_count(count);
		}
		cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl;
	}

	//item_list�� �����ϴ� item �� ��� ���ǿ� �´� item ���
	void item_list_management::item_disposal() {
		this->item_list->item_disposal();
	}

	//item_list�� �����ϴ� item ��� ����
	void item_list_management::show_item_menu() {
		this->item_list->show_item_menu();
	}
}