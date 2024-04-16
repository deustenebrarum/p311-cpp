#include <iostream>
#include <vector>
#include <algorithm>
// найти позицию конкретного 
// значения в массиве

void array_div_numbers() {
	const size_t size1 = 5;
	int arr1[size1]{ 1,-6,0,4,6 };

	const size_t size2 = 5;
	int arr2[size2]{ -16,0,57,-43,62 };

	const size_t size3 = size1 + size2;
	int arr3[size3]{ 0 };

	size_t cursor = 0;

	for (size_t i = 0; i < size1; ++i) {
		if (arr1[i] > 0) {
			arr3[cursor] = arr1[i];
			cursor++;
		}
		if (arr2[i] > 0) {
			arr3[cursor] = arr2[i];
			cursor++;
		}
	}

	for (size_t i = 0; i < size1; ++i) {
		if (arr1[i] == 0) {
			arr3[cursor] = arr1[i];
			cursor++;
		}
		if (arr2[i] == 0) {
			arr3[cursor] = arr2[i];
			cursor++;
		}
	}

	for (size_t i = 0; i < size1; ++i) {
		if (arr1[i] < 0) {
			arr3[cursor] = arr1[i];
			cursor++;
		}
		if (arr2[i] < 0) {
			arr3[cursor] = arr2[i];
			cursor++;
		}
	}
}