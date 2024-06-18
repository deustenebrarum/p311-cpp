#include <iostream>
#include "Array.h"

struct Meabeab {
	int weight;
	const char* name;
};

void print(Meabeab meabeab) {
	std::cout << meabeab.name << ' ' << meabeab.weight << '\n';
}

void print(Array<Meabeab>& meabeabs) {
	for (size_t i = 0; i < meabeabs.size(); i++)
	{
		std::cout << meabeabs[i].name << ' ' 
			<< meabeabs[i].weight << '\n';
	}
}

void add_meabeab(Array<Meabeab>& meabeabs) {
	Meabeab new_meabeab;
	std::cin >> new_meabeab.weight;
	new_meabeab.name = "meabebab";
	meabeabs.append(new_meabeab);
}

void find_by_weight(Array<Meabeab>& meabeabs) {
	int weight;
	std::cin >> weight;
	for (size_t i = 0; i < meabeabs.size(); i++)
	{
		if (meabeabs[i].weight == weight)
		{
			print(meabeabs[i]);
		}
	}
}

int main() {
	Array<Meabeab> array(10);
	for (size_t i = 0; i < 3; i++)
	{
		add_meabeab(array);
	}

	find_by_weight(array);
}
