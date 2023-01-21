#include "item_list.h"

namespace pos {
	// Constructor
	item_list::item_list() {
		this->item_count = 0;
	}

	// Destructor: itee_list내의 item_array에 담긴 item 객체들 delete
	item_list::~item_list() {
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;

		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++) {
			item = *iter;
			delete(item);
		}
	}

	// Public method

	// 받은 수량만큼 total_count 업데이트
	void item_list::update_item_count(int update_count) {
		this->item_count += update_count;
	}

	// 현재 item에 존재하는 수량 다시 세려서 total_count 업데이트
	void item_list::update_item_count() {
		int total_item_count = 0;
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			total_item_count += item->get_total_count();
		}
		this->item_count = total_item_count;
	}

	// name 받아서 이름이 동일한 item 반환
	abstract_item* item_list::search_item(string name) {
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item = NULL;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			if (item->get_name() == name) break;
		}
		return item;
	}

	// 상품 추가
	void item_list::item_push(cart_item* cart_item) {
		abstract_item* item = search_item(cart_item->get_name());
		// cart_item 내부 상품들 item에 넣은 후 정렬
		item->get_identifier_array().merge(cart_item->get_identifier_array());
		item->get_identifier_array().sort();
		// 상품 수량 변경
		item->update_total_count(cart_item->get_total_count());
		this->update_item_count(cart_item->get_total_count());

		delete(cart_item);
	}

	// 상품 추가
	void item_list::item_push(string name, list<int>& identifier_array) {
		abstract_item* item = search_item(name);
		item->get_identifier_array().merge(identifier_array);
		item->update_total_count();
	}

	// 상품 추가
	void item_list::item_push(abstract_item* new_item) {
		this->item_array.push_back(new_item);
		new_item->update_total_count();
	}

	// list_item에서 name이 동일한 item 찾아 받은 수량만큼 pop
	cart_item* item_list::item_pop(string name, int count) {
		abstract_item* item = search_item(name);
		// cart item 생성
		cart_item* my_cart = new cart_item;
		my_cart->set_name(item->get_name());
		my_cart->set_price(item->get_price());
		my_cart->set_total_count(count);
		my_cart->set_is_over_19(item->get_is_over_19());
		// cart item에 상품 담기
		for (int item_count = 0; item_count < count; item_count++) {
			my_cart->get_identifier_array().push_back(item->item_pop());
		}
		// 변동 수량 update
		item->update_total_count(-count);
		this->update_item_count(-count);

		return my_cart;
	}

	// name과 동일한 item 존재여부 판단
	bool item_list::is_exist_item(string name) {
		bool exist = false;
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;

		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			if (item->get_name() == name) {
				exist = true;
				break;
			}
		}
		return exist;
	}

	// 폐기 조건에 맞는 item 폐기 (예: 유통기한 있는 item은 오늘날짜와 비교해 폐기, guarantee 있는 item은 오늘날짜보다 5년 이사 지났으면 폐기)
	void item_list::item_disposal() {
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			item = *iter;
			item->item_disposal();
		}
		this->update_item_count();
	}

	// item_list 내부에 있는 모든 item 이름 출력
	void item_list::show_item_menu() {
		// 반복자 생성 
		list<abstract_item*>::iterator iter = this->item_array.begin();
		abstract_item* item;
		int count = 0;
		for (iter = this->item_array.begin(); iter != this->item_array.end(); iter++)
		{
			count = ++count;
			item = *iter;
			cout << count << ". " << item->get_name() << "	" << "가격: " << item->get_price() << "	" << "남은 수량: " << item->get_total_count() << endl;
		}
	}
}