#include <iostream>
#include "my_utility.h"

bool is_even(int number) {
	return number % 2 == 0;
}

void transform(
	int* array, size_t size,
	int (*function)(int number)
) {
	for (size_t i = 0; i < size; i++)
	{
		array[i] = function(array[i]);
	}
}

int sqr(int number) {
	return number * number;
}

int cube(int number) {
	return number * number * number;
}

int main() {
	const size_t size = 5;
	std::cout << "Enter 5 numbers: ";
	int array[size];

	for (size_t i = 0; i < size; i++) {
		std::cin >> array[i];
	}

	int (*functions[2])(int) = { sqr, cube };
	
	std::cout << "1 - square all,\n2 - cube all\n";

	int choice;
	std::cin >> choice;

	transform(array, size, functions[choice - 1]);

	print(array, size);
}
