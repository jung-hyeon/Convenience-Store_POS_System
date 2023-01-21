#include "purchase_management.h"

namespace pos {

	//setter of management pointer

	void purchase_management::set_stock_management(pos::stock_management* stock_management) {

		this->stock_management = stock_management;
	}
	void purchase_management::set_account_management(pos::account_management* account_management) {

		this->account_management = account_management;
	}
	void purchase_management::set_order_management(pos::order_management* order_management) {

		this->order_management = order_management;
	}

	//�޴� �����ִ� �Լ�
	void purchase_management::show_menu() {

		cout << "=======================================================" << endl;
		cout << "                       ��ǰ ���         " << endl;
		stock_management->show_item_menu();
		cout << "=======================================================" << endl;
	}

	//�Է°� purchase_item_name(�����ϰ��� �ϴ� ��ǰ �̸�)���� �����ϴ� �޼���

	string purchase_management::get_purchase_item_name() {
		string temp_purchase_item_name;
		cin >> temp_purchase_item_name;

		return temp_purchase_item_name;
	}


	//�Է°� purchase_item_count(�����ϰ��� �ϴ� ��ǰ�� ����)���� �����ϴ� �Լ�

	int purchase_management::get_purchase_item_count() {

		int temp_purchase_item_count;
		cin >> temp_purchase_item_count;
		return temp_purchase_item_count;
	}


	//�ǸŸ� ���� �� �۵� �Լ�
	void purchase_management::purchase_run() {
		cout << endl;
		shopping_cart cart; // ������ ��ǰ ���

		int age = 0;                              //�մ� ���� �޾ƿͼ� ����
		int coupon = 0;                           //�մԿ��Լ� ���� ���ΰ� �޾ƿ�
		int total_order_price = 0;                //�����ϴ� ��ǰ �� ����
		int change = 0;   //�Ž�����
		int paid_money = 0; //�մ��� ������ ������ �ݾ�
		int payment = 0; // total_order_price - coupon 
		bool payment_type;

		this->show_menu();                        //�޴� ������
		cout << endl;
		cout << endl;
		cout << "========================== ���� ���� ===========================" << endl;

		cout << "�մ��� ���̸� �Է����ּ���: (�Է� ���� : 20) : ";     //�մ� ���� ���
		cin >> age;                                 // age�� �մ� ���� ����


		put_in_shopping_cart(cart);  //�ֹ��� ���� �� : ������ item���� �ޱ� + item�� shopping_cart�� ��� + shopping_cart�� order.management�� ������

		total_order_price = cart.get_cart_total_price();

		cout << endl;
		cout << "������ �����մϴ�." << endl;
		cout << "������ �ִٸ� ���ΰ��� �Է��ϼ��� (�Է� ���� : 500, ���ٸ� 0�Է�) : ";
		cin >> coupon;// coupon�� ���ΰ� ����

		payment = total_order_price - coupon;

		cout << "�� " << payment << "�� �Դϴ�." << endl;

		cout << "���� ����� �������ּ��� (0: ī�� 1: ����) : ";
		cin >> payment_type;

		if (payment_type == false) {
			paid_money = payment; //ī���̹Ƿ� �ݾ� �� ����
			cout << paid_money << "�� ���� �Ϸ�." << endl;
		}
		else {
			cout << "�մԿ��� ���� �ݾ��� �Է��ϼ���. (�Է� ����: 20000) : " << endl;
			cin >> paid_money;
			change = paid_money - payment;
			cout << payment << "�� ���� �Ϸ�." << endl;
			cout << "�Ž��� ���� " << change << "�� �Դϴ�." << endl;
			this->account_management->calculate_change(change);
		}

		this->purchase_pay(paid_money, payment_type); // account_management�� payment�� payment_type �����ϴ� ���� �޼���

		order_management->order_run(cart, coupon, payment, age, change, payment_type);
		cout << "========================== ���� �Ϸ� ===========================" << endl;
		cout << endl;
		cout << endl;
	}

	//�ֹ� ������ �޾ƿͼ� shopping_cart���� 
	//�Է°��� 0�϶� shopping_cart ���� ����!
	void purchase_management::put_in_shopping_cart(shopping_cart& cart) {

		string purchase_item_name = ""; //��ǰ�̸�
		int purchase_item_count = 0;   //�ش� ��ǰ ����
		cart_item* my_item;   //stock_management���� ���� item ��ü �޾Ƽ� �����Ұ���, ���� shopping cart�� �Ѱ��ٰ�


		while (1) {

			//1.�մ����κ��� �ֹ� ������ ������
			cout << endl;
			cout << "���� ��ǰ ����� �����Ͽ� ������ ��ǰ�� �ϳ��� �Է����ּ���." << endl;
			cout << "(�Է� ����: banana, ���ٸ� 0�Է�)(�� ���� �� ������ ��ǰ�� �Է��ϼ���.) :  ";
			cin >> purchase_item_name;

			if ((purchase_item_name.compare("0")) == 0) {
				cout << "��ٱ��Ͽ� ������ ��ǰ�� ��� �߰��Ǿ����ϴ�.";
				break;
			}
			cout << "������ ��ǰ�� ������ �Է��ϼ���. (�Է� ����: 1) : ";
			cin >> purchase_item_count;

			//2-1.stock management�κ��� item ��ü ������ �����Ͽ� cart_item �ڷ������� �޾ƿ���
			my_item = stock_management->item_pop(purchase_item_name, purchase_item_count);

			//2-2.�޾ƿ� cart_item �ڷ��� ��ü�� shopping cart�� ���
			cart.add_item(my_item);
			cout << "����īƮ�� ��ǰ�� �����ϴ�." << endl;
			cout << endl;
		}

		//shopping_cart�� ��ü�� order_management���� �ֹ� ���� �Ѱ���
		//���� order_management�� order�� �����Ͽ� order_log�� log_array�� ����

	}

	//�����ϴ� ���� -> account_management�� �����Ͽ� ���� ������Ŵ 
	void purchase_management::purchase_pay(int payment, bool payment_type) {

		this->account_management->purchase_pay(payment, payment_type);
	}


}
