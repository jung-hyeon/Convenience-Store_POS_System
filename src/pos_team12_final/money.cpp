#include "money.h"

namespace pos {

	money::money() {
		card_money = 0;
		cash = 100000; //초기 준비금
		today_money = 0;
		capital = -100000; //초기에는 현금으로 준비금을 빼서 미리 10만 원을 빼 둠
	}

	money::~money() {};

	void money::set_card_money(int set_amount) { this->card_money = set_amount; }

	void money::set_cash(int set_amount) { this->cash = set_amount; }

	void money::set_capital(int set_amount) { this->capital = set_amount; }

	void money::plus(int money, bool payment_type) {
		if (payment_type == false)
			this->card_money += money; // 카드 매출 증가
		else if (payment_type == true)
			this->cash += money; // 현금 매출 증가
	}

	void money::minus(int money, bool payment_type) {
		if (payment_type == false)
			this->card_money -= money; // 카드 매출 감소
		else if (payment_type == true)
			this->cash -= money; // 현금 매출 감소
	}

	void money::calculate_day_revenue() {
		this->today_money = this->card_money + this->cash; //카드 현금 합산
		this->capital += this->today_money; //자본금에 하루 매출 합산
	}

	int money::get_today_money() { return this->today_money; }

	int money::get_capital() { return this->capital; };
}