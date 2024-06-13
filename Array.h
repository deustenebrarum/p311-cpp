#pragma once
#include <stdexcept>

template <typename T>
class Array {
private:
	T* data_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
public:
	Array() = default;

	Array(const size_t capacity) {
		data_ = new T[capacity];
		this->capacity_ = capacity;
	}

	Array(std::initializer_list<T> list) {
		capacity_ = list.size();
		size_ = 0;
		data_ = new T[capacity_];
		for (const T* ptr = list.begin(); ptr != list.end(); ptr++) {
			append(*ptr);
		}
	}

	~Array() {
		delete[] data_;
	}

	const size_t& size() const {
		return size_;
	}

	const size_t& capacity() const {
		return capacity_;
	}

	size_t set_size(size_t new_size) {
		size_ = new_size;
		return size_;
	}

	T& operator[](const size_t index) { 
		return get(index); 
	}

	const T& operator[](const size_t index) const {
		return get(index);
	}

	T& get(const size_t index) {
		if (index >= size_) {
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	const T& get(const size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	T pop(size_t index) {
		T value = get(index);
		for (size_t i = index; i < size_ - 1; i++) {
			get(i) = get(i + 1);
		}
		size_--;

		return value;
	}

	void clear() {
		delete[] data_;
		data_ = nullptr;
		size_ = 0;
		capacity_ = 0;
	}

	void reallocate(size_t new_capacity) {
		T* new_data = new T[new_capacity];

		capacity_ = new_capacity;

		size_ = size_ < new_capacity ? size_ : new_capacity;

		for (size_t i = 0; i < size_; i++) {
			new_data[i] = get(i);
		}

		delete[] data_;
		data_ = new_data;
	}

	void extend_memory() {
		reallocate(capacity_ == 0 ? 2 : capacity_ * 2);
	}

	void append(T value) {
		if (size_ >= capacity_) {
			extend_memory();
		}

		data_[size_] = value;
		size_++;
	}

	void extend(const Array<T>& other) {
		for (size_t i = 0; i < other.size_; i++) {
			append(get(other, i));
		}
	}

	void insert(size_t index, T value) {
		if (index == size_) {
			append(value);
			return;
		}

		if (size_ >= capacity_) {
			extend_memory();
		}

		for (size_t i = size_; i > index; i--) {
			get(i) = get(i - 1);
		}
		
		get(index) = value;
		size_++;
	}

	Array<T> copy() {
		Array<T> other = Array<T>(*this);
		other.data_ = new T[capacity_];
		
		for (size_t i = 0; i < size_; i++) {
			other.data_[i] = data_[i];
		}

		return other;
	}
};


