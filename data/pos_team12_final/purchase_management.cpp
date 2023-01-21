#include "purchase_management.h"

namespace pos {

	//setter of management pointer

	void purchase_management::set_stock_management(pos::stock_management* stock_management) {

		this->stock_management = stock_management;
	}
	void purchase_management::set_account_management(pos::account_management* account_management) {

		this->account_management = account_management;
	}
	void purchase_management::set_order_management(pos::order_management* order_management) {

		this->order_management = order_management;
	}

	//메뉴 보여주는 함수
	void purchase_management::show_menu() {

		cout << "=======================================================" << endl;
		cout << "                       상품 목록         " << endl;
		stock_management->show_item_menu();
		cout << "=======================================================" << endl;
	}

	//입력값 purchase_item_name(구매하고자 하는 상품 이름)으로 저장하는 메서드

	string purchase_management::get_purchase_item_name() {
		string temp_purchase_item_name;
		cin >> temp_purchase_item_name;

		return temp_purchase_item_name;
	}


	//입력값 purchase_item_count(구매하고자 하는 상품의 개수)으로 저장하는 함수

	int purchase_management::get_purchase_item_count() {

		int temp_purchase_item_count;
		cin >> temp_purchase_item_count;
		return temp_purchase_item_count;
	}


	//판매를 위한 주 작동 함수
	void purchase_management::purchase_run() {
		cout << endl;
		shopping_cart cart; // 구매할 상품 목록

		int age = 0;                              //손님 나이 받아와서 저장
		int coupon = 0;                           //손님에게서 쿠폰 할인가 받아옴
		int total_order_price = 0;                //구매하는 상품 총 가격
		int change = 0;   //거스름돈
		int paid_money = 0; //손님이 실제로 지불한 금액
		int payment = 0; // total_order_price - coupon 
		bool payment_type;

		this->show_menu();                        //메뉴 보여줌
		cout << endl;
		cout << endl;
		cout << "========================== 구매 시작 ===========================" << endl;

		cout << "손님의 나이를 입력해주세요: (입력 예시 : 20) : ";     //손님 나이 물어봄
		cin >> age;                                 // age에 손님 나이 저장


		put_in_shopping_cart(cart);  //주문에 대한 것 : 구매할 item정보 받기 + item을 shopping_cart에 담기 + shopping_cart를 order.management로 보내기

		total_order_price = cart.get_cart_total_price();

		cout << endl;
		cout << "결제를 시작합니다." << endl;
		cout << "쿠폰이 있다면 할인가를 입력하세요 (입력 예시 : 500, 없다면 0입력) : ";
		cin >> coupon;// coupon에 할인가 저장

		payment = total_order_price - coupon;

		cout << "총 " << payment << "원 입니다." << endl;

		cout << "결제 방식을 선택해주세요 (0: 카드 1: 현금) : ";
		cin >> payment_type;

		if (payment_type == false) {
			paid_money = payment; //카드이므로 금액 딱 맞춤
			cout << paid_money << "원 결제 완료." << endl;
		}
		else {
			cout << "손님에게 받은 금액을 입력하세요. (입력 예시: 20000) : " << endl;
			cin >> paid_money;
			change = paid_money - payment;
			cout << payment << "원 결제 완료." << endl;
			cout << "거스름 돈은 " << change << "원 입니다." << endl;
			this->account_management->calculate_change(change);
		}

		this->purchase_pay(paid_money, payment_type); // account_management에 payment와 payment_type 전달하는 내부 메서드

		order_management->order_run(cart, coupon, payment, age, change, payment_type);
		cout << "========================== 구매 완료 ===========================" << endl;
		cout << endl;
		cout << endl;
	}

	//주문 정보를 받아와서 shopping_cart생성 
	//입력값이 0일때 shopping_cart 생성 종료!
	void purchase_management::put_in_shopping_cart(shopping_cart& cart) {

		string purchase_item_name = ""; //상품이름
		int purchase_item_count = 0;   //해당 상품 개수
		cart_item* my_item;   //stock_management에서 실제 item 객체 받아서 저장할거임, 이후 shopping cart에 넘겨줄거


		while (1) {

			//1.손님으로부터 주문 정보를 가져옴
			cout << endl;
			cout << "위의 상품 목록을 참고하여 구매할 상품을 하나씩 입력해주세요." << endl;
			cout << "(입력 예시: banana, 없다면 0입력)(한 번에 한 종류의 상품만 입력하세요.) :  ";
			cin >> purchase_item_name;

			if ((purchase_item_name.compare("0")) == 0) {
				cout << "장바구니에 구매할 상품이 모두 추가되었습니다.";
				break;
			}
			cout << "구매할 상품의 개수를 입력하세요. (입력 예시: 1) : ";
			cin >> purchase_item_count;

			//2-1.stock management로부터 item 객체 정보를 복사하여 cart_item 자료형으로 받아오기
			my_item = stock_management->item_pop(purchase_item_name, purchase_item_count);

			//2-2.받아온 cart_item 자료형 객체를 shopping cart에 담기
			cart.add_item(my_item);
			cout << "쇼핑카트에 상품이 담겼습니다." << endl;
			cout << endl;
		}

		//shopping_cart의 객체를 order_management에게 주문 정보 넘겨줌
		//이후 order_management는 order를 생성하여 order_log의 log_array에 넣음

	}

	//결제하는 과정 -> account_management에 접근하여 매출 증가시킴 
	void purchase_management::purchase_pay(int payment, bool payment_type) {

		this->account_management->purchase_pay(payment, payment_type);
	}


}
