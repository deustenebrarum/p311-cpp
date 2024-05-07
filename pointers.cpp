//#include <iostream>
//#include "my_utility.h"
//
//int* concatenate(
//	const int* array1, const size_t size1,
//	const int* array2, const size_t size2
//) {
//	int* result = new int[size1 + size2];
//
//	for (size_t i = 0; i < size1; i++)
//	{
//		result[i] = array1[i];
//	}
//	for (size_t i = 0; i < size2; i++)
//	{
//		result[i + size1] = array2[i];
//	}
//
//	return result;
//}
//
//int sum(int aa, int b) {
//	return aa + b;
//}
//
//int sub(int a, int b) {
//	return a - b;
//}
//
//void pointers_example() {
//	int (*operation[2]) (int, int) { sum, sub };
//
//	std::cout << operation[1](1, 2);
//}

//bool has(
//	int array[],
//	const size_t size,
//	const int value
//) {
//	for (size_t i = 0; i < size; ++i) {
//		if (array[i] == value) return true;
//	}
//	return false;
//}
//
//std::pair<int*, size_t> distinct_concat(
//	int array1[], const size_t size1,
//	int array2[], const size_t size2
//) {
//	const size_t size3 = size1 + size2;
//	int* array3 = new int[size3] {};
//
//	size_t array3_count = 0;
//
//	for (size_t i = 0; i < size1; ++i) {
//		if (!has(array3, size3, array1[i])) {
//			array3[array3_count] = array1[i];
//			++array3_count;
//		}
//	}
//
//	for (size_t i = 0; i < size2; ++i) {
//		if (!has(array3, size3, array2[i])) {
//			array3[array3_count] = array2[i];
//			++array3_count;
//		}
//	}
//
//	return { array3, array3_count };
//}
//
//void filter_print(
//	bool (*predicate)(int),
//	int array[], 
//	const size_t size
//) {
//	for (size_t i = 0; i < size; ++i) {
//		if (predicate(array[i])) {
//			std::cout << array[i] << " ";
//		}
//	}
//}
//
//bool is_even(int value) {
//	return value % 2 == 0;
//}
//
//bool is_odd(int value) {
//	return value % 2 != 0;
//}
//
//void main_pointers_() {
//	size_t size1 = 0;
//	std::cin >> size1;
//	int* array1 = new int[size1]{};
//	for (size_t i = 0; i < size1; ++i) {
//		std::cin >> array1[i];
//	}
//	std::cout << is_even;
//	filter_print(is_odd, array1, size1);
//
//	//size_t size2 = 0;
//	//std::cin >> size2;
//	//int* array2 = new int[size2]{};
//	//for (size_t i = 0; i < size2; ++i) {
//	//	std::cin >> array2[i];
//	//}
//
//	//std::pair<int*, size_t> array3_sized = distinct_concat(
//	//	array1, size1,
//	//	array2, size2
//	//);
//
//	//int* array3 = array3_sized.first;
//	//size_t size3 = array3_sized.second;
//
//	//print(array3, size3);
//	//delete[] array1;
//	//delete[] array2;
//	//delete[] array3;
//}
