#include "abstract_item.h"

namespace pos {
	// Constructor
	abstract_item::abstract_item() {
		this->name = "";
		this->price = 0;
		this->total_count = 0;
		this->is_over_19 = false;
	}

	// Destructor
	abstract_item::~abstract_item() {}
}