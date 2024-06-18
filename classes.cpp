#include <iostream>

struct Point {
	int x;
	int y;
};

class Square {
public:
	Square(Point position, int size) {
		position_ = position;
		size_ = size;
	}

	Square() = delete;

	int area() {
		return size_ * size_;
	}

	const int& size() {
		return size_;
	}

	void print() {
		for (size_t i = 0; i < position_.y; i++)
		{
			std::cout << '\n';
		}
		for (size_t i = 0; i < size(); i++)
		{
			for (size_t j = 0; j < position_.x; j++) {
				std::cout << "  ";
			}
			for (size_t j = 0; j < size(); j++) {
				std::cout << "# ";
			}
			std::cout << '\n';
		}
	}
private:
	Point position_;
	int size_;
};

int main() {
	Square sqr(Point{ 10,1 }, 2);

	sqr.print();
}
