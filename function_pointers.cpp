#include <iostream>
#include "my_utility.h"

int max(
	const int* array,
	const size_t size
) {
	int max_value = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > max_value) {
			max_value = array[i];
		}
	}

	return max_value;
}

int min(
	const int* array,
	const size_t size
) {
	int min_value = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (array[i] < min_value) {
			min_value = array[i];
		}
	}

	return min_value;
}

int average(
	const int* array,
	const size_t size
) {
	int sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += array[i];
	}

	return sum / size;
}

int main() {
	int array[5]{ 1,2,5,-5,3 };

	int (*actions[3])(const int*, const size_t) {
		min, max, average
	};
	
	std::cout << "1) min\n"
		<< "2) max\n"
		<< "3) average\n";

	int choice;
	std::cin >> choice;

	std::cout << actions[choice - 1](array, 5);
}
