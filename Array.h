#pragma once

template <typename T>
struct Array {
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;
};

template <typename T>
T& get(Array<T>& array, const size_t index) {
	if (index >= array.size) {
		throw std::out_of_range("Index out of range");
	}

	return array.data[index];
}

template <typename T>
const T& get(const Array<T>& array, const size_t index) {
	if (index >= array.size) {
		throw std::out_of_range("Index out of range");
	}

	return array.data[index];
}

template <typename T>
void print(Array<T>& array) {
	for (size_t i = 0; i < array.size; i++) {
		std::cout << get(array, i) << ' ';
	}
	std::cout << '\n';
}

template <typename T>
void print_specific(const Array<T>& array) {
	for (size_t i = 0; i < array.size; i++) {
		print(get(array, i));
	}
	std::cout << '\n';
}

template <typename T>
T pop(Array<T>& array, size_t index) {
	T value = get(array, index);
	for (size_t i = index; i < array.size - 1; i++) {
		get(array, i) = get(array, i + 1);
	}
	array.size--;

	return value;
}

template <typename T>
void append(Array<T>& array, T value) {
	if (array.size >= array.capacity) {
		array.capacity = array.capacity == 0 ? 2 : array.capacity * 2;
		T* new_data = new T[array.capacity];

		for (size_t i = 0; i < array.size; i++) {
			new_data[i] = get(array, i);
		}
		delete[] array.data;
		array.data = new_data;
	}
	
	array.data[array.size] = value;
	array.size++;
}
