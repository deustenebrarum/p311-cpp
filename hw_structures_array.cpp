#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

struct Meabeab {
	int weight;
	const char* name;
};

int main() {
	std::vector<Meabeab> vec;

	vec.push_back(Meabeab{
		2, "alesha"
	});
	vec.push_back(Meabeab{
		9, "petya"
	});
	vec.push_back(Meabeab{
		4, "petuh"
	});
	vec.push_back(Meabeab{
		7, "citer"
	});

	vec.erase(vec.begin() + 2);

	

	std::sort(vec.begin(), vec.end(), 
		[&vec](const Meabeab& left, const Meabeab& right) {
			return left.weight < right.weight;
		}
	);

	std::vector<std::reference_wrapper<Meabeab>> selected_meabeabs;
	selected_meabeabs.reserve(vec.size());

	std::copy_if(
		vec.begin(),
		vec.end(),
		std::back_inserter(selected_meabeabs),
		[](const Meabeab& item) { return strstr(item.name, "t"); }
	);

	for (size_t i = 0; i < selected_meabeabs.size(); i++) {
		std::cout << i + 1 << selected_meabeabs[i].get().name << ' ';
	}
}
