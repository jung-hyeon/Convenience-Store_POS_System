#include "account_management.h"
extern int today;

namespace pos {
	//Stock Management 객체 Setter
	void account_management::set_stock_management(pos::stock_management& stock_management) {
		this->stock_management = &stock_management;
	}

	void account_management::set_money(pos::money& money) {
		this->money = &money;
	}

	//마감 정산
	void account_management::dayclose() {
		this->money->calculate_day_revenue(); //매출 합산 실행
		this->stock_management->item_disposal(); //Stock Management에 폐기 전달
		push_sales_log(); //날짜와 매출 Push
		this->money->set_card_money(0); //카드 매출 초기화
		this->money->set_cash(this->ready_money); //현금 통 초기화
		int new_capital;
		new_capital = this->money->get_capital() - this->ready_money;
		this->money->set_capital(new_capital); //현금 통 채운 만큼 자본금에서 제하기
	}

	//정산 할 때 기록 추가
	void account_management::push_sales_log() {
		int today_money;
		today_money = this->money->get_today_money() - 100000; //Get 함수로 Money에서 일일 매출 가져 오기 

		(this->sales_log).insert({ today, today_money }); //날짜랑 일일 매출 Sales_Log에 넣기
		cout << "매출 로그 업데이트 완료" << endl;
	}

	//날짜 Key로 해당 일자 매출 조회
	void account_management::find_sales_log(int date) {
		if (this->sales_log.find(date) != this->sales_log.end()) {
			cout << date << " 일자의 매출: " << (this->sales_log).find(date)->second << endl; //Map 기능 통해 매출 찾기
			cout << "======================== 일일 매출을 조회 완료 ===========================" << endl;
			cout << endl;
			cout << endl;
		}
		else {
			cout << "매출 기록을 찾을 수 없습니다." << endl;
			cout << "======================== 일일 매출을 조회 실패 ===========================" << endl;
			cout << endl;
			cout << endl;
		}
	}

	//Run 함수
	void account_management::account_run() {
		cout << endl;
		cout << "원하시는 메뉴를 선택해 주세요." << endl;
		cout << "===================================================" << endl;
		cout << "           1. 마감 정산	     2 : 매출 조회" << endl;
		cout << "===================================================" << endl;
		cout << endl;
		int menu_choice;
		cout << "입력 (입력 예시: 1) : ";
		cin >> menu_choice;
		if (menu_choice == 1)
		{
			cout << endl;
			cout << endl;
			cout << "======================== 마감 정산 ===========================" << endl;
			cout << "마감 정산을 시작하시겠습니까? (Y / N) ";
			char answer;
			cin >> answer;
			if ((answer == 'Y') || (answer == 'y'))
			{
				this->dayclose(); //매출 합산 + 폐기 + Money 초기화
				today += 1; //날짜 +1
				cout << "마감 정산이 완료되었습니다. 오늘 날짜가 변경됩니다." << endl;
				cout << "======================== 마감 정산 완료 ===========================" << endl;
				cout << endl;
				cout << endl;
				
			}
			else if ((answer == 'N') || (answer == 'n')) {
				cout << "마감 정산을 취소합니다." << endl;
				cout << "======================== 마감 정산 취소 ===========================" << endl;
				cout << endl;
				cout << endl;
			}
		}
		else if (menu_choice == 2)
		{	
			cout << "일일 매출을 조회하시겠습니까? (Y / N)" << endl;
			char answer;
			cin >> answer;
			if ((answer == 'Y') || (answer == 'y'))
			{
				cout << endl;
				cout << endl;
				cout << "======================== 일일 매출을 조회 시작 ===========================" << endl;
				cout << "조회할 날짜를 입력해 주세요. (입력 예시 : YYYYMMDD)";
				int key_date;
				cin >> key_date;//조회하고자 하는 날짜 입력
				this->find_sales_log(key_date);
			}
			else if ((answer == 'N') || (answer == 'n')) {
				cout << "매출 조회를 취소합니다." << endl;
				cout << "======================== 일일 매출을 조회 취소 ===========================" << endl;
				cout << endl;
				cout << endl;
			}
		}
	}

	// 환불해야 하는 총 금액 다시 계산해서 돈 통에서 빼기
	void account_management::refund(order* refund_order) {
		int refund_money, refund_payment_type;
		refund_money = refund_order->get_payment(); //환불 기록의 총 금액
		refund_payment_type = refund_order->get_payment_type(); //환불 기록의 결제 수단
		money->minus(refund_money, refund_payment_type); //환불해야 하는 금액 만큼 차감
	}

	//받은 돈 더하기
	void account_management::purchase_pay(int received_money, bool payment_type) {
		money->plus(received_money, payment_type);
	}

	//거스름 돈 빼기
	void account_management::calculate_change(int change) {
		money->minus(change, false);
	}
}