#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

namespace pos {
	class abstract_item {
	protected:
		// Protected property
		string name;
		int price;
		int total_count;
		bool is_over_19;
		list<int> identifier_array;

	public:
		// Constructor & Destructor
		abstract_item();
		virtual ~abstract_item();

		// Public pure virtual method
		virtual string get_name() = 0;
		virtual int get_price() = 0;
		virtual int get_total_count() = 0;
		virtual bool get_is_over_19() = 0;
		virtual list<int> get_identifier_array() = 0;

		virtual void set_name(std::string) = 0;
		virtual void set_price(int) = 0;
		virtual void set_total_count(int) = 0;
		virtual void set_is_over_19(char) = 0;
		virtual void set_identifier_array(list<int>&) = 0;

		virtual void update_total_count() = 0;
		virtual void update_total_count(int) = 0;
		virtual void item_disposal() = 0;
		virtual int item_pop() = 0;
	};
}