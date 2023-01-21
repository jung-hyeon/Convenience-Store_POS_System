#include "money.h"

namespace pos {

	money::money() {
		card_money = 0;
		cash = 100000; //�ʱ� �غ��
		today_money = 0;
		capital = -100000; //�ʱ⿡�� �������� �غ���� ���� �̸� 10�� ���� �� ��
	}

	money::~money() {};

	void money::set_card_money(int set_amount) { this->card_money = set_amount; }

	void money::set_cash(int set_amount) { this->cash = set_amount; }

	void money::set_capital(int set_amount) { this->capital = set_amount; }

	void money::plus(int money, bool payment_type) {
		if (payment_type == false)
			this->card_money += money; // ī�� ���� ����
		else if (payment_type == true)
			this->cash += money; // ���� ���� ����
	}

	void money::minus(int money, bool payment_type) {
		if (payment_type == false)
			this->card_money -= money; // ī�� ���� ����
		else if (payment_type == true)
			this->cash -= money; // ���� ���� ����
	}

	void money::calculate_day_revenue() {
		this->today_money = this->card_money + this->cash; //ī�� ���� �ջ�
		this->capital += this->today_money; //�ں��ݿ� �Ϸ� ���� �ջ�
	}

	int money::get_today_money() { return this->today_money; }

	int money::get_capital() { return this->capital; };
}