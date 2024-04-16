#include <iostream>

int get_power(int number, int power) {
	if (power == 0) return 1;

	return number * get_power(number, power - 1);
}

int fucktorial(int number) {
	if (number < 1) {
		throw std::invalid_argument("Number cannot be not positive");
	}
	if (number == 1) return 1;

    return number * fucktorial(number - 1);
}

void printLine(int count, char sign) {
	if (count == 0) return;

	std::cout << sign;
	printLine(count - 1, sign);
}

int sum_range(int start, int end) {
	if (start > end) {
		throw std::invalid_argument("Start cannot be bigger than end");
	}
	if (start == end) return start;

	return start + sum_range(start + 1, end);
}

int sum(const int array[], const size_t size) {
	if (size == 0) return 0;

	return array[size - 1] + sum(array, size - 1);
}

int max(int number1, int number2) {
	return number1 > number2 ? number1 : number2;
}

float max(float number1, float number2) {
	return number1 > number2 ? number1 : number2;
}

int max(const int array[], const size_t size) {
	if (size == 1) return array[0];

	return max(array[size - 1], max(array, size - 1));
}


void what_sum_recursiveXDXDXD() {
	int arr[3]{ 1, 2, 3 };

	std::cout << sum(arr, 3) << '\n';
}

// pastebin.com/7mH1buqP