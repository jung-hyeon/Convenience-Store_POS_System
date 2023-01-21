#pragma once
#include <string>
#include <list>
#include "abstract_item.h"
using namespace std;

namespace pos {

	class item_with_exdate : public abstract_item {
	protected:
		// Protected property
		std::string name;
		int price;
		int total_count;
		bool is_over_19;
		list<int> identifier_array;

	public:
		// Constructor & Destructor
		item_with_exdate();
		virtual ~item_with_exdate();

		// Public virtual method
		virtual std::string get_name();
		virtual int get_price();
		virtual int get_total_count();
		virtual bool get_is_over_19();
		virtual list<int> get_identifier_array();

		virtual void set_name(std::string);
		virtual void set_price(int);
		virtual void set_total_count(int);
		virtual void set_is_over_19(char);
		virtual void set_identifier_array(list<int>&);

		// 받은 수량만큼 total_count 업데이트
		virtual void update_total_count(int);
		// 현재 item에 존재하는 수량 다시 세려서 total_count 업데이트
		virtual void update_total_count();

		// 현재 item에 존재하는 폐기 조건에 맞는 것들 폐기
		virtual void item_disposal();
		// 가장 오래된 item pop & pick
		virtual int item_pop();
	};
}