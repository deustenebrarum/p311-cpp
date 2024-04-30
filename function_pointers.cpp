#include <iostream>
#include "my_utility.h"

bool is_even(int number) {
	return number % 2 == 0;
}

int sqr(int number) {
	return number * number;
}

int cube(int number) {
	return number * number * number;
}

int sum(std::pair<int, int> pair) {
	return pair.first + pair.second;
}

int* sumEach(
	const int* array1, const int* array2,
	const size_t size
) {
	const std::pair<int, int>* pairs = zip(
		array1, array2, size
	);

	int* result = map(sum, pairs, size);

	delete[] pairs;

	return result;
}

void functional_example() {
	const size_t size = 3;
	
	int array1[size] = { 1, 2, 3 };
	int array2[size] = { 4, 5, 6 };

	int* result = sumEach(
		array1, array2, size
	);

	print(array1, size);
	print(array2, size);
	print(result, size);

	delete[] result;
}
