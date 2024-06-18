#include <iostream>
#include "Array.h"

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

class Animal {
public:
	void makeSound() {
		std::cout << species_ << " says " << sound_ << '\n';
	}

	Animal(const char* species, const char* sound) {
		species_ = species;
		sound_ = sound;
		std::cout << species_ << " is created\n";
	}
private:
	const char* species_;
	const char* sound_;
};

class Bonk {
public:
	Bonk(int lifetime) {
		lifetime_left_ = lifetime;
		saturation_ = 0;
	}

	void feed(int amount) {
		saturation_ += amount;
		if (saturation_ > saturation_max) {
			saturation_ = saturation_max;
		}
	}

	void attack(Bonk& other) {
		const int damage = 5;

		set_lifetime_left(lifetime_left() - damage);

		other.set_lifetime_left(other.lifetime_left() - damage * 2);

		other.feed(damage * 2);
	}

	int lifetime_left() {
		return lifetime_left_;
	}

	bool is_dead() {
		return lifetime_left_ <= 0;
	}
private:
	void regenerate() {
		saturation_ /= 2;
		set_lifetime_left(lifetime_left() + saturation_);
	}

	int set_lifetime_left(int lifetime) {
		lifetime_left_ = lifetime;

		if (lifetime_left_ < 0) {
			lifetime_left_ = 0;
		}
		
		return lifetime_left_;
	}

	int lifetime_left_;
	int saturation_;
	const int saturation_max = 100;
};

void bonks_example() {
	Bonk alesha(100);
	Bonk vasenka(100);

	for (size_t i = 0; i < 9; i++)
	{
		alesha.attack(vasenka);

	}

	std::cout << vasenka.is_dead() << '\n';
}
