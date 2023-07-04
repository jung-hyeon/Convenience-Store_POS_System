#include "item_list_management.h"
#include <sstream>

namespace pos {
	//Public method

	//item_llist_management 객체 setter
	void item_list_management::set_item_list(pos::item_list& item_list) {
		this->item_list = &item_list;
	}

	//item_list에 물품 추가
	void item_list_management::item_push(cart_item* cart_item) {
		this->item_list->item_push(cart_item);
	}

	//item_list에 물품 추가
	void item_list_management::item_push(string name, list<int>& item_array) {
		this->item_list->item_push(name, item_array);
	}

	//item_list에 물품 추가
	void item_list_management::item_push(abstract_item* new_item) {
		this->item_list->item_push(new_item);
	}

	//item_list에서 물품 꺼냄
	cart_item* item_list_management::item_pop(string name, int count) {
		return this->item_list->item_pop(name, count);
	}

	// 문자열을 공복을 기준으로 잘라 int형 배열로 반환
	list<int> item_list_management::string_to_listint(string st) {
		istringstream ss(st);
		string strBuffer;
		list<int> identifier_list;
		//ss에는 문자열 버퍼에 구분자(' ')로 자르고 남은 문자열이 저장됨
		while (getline(ss, strBuffer, ' ')) {
			identifier_list.push_back(stoi(strBuffer));
		}
		//
		list<int>::iterator it; //반복자 선언

		for (it = identifier_list.begin(); it != identifier_list.end(); it++) {
			//it이 li.begin()을 가리킴, it이 li.end()를 가리키지 않을때까지 반복, it가 다음것을 가리킴
			printf("%d ", *it); //원소 접근은 *it을 이용
		}
		//
		return identifier_list;
	}

	// item_list에 name과 이름이 동일한 상품이 존재하는지 판단
	bool item_list_management::is_exist_item(string name) {
		return this->item_list->is_exist_item(name);
	}

	// 상품 입고
	void item_list_management::add_item(string name) {
		//이미 존재하면 item정보만 update
		if (this->is_exist_item(name)) {
			this->add_exist_item(name);
		}
		//존재하지 않으면 새로 item 만들어서 item_list에 push
		else {
			this->create_new_item(name);
		}
	}

	// 상품 입고시 item_list에 이미 존재하는 item인 경우, 각 상품의 고유 정보(유통기한, 보증기한 등)를 받아서 item에 추가
	void item_list_management::add_exist_item(string name) {
		int count;
		string identifier;
		cout << name << "의 개수를 입력하세요. (입력 예시: 1) ";		//count 수만큼 반복문 돌리기
		cin >> count;
		cout << name << " " << count << "개의 " << "유통 기한 또는 품질 보증 기한을 입력하세요. (입력 예시: 20221219 20221219 20221224)" << endl;
		cout << "(유통 기한이 같을 경우에도 각각 입력, 입력 후 Enter)" << endl;
		cin >> identifier;

		// 고유 정보 배열을 item에 push
		list<int> identifier_list = this->string_to_listint(identifier);
		this->item_push(name, identifier_list);

		cout << "상품이 추가되었습니다." << endl;
	}

	// 상품 입고시 item_list에 존재하지 않는 item인 경우, item을 모든 정보를 받아 새로 생성한 후, item_list에 추가
	void item_list_management::create_new_item(string name) {
		int price, count;				//상품의 가격과 갯수
		char is_over_19;				//19세 이상 판매 상품여부를 묻는 변수
		int identifier;				//고유 정보

		cout << name << "은(는) 19세 미만 판매금지 상품입니까? (Y / N) ";
		cin >> is_over_19;

		cout << name << "의 가격을 입력하세요. (입력 예시: 2000) ";
		cin >> price;

		cout << name << "의 개수를 입력하세요. (입력 예시: 3) ";		//count 수만큼 반복문 돌리기
		cin >> count;

		cout << name << "의 고유 정보는 무엇입니까? (1. 유통 기한 2. 보증 기한) (입력 예시: 1) ";
		cin >> identifier;
		if (identifier == 1) {
			int ex_date;
			list<int> ex_date_list;
			cout << name << " "<< count << "개의 "<< "유통 기한을 입력하세요. (유통 기한이 같을 경우에도 각각 입력)" << endl;
			cout << "(입력 예시: 20221219 20221219 20221224)(입력 후 Enter)" << endl;
			for (int i = 1; i <= count; i++) {
				cin >> ex_date;
				ex_date_list.push_back(ex_date);
			}

			item_with_exdate* new_item = new item_with_exdate;
			new_item->set_name(name);
			new_item->set_price(price);
			new_item->set_is_over_19(is_over_19);
			new_item->set_identifier_array(ex_date_list);
			this->item_push(new_item);
		}
		else if (identifier == 2) {
			int guarantee;
			list<int> guarantee_list;
			cout << name << " " << count << "개의 " << "품질 보증 기한을 입력하세요. (품질 보증 기한이 같을 경우에도 각각 입력)" << endl;
			cout << "(입력 예시: 20301219 20301219 20301224)(입력 후 Enter)" << endl;

			for (int i = 1; i <= count; i++) {
				cin >> guarantee;
				guarantee_list.push_back(guarantee);
			}

			item_with_guarantee* new_item = new item_with_guarantee;
			new_item->set_name(name);
			new_item->set_price(price);
			new_item->set_is_over_19(is_over_19);
			new_item->set_identifier_array(guarantee_list);
			this->item_push(new_item);
			new_item->set_total_count(count);
		}
		cout << "상품이 추가되었습니다." << endl;
	}

	//item_list에 존재하는 item 중 폐기 조건에 맞는 item 폐기
	void item_list_management::item_disposal() {
		this->item_list->item_disposal();
	}

	//item_list에 존재하는 item 목록 나열
	void item_list_management::show_item_menu() {
		this->item_list->show_item_menu();
	}
}