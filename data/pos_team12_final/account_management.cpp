#include "account_management.h"
extern int today;

namespace pos {
	//Stock Management ��ü Setter
	void account_management::set_stock_management(pos::stock_management& stock_management) {
		this->stock_management = &stock_management;
	}

	void account_management::set_money(pos::money& money) {
		this->money = &money;
	}

	//���� ����
	void account_management::dayclose() {
		this->money->calculate_day_revenue(); //���� �ջ� ����
		this->stock_management->item_disposal(); //Stock Management�� ��� ����
		push_sales_log(); //��¥�� ���� Push
		this->money->set_card_money(0); //ī�� ���� �ʱ�ȭ
		this->money->set_cash(this->ready_money); //���� �� �ʱ�ȭ
		int new_capital;
		new_capital = this->money->get_capital() - this->ready_money;
		this->money->set_capital(new_capital); //���� �� ä�� ��ŭ �ں��ݿ��� ���ϱ�
	}

	//���� �� �� ��� �߰�
	void account_management::push_sales_log() {
		int today_money;
		today_money = this->money->get_today_money() - 100000; //Get �Լ��� Money���� ���� ���� ���� ���� 

		(this->sales_log).insert({ today, today_money }); //��¥�� ���� ���� Sales_Log�� �ֱ�
		cout << "���� �α� ������Ʈ �Ϸ�" << endl;
	}

	//��¥ Key�� �ش� ���� ���� ��ȸ
	void account_management::find_sales_log(int date) {
		if (this->sales_log.find(date) != this->sales_log.end()) {
			cout << date << " ������ ����: " << (this->sales_log).find(date)->second << endl; //Map ��� ���� ���� ã��
			cout << "======================== ���� ������ ��ȸ �Ϸ� ===========================" << endl;
			cout << endl;
			cout << endl;
		}
		else {
			cout << "���� ����� ã�� �� �����ϴ�." << endl;
			cout << "======================== ���� ������ ��ȸ ���� ===========================" << endl;
			cout << endl;
			cout << endl;
		}
	}

	//Run �Լ�
	void account_management::account_run() {
		cout << endl;
		cout << "���Ͻô� �޴��� ������ �ּ���." << endl;
		cout << "===================================================" << endl;
		cout << "           1. ���� ����	     2 : ���� ��ȸ" << endl;
		cout << "===================================================" << endl;
		cout << endl;
		int menu_choice;
		cout << "�Է� (�Է� ����: 1) : ";
		cin >> menu_choice;
		if (menu_choice == 1)
		{
			cout << endl;
			cout << endl;
			cout << "======================== ���� ���� ===========================" << endl;
			cout << "���� ������ �����Ͻðڽ��ϱ�? (Y / N) ";
			char answer;
			cin >> answer;
			if ((answer == 'Y') || (answer == 'y'))
			{
				this->dayclose(); //���� �ջ� + ��� + Money �ʱ�ȭ
				today += 1; //��¥ +1
				cout << "���� ������ �Ϸ�Ǿ����ϴ�. ���� ��¥�� ����˴ϴ�." << endl;
				cout << "======================== ���� ���� �Ϸ� ===========================" << endl;
				cout << endl;
				cout << endl;
				
			}
			else if ((answer == 'N') || (answer == 'n')) {
				cout << "���� ������ ����մϴ�." << endl;
				cout << "======================== ���� ���� ��� ===========================" << endl;
				cout << endl;
				cout << endl;
			}
		}
		else if (menu_choice == 2)
		{	
			cout << "���� ������ ��ȸ�Ͻðڽ��ϱ�? (Y / N)" << endl;
			char answer;
			cin >> answer;
			if ((answer == 'Y') || (answer == 'y'))
			{
				cout << endl;
				cout << endl;
				cout << "======================== ���� ������ ��ȸ ���� ===========================" << endl;
				cout << "��ȸ�� ��¥�� �Է��� �ּ���. (�Է� ���� : YYYYMMDD)";
				int key_date;
				cin >> key_date;//��ȸ�ϰ��� �ϴ� ��¥ �Է�
				this->find_sales_log(key_date);
			}
			else if ((answer == 'N') || (answer == 'n')) {
				cout << "���� ��ȸ�� ����մϴ�." << endl;
				cout << "======================== ���� ������ ��ȸ ��� ===========================" << endl;
				cout << endl;
				cout << endl;
			}
		}
	}

	// ȯ���ؾ� �ϴ� �� �ݾ� �ٽ� ����ؼ� �� �뿡�� ����
	void account_management::refund(order* refund_order) {
		int refund_money, refund_payment_type;
		refund_money = refund_order->get_payment(); //ȯ�� ����� �� �ݾ�
		refund_payment_type = refund_order->get_payment_type(); //ȯ�� ����� ���� ����
		money->minus(refund_money, refund_payment_type); //ȯ���ؾ� �ϴ� �ݾ� ��ŭ ����
	}

	//���� �� ���ϱ�
	void account_management::purchase_pay(int received_money, bool payment_type) {
		money->plus(received_money, payment_type);
	}

	//�Ž��� �� ����
	void account_management::calculate_change(int change) {
		money->minus(change, false);
	}
}