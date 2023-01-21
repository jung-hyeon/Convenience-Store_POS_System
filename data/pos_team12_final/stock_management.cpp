#include "stock_management.h"

namespace pos {

	//Public method
	//item_llist_management ��ü setter
	void stock_management::set_item_list_management(pos::item_list_management* item_list_management) {
		this->item_list_management = item_list_management;
	}

	//ȯ�ҽ� shopping_cart�� ����ִ� ��ǰ�� �ٽ� item_list�� push
	void stock_management::item_push(cart_item* cart_item) {
		this->item_list_management->item_push(cart_item);
	}

	//���Ž� item�� �̸��� ������ŭ item_list���� pop
	cart_item* stock_management::item_pop(string name, int num) {
		return this->item_list_management->item_pop(name, num);
	}

	//��� ���� �߰�
	void stock_management::add_item(string name) {
		this->item_list_management->add_item(name);
	}

	//��ǰ ���ó��
	void stock_management::item_disposal() {
		this->item_list_management->item_disposal();
	}

	//ȯ�� ��ǰ ��� �ٽ� �߰�
	void stock_management::refund(order* refund_order) {
		shopping_cart cart = refund_order->get_shopping_cart();
		int count = cart.get_cart_total_count();

		list<cart_item*>::iterator it;
		it = cart.get_cart_list().begin();
		for (int i = 0; i < count; i++) {
			this->item_push(*it);
		}
	}

	//item_list�� ����ִ� ��� item�� �̸� ���
	void stock_management::show_item_menu() {
		this->item_list_management->show_item_menu();
	}

	//������ ��� ����
	bool stock_management::stock_run() {
		cout << endl;
		char answer;
		while (true) {
			cout << "��� �߰��Ͻðڽ��ϱ�? (Y / N) ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				while (true) {
					string name;
					cout << endl;
					cout << endl;
					cout << "============================ ��� �߰� ���� ==============================" << endl;
					cout << "�߰��� ��ǰ�� �̸��� �Է����ּ���. (�Է� ����: banana, ���̻� �߰��� ��ǰ�� ���� ��� 0�Է�) ";
					cin >> name;
					if (name.compare("0") == 0) break;
					this->add_item(name);
					cout << "============================ ��� �߰� �Ϸ� ===============================" << endl;
					cout << endl;
					cout << endl;
				}
			}
			else {
				cout << "��� �߰����� �ʽ��ϴ�." << endl;
				cout << "============================ ��� �߰� ��� ===============================" << endl;
				cout << endl;
				cout << endl;
				break;
			}
		}
		return true;
	}
}