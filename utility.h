#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>


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
#endif
