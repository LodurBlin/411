#include "cl_base.h"
#include <iostream>

void cl_base::add_spinogriz(std::unique_ptr <cl_base>&& spinogriz) {

	spinogriz->p_predok = this;
	spinogrizi.push_back(std::move(spinogriz));

}

void cl_base::print_hierarchy(int offset) const {
	if (offset != 0) {
		std::cout << "\n";
	}
	std::cout << std::string(offset * 4, ' ') << this->ob_name;
	for (const auto& spin : spinogrizi) {
		spin->print_hierarchy(offset + 1);
	}

}
void cl_base::detdom(cl_base* new_predok) {
	if (new_predok) {
		this->p_predok = new_predok;
		for (auto& spin : p_predok->spinogrizi) {
			if (spin.get() == this) {
				new_predok->add_spinogriz(std::move(spin));
			}
		}
	}
	else this->p_predok = 0;
}
cl_base* cl_base::kto_otez() {
	return p_predok;
}
