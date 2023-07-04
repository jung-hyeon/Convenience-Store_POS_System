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
		map<int, int> sales_log; //일일 매출 기록하는 Map
		const int ready_money = 100000; //준비금
		money* money; //Money 접근 포인터
		stock_management* stock_management; //Stock Management 접근 포인터
		void dayclose(); //마감 정산
		void push_sales_log(); //정산 할 때 기록 추가
		void find_sales_log(int date); //날짜 Key로 해당 일자 매출 조회

	public:
		void set_stock_management(pos::stock_management&); //Account Management 객체 Setter
		void set_money(pos::money&); //Money 객체 Setter
		void account_run(); //Run 함수
		void refund(order*); // 환불해야 하는 총 금액 다시 계산해서 돈 통에서 빼기
		void purchase_pay(int, bool); //받은 돈 더하기
		void calculate_change(int); //거스름 돈 빼기
	};
}