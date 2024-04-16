#define _USE_MATH_DEFINES

#include <iostream>
#include <Windows.h>
#include "utility.h"

int binary_to_decimal(int binary) {
	int result = 0;

	for (int mul = 1; binary > 0; mul *= 2) {
		result += binary % 10 * mul;
		binary /= 10;
	}

	return result;
}

void pyramid_print(int array[], const size_t size);

void sort(
	int array[], const size_t size,
	const bool is_descending = false,
	const size_t start_index = 0
) {
	for (size_t _ = 0; _ < size - start_index; _++)
	{
		for (size_t i = start_index; i < size - 1; i++)
		{
			bool is_lesser = array[i] > array[i + 1];
			if (is_descending) is_lesser = array[i] < array[i + 1];

			if (is_lesser) {
				std::swap(array[i], array[i + 1]);
				system("cls");
				pyramid_print(array, size);
				Sleep(50);
			}
		}
	}
}

void generate_random_values(
	int array[], const size_t size,
	const int min, const int max
) {
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

#include <algorithm>
void sort_between_negative_edges(
	int array[], const size_t size
) {
	size_t left_edge = 0;
	for (; 
		left_edge < size && array[left_edge] >= 0; 
		left_edge++
	);

	size_t right_edge = size;
	for (; 
		right_edge > 0 && array[left_edge - 1] >= 0;
		right_edge--
	);

	sort(array, right_edge, false, left_edge + 1);
}

void functions_main() {
	const size_t size = 20;
	int array[size];
	generate_random_values(array, size, -20, 20);

	print(array, size);
	sort_between_negative_edges(array, size);

	print(array, size);
}

void print_line_(int count, char sign) {
	for (int _ = 0; _ < count; _++)
	{
		std::cout << sign << ' ';
	}
	std::cout << '\n';
}

void pyramid_print(int array[], const size_t size) {
	for (size_t i = 0; i < size; i++) {
		print_line_(array[i], '=');
	}
}

void reverse(int array[], size_t from, size_t to) {
	for (size_t i = from, j = to - 1; i < j; i++, j--) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

size_t find_max(int array[], size_t from, size_t to) {
	size_t max_index = 0;

	for (size_t i = from; i < to; i++) {
		if (array[i] > array[i + 1]) {
			max_index = i;
		}
	}

	return max_index;
}

void pancake_sort(
	int array[],
	size_t size
) {
	for (size_t i = 0; i < size; i++)
	{
		size_t max_index = find_max(array, i, size);

		reverse(array, max_index, size);
		system("cls");
		pyramid_print(array, size);
		Sleep(80);
		reverse(array, i, size);
		system("cls");
		pyramid_print(array, size);
		Sleep(80);
	}
}

void print_sorts() {
	int array[25]{ 1, 20, 17, 5, 22, 8, 1, 13, 2, 15 };

	generate_random_values(array, 25, 0, 30);

	pancake_sort(array, 25);
}

float mean(const int array[], const size_t size) {
	int sum = 0;

	for (size_t i = 0; i < size; i++) {
		sum += array[i];
	}

	return (float)sum / size;
}

bool isLeap(const int year) {
	return (
		year % 4 == 0 &&
		year % 100 != 0 ||
		year % 400 == 0
	);
}

int get_days_in_month(const int month, const int year) {
	if (month == 2 && isLeap(year)) return 29;

	const int days_in_month[] = { 
		31, 28, 31, 30, 31, 30, 31, 
		31, 30, 31, 30, 31 
	};
	
	return days_in_month[month - 1];
}

int get_date_diff_in_days(
	const int day1, const int month1, const int year1,
	const int day2, const int month2, const int year2
) {
	// 02.05.2020 - 17.04.2023
	// days = 31 - 2 + 17
	int days = get_days_in_month(month1, year1) - day1 + day2;

	// days + get_days_in_month(06, 2020)
	// ...
	// days + get_days_in_month(12, 2020)
	for (int cur_month = month1 + 1; cur_month <= 12; cur_month++) {
		days += get_days_in_month(
			cur_month, year1
		);
	}

	// days + get_days_in_month(01, 2021)
	// ...
	// days + get_days_in_month(12, 2022)
	for (int cur_year = year1 + 1; cur_year < year2; cur_year++) {
		for (int cur_month = 1; cur_month <= 12; cur_month++) {
			days += get_days_in_month(
				cur_month, cur_year
			);
		}
	}

	// days + get_days_in_month(01, 2023)
	// ...
	// days + get_days_in_month(03, 2023)
	for (int cur_month = 1; cur_month < month2; cur_month++) {
		days += get_days_in_month(
			cur_month, year2
		);
	}

	return days;
}

void print_rect(int width, int height, char sign) {
	for (int _ = 0; _ < height; _++)
	{
		print_line_(width, sign);
	}
}

int factorial(int number) {
	int result = 1;

	for (int i = 1; i <= number; i++)
	{
		result *= i;
	}

	return result;
}

int get_greater(int number1, int number2) {
	if (number1 > number2)
	{
		return number1;
	}

	return number2;
}

bool is_positive(int number) {
	return number > 0;
}

bool is_prime(uint64_t number) {
	uint64_t root = sqrt(number);
	for (uint64_t i = 2; i <= root; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

void aadad() {	
	for (uint64_t i = 1000000000000000; i < 10000000000000000; i++)
	{
		if (is_prime(i)) std::cout << i << '\n';
	}
}
