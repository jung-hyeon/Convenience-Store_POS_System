#pragma once
#include <string>
#include <list>
#include "abstract_item.h"
using namespace std;

namespace pos {
	class item_with_guarantee : public abstract_item {
	protected:
		// Protected property
		std::string name;
		int price;
		int total_count;
		bool is_over_19;
		list<int> identifier_array;

	public:
		// Constructor & Destructor
		item_with_guarantee();
		virtual ~item_with_guarantee();

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

		// ���� ������ŭ total_count ������Ʈ
		virtual void update_total_count();
		// ���� item�� �����ϴ� ���� �ٽ� ������ total_count ������Ʈ
		virtual void update_total_count(int);

		// ���� item�� �����ϴ� ��� ���ǿ� �´� �͵� ���
		virtual void item_disposal();
		// ���� ������ item pop & pick
		virtual int item_pop();
	};
}