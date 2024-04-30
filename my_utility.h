#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>

template <typename T>
int* concat(
	const int array1[], const size_t size1,
	const int array2[], const size_t size2
) {
	const size_t size3 = size1 + size2;
	int* array3 = new int[size3] {};

	for (size_t i = 0; i < size1; ++i) {
		array3[i] = array1[i];
	}

	for (size_t i = 0; i < size2; ++i) {
		array3[i + size1] = array2[i];
	}

	return array3;
}

void print(int array[], const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

void bubble_sort(int array[], const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		bool is_sorted = true;
		for (size_t j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				is_sorted = false;
				// то же самое std::swap(array[j], array[j + 1]);
			}
		}
		if (is_sorted) break;
	}
}

void insertion_sort(int array[], const size_t size) {
	for (size_t i = 1; i < size; i++)
	{
		for (size_t j = i; j > 0 && array[j - 1] > array[j]; j--) {
			std::swap(array[j], array[j - 1]);
		}
	}
}

bool has(
	const int array[],
	const size_t size,
	const int value
) {
	for (size_t i = 0; i < size; ++i) {
		if (array[i] == value) return true;
	}
	return false;
}

void generate_random_values(
	int array[],
	const size_t size,
	const int min,
	const int max
) {
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % (max - min) + min;
	}
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

template <typename T, typename TResult>
TResult* map(
	TResult (*transform)(T),
	const T* array,
	const size_t size
) {
	TResult* result = new TResult[size];

	for (size_t i = 0; i < size; i++)
	{
		result[i] = transform(array[i]);
	}

	return result;
}

template <typename T1, typename T2>
std::pair<T1, T2>* zip(
	const T1* array1,
	const T2* array2,
	const size_t size
) {
	auto result = new std::pair<int, int>[size];

	for (size_t i = 0; i < size; i++)
	{
		result[i] = { array1[i], array2[i] };
	}

	return result;
}

#endif
