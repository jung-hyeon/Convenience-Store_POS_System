#pragma once
#include <iostream>
#include <string>
#include <list>
#include "item_list.h"
#include "cart_item.h"
#include "abstract_item.h"
#include "item_with_exdate.h"
#include "item_with_guarantee.h"

namespace pos {
	class item_list_management {
	private:
		//Private property
		item_list* item_list;
	public:
		//Public method
		//item_llist_management 객체 setter
		void set_item_list(pos::item_list&);
		//item_list에 물품 추가
		void item_push(cart_item*);
		//item_list에 물품 추가
		void item_push(string, list<int>&);
		//item_list에 물품 추가
		void item_push(abstract_item*);
		//item_list에서 물품 꺼냄
		cart_item* item_pop(string, int);
		// 문자열을 공복을 기준으로 잘라 int형 배열로 반환
		list<int> string_to_listint(string);
		// item_list에 name과 이름이 동일한 상품이 존재하는지 판단
		bool is_exist_item(string);
		// 상품 입고
		void add_item(string);
		// 상품 입고시 item_list에 이미 존재하는 item인 경우, 각 상품의 고유 정보(유통기한, 보증기한 등)를 받아서 item에 추가
		void add_exist_item(string);
		// 상품 입고시 item_list에 존재하지 않는 item인 경우, item을 모든 정보를 받아 새로 생성한 후, item_list에 추가
		void create_new_item(string);
		//item_list에 존재하는 item 중 폐기 조건에 맞는 item 폐기									//item_list에 존재하는 메뉴 목록을 나열함
		void item_disposal();
		//item_list에 존재하는 item 목록 나열
		void show_item_menu();
	};
}