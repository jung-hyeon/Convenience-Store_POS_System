#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

namespace pos {
	class cart_item {
	protected:
		// Protected property
		std::string name;
		int price;
		int total_count;
		bool is_over_19;
		list<int> identifier_array;

	public:
		// Constructor & Destructor
		cart_item();
		~cart_item();

		// Public method
		std::string get_name();
		int get_price();
		int get_total_count();
		bool get_is_over_19();
		list<int> get_identifier_array();

		void set_name(std::string);
		void set_price(int);
		void set_total_count(int);
		void set_is_over_19(char);
	};
}