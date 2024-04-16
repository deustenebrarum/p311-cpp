#include <iostream>
#include <vector>

int main() {
	// pastebin.com/7FGWcVDF
	size_t size = 0;
	std::cin >> size;

	int* a = new int[size] {};

	for (size_t i = 0; i < size; i++) {
		std::cin >> a[i];
	}

	int sum = 0;

	for (size_t i = 0; i < size; i++) {
		sum += *(a + i);
	}

	std::cout << sum << '\n';

	delete[] a;
}
