#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
namespace pos {

	class money {
	private:
		int card_money; //카드
		int cash; //현금
		int today_money; //일일 매출
		int capital; //총 자본금

	public:
		//constructor
		money();
		//destructor
		~money();

		void set_card_money(int); //카드 Set
		void set_cash(int); // 현금 Set
		void set_capital(int); //자본금 Set
		int get_today_money(); //일일 매출 Get
		int get_capital(); //자본금 Get
		void calculate_day_revenue(); //일일 정산
		void plus(int, bool); //돈을 더할 때 사용
		void minus(int, bool); //돈을 뺄 때 사용
	};
} //형식 Clean Up