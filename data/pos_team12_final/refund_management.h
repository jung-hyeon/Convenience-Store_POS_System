#pragma once
#include <iostream>
#include <string>
#include <map>
#include "account_management.h"
#include "stock_management.h"
#include "order_management.h"


using namespace std;
namespace pos {

	class refund_management {
	private:
		stock_management* stock_management; //Stock Management�� �����ϱ� ���� ������
		account_management* account_management; //Account Management�� �����ϱ� ���� ������
		order_management* order_management; //Order Management�� �����ϱ� ���� ������

	public:
		void set_stock_management(pos::stock_management&); //Stock Management ��ü Setter
		void set_account_management(pos::account_management&); //Account Management ��ü Setter
		void set_order_management(pos::order_management&); //Order Management ��ü Setter
		void refund_run();
	};
}