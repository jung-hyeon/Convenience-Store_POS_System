#include "refund_management.h"

namespace pos {
	//Stock Management ��ü Setter
	void refund_management::set_stock_management(pos::stock_management& stock_management) {
		this->stock_management = &stock_management;
	}
	//Account Management ��ü Setter
	void refund_management::set_account_management(pos::account_management& account_management) {
		this->account_management = &account_management;
	}
	//Order Management ��ü Setter
	void refund_management::set_order_management(pos::order_management& order_management) {
		this->order_management = &order_management;
	}

	void refund_management::refund_run() {
		cout << endl;
		order* refund_order = NULL;
		cout << "ȯ���� �����Ͻðڽ��ϱ�? (�κ� ȯ���� �������� �ʽ��ϴ�.) (Y / N)";
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << endl;
			cout << endl;
			cout << "============================ ȯ�� ���� ==============================" << endl;
			cout << "ȯ�� ������ ��ȣ�� �Է��� �ּ���. (�Է� ����: 0)";
			int refund_order_id; 
			cin >> refund_order_id;
			refund_order = this->order_management->pop_order_log(refund_order_id); //Order Management ���� ������ ��ȣ ��ȸ�ϱ� ���� Null ������ �Ű� ���� ����.
			if ( refund_order == NULL) //My Order�� �״�� Null�̸� ����
			{
				cout << "�������� �ʴ� ������ ��ȣ�Դϴ�." << endl;
				cout << "============================ ȯ�� ���� ==============================" << endl;
				cout << endl;
				cout << endl;
			}
			else { //My Order�� �ּ� ���� ���� ���� ����
				cout << "���� ��ȸ�� �����߽��ϴ�. ȯ���� �����մϴ�." << endl;
				this->stock_management->refund(refund_order); //Stock Management���� ȯ�� ����
				this->account_management->refund(refund_order); //Account Management���� ȯ�� ����
				cout << "ȯ���� �����߽��ϴ�." << endl;
				cout << "============================ ȯ�� ���� ==============================" << endl;
				cout << endl;
				cout << endl;
			}
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "ȯ�� ������ ����մϴ�." << endl;
			cout << "============================ ȯ�� ��� ==============================" << endl;
			cout << endl;
			cout << endl;
		}
	}
}