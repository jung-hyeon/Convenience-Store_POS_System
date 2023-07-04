#pragma once
#include <iostream>
#include <string>
#include <map>
#include "money.h"
#include "order_management.h"
#include "order.h"
#include "stock_management.h"


using namespace std;
namespace pos {

	class account_management {
	private:
		map<int, int> sales_log; //���� ���� ����ϴ� Map
		const int ready_money = 100000; //�غ��
		money* money; //Money ���� ������
		stock_management* stock_management; //Stock Management ���� ������
		void dayclose(); //���� ����
		void push_sales_log(); //���� �� �� ��� �߰�
		void find_sales_log(int date); //��¥ Key�� �ش� ���� ���� ��ȸ

	public:
		void set_stock_management(pos::stock_management&); //Account Management ��ü Setter
		void set_money(pos::money&); //Money ��ü Setter
		void account_run(); //Run �Լ�
		void refund(order*); // ȯ���ؾ� �ϴ� �� �ݾ� �ٽ� ����ؼ� �� �뿡�� ����
		void purchase_pay(int, bool); //���� �� ���ϱ�
		void calculate_change(int); //�Ž��� �� ����
	};
}