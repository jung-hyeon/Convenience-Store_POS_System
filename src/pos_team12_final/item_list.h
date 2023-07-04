#pragma once
#include <iostream>
#include <string>
#include <list>
#include "abstract_item.h"
#include "cart_item.h"
using namespace std;

namespace pos {
	class item_list {
	protected:
		// Protected property
		int item_count;

	public:
		// Constructor & Destructor
		item_list();
		~item_list();

		// Public property
		list<abstract_item*> item_array;

		// Public method

		// 받은 수량만큼 total_count 업데이트
		void update_item_count(int);
		// 현재 item에 존재하는 수량 다시 세려서 total_count 업데이트
		void update_item_count();
		// name 받아서 이름이 동일한 item 반환
		abstract_item* search_item(string);
		// 상품 추가
		void item_push(cart_item*);
		// 상품 추가
		void item_push(string, list<int>&);
		// 상품 추가
		void item_push(abstract_item*);
		// list_item에서 name이 동일한 item 찾아 받은 수량만큼 pop
		cart_item* item_pop(std::string, int);
		// name과 동일한 item 존재여부 판단
		bool is_exist_item(string);
		// 폐기 조건에 맞는 item 폐기 (예: 유통기한 있는 item은 오늘날짜와 비교해 폐기, guarantee 있는 item은 오늘날짜보다 5년 이사 지났으면 폐기)
		void item_disposal();
		// item_list 내부에 있는 모든 item 이름 출력
		void show_item_menu();
	};
}