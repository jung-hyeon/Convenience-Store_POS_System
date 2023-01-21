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
		stock_management* stock_management; //Stock Management에 접근하기 위한 포인터
		account_management* account_management; //Account Management에 접근하기 위한 포인터
		order_management* order_management; //Order Management에 접근하기 위한 포인터

	public:
		void set_stock_management(pos::stock_management&); //Stock Management 객체 Setter
		void set_account_management(pos::account_management&); //Account Management 객체 Setter
		void set_order_management(pos::order_management&); //Order Management 객체 Setter
		void refund_run();
	};
}