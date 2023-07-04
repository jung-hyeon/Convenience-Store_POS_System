#include "stock_management.h"

namespace pos {

	//Public method
	//item_llist_management 객체 setter
	void stock_management::set_item_list_management(pos::item_list_management* item_list_management) {
		this->item_list_management = item_list_management;
	}

	//환불시 shopping_cart에 담겨있던 물품을 다시 item_list에 push
	void stock_management::item_push(cart_item* cart_item) {
		this->item_list_management->item_push(cart_item);
	}

	//구매시 item의 이름과 수량만큼 item_list에서 pop
	cart_item* stock_management::item_pop(string name, int num) {
		return this->item_list_management->item_pop(name, num);
	}

	//재고를 직접 추가
	void stock_management::add_item(string name) {
		this->item_list_management->add_item(name);
	}

	//상품 폐기처리
	void stock_management::item_disposal() {
		this->item_list_management->item_disposal();
	}

	//환불 상품 재고에 다시 추가
	void stock_management::refund(order* refund_order) {
		shopping_cart cart = refund_order->get_shopping_cart();
		int count = cart.get_cart_total_count();

		list<cart_item*>::iterator it;
		it = cart.get_cart_list().begin();
		for (int i = 0; i < count; i++) {
			this->item_push(*it);
		}
	}

	//item_list에 담겨있는 모든 item의 이름 출력
	void stock_management::show_item_menu() {
		this->item_list_management->show_item_menu();
	}

	//재고관리 기능 실행
	bool stock_management::stock_run() {
		cout << endl;
		char answer;
		while (true) {
			cout << "재고를 추가하시겠습니까? (Y / N) ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				while (true) {
					string name;
					cout << endl;
					cout << endl;
					cout << "============================ 재고 추가 시작 ==============================" << endl;
					cout << "추가할 상품의 이름을 입력해주세요. (입력 예시: banana, 더이상 추가할 상품이 없을 경우 0입력) ";
					cin >> name;
					if (name.compare("0") == 0) break;
					this->add_item(name);
					cout << "============================ 재고 추가 완료 ===============================" << endl;
					cout << endl;
					cout << endl;
				}
			}
			else {
				cout << "재고를 추가하지 않습니다." << endl;
				cout << "============================ 재고 추가 취소 ===============================" << endl;
				cout << endl;
				cout << endl;
				break;
			}
		}
		return true;
	}
}