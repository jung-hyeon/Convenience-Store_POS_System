#include "refund_management.h"

namespace pos {
	//Stock Management 객체 Setter
	void refund_management::set_stock_management(pos::stock_management& stock_management) {
		this->stock_management = &stock_management;
	}
	//Account Management 객체 Setter
	void refund_management::set_account_management(pos::account_management& account_management) {
		this->account_management = &account_management;
	}
	//Order Management 객체 Setter
	void refund_management::set_order_management(pos::order_management& order_management) {
		this->order_management = &order_management;
	}

	void refund_management::refund_run() {
		cout << endl;
		order* refund_order = NULL;
		cout << "환불을 진행하시겠습니까? (부분 환불은 가능하지 않습니다.) (Y / N)";
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << endl;
			cout << endl;
			cout << "============================ 환불 시작 ==============================" << endl;
			cout << "환불 영수증 번호를 입력해 주세요. (입력 예시: 0)";
			int refund_order_id; 
			cin >> refund_order_id;
			refund_order = this->order_management->pop_order_log(refund_order_id); //Order Management 통해 영수증 번호 조회하기 위해 Null 포인터 매개 변수 보냄.
			if ( refund_order == NULL) //My Order가 그대로 Null이면 실패
			{
				cout << "존재하지 않는 영수증 번호입니다." << endl;
				cout << "============================ 환불 실패 ==============================" << endl;
				cout << endl;
				cout << endl;
			}
			else { //My Order가 주소 값을 가져 오면 성공
				cout << "내역 조회에 성공했습니다. 환불을 진행합니다." << endl;
				this->stock_management->refund(refund_order); //Stock Management에서 환불 진행
				this->account_management->refund(refund_order); //Account Management에서 환불 진행
				cout << "환불을 성공했습니다." << endl;
				cout << "============================ 환불 종료 ==============================" << endl;
				cout << endl;
				cout << endl;
			}
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "환불 절차를 취소합니다." << endl;
			cout << "============================ 환불 취소 ==============================" << endl;
			cout << endl;
			cout << endl;
		}
	}
}