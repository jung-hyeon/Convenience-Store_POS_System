#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
namespace pos {

	class money {
	private:
		int card_money; //ī��
		int cash; //����
		int today_money; //���� ����
		int capital; //�� �ں���

	public:
		//constructor
		money();
		//destructor
		~money();

		void set_card_money(int); //ī�� Set
		void set_cash(int); // ���� Set
		void set_capital(int); //�ں��� Set
		int get_today_money(); //���� ���� Get
		int get_capital(); //�ں��� Get
		void calculate_day_revenue(); //���� ����
		void plus(int, bool); //���� ���� �� ���
		void minus(int, bool); //���� �� �� ���
	};
} //���� Clean Up