#include <iostream>

struct Array {
	int* data;
	size_t size;
	size_t capacity;
};

int& get(Array& array, const size_t index) {
	if (index >= array.size) {
		throw std::out_of_range("Index out of range");
	}
	return array.data[index];
}

void print(const Array& array) {
	for (size_t i = 0; i < array.size; i++) {
		std::cout << array.data[i] << ' ';
	}
	std::cout << '\n';
}

void pop(Array& array, const size_t index) {
	if (index >= array.size) {
		throw std::out_of_range("Index out of range");
	}

	for (size_t i = index; i < array.size - 1; i++) {
		array.data[i] = array.data[i + 1];
	}

	array.size--;
}

void append(Array& array, const int value) {
	if (array.size >= array.capacity) {
		array.capacity = array.capacity != 0 ? array.capacity * 2 : 2;
		array.data = (int*)realloc(
			array.data, array.capacity * sizeof(int)
		);
	}
	array.data[array.size] = value;
	array.size++;
}

int main() {
	Array array{};

	append(array, 1);
	append(array, 2);
	append(array, 3);

	print(array);

	delete[] array.data;
}

