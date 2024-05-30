#include <iostream>
#include <Windows.h>

struct Car {
	int speed;
	int distance;
};

void Car_Print(const Car& car) {
	for (size_t i = 0; i < car.distance; i++)
	{
		std::cout << ' ';
	}
	std::cout << "=\n";
}

void print_field(const Car* cars, size_t size) {
	system("cls");
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i + 1 << '.';
		Car_Print(cars[i]);
	}
}

void update_cars(Car* cars, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cars[i].distance += cars[i].speed;
		cars[i].speed = 1 + rand() % 3;
	}
}

void initialize_field(Car* cars, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cars[i].distance = 0;
		cars[i].speed = 1 + rand() % 3;
	}
}

void run_game(Car* cars, size_t size) {
	for (size_t _ = 0; _ < 20; _++) {
		print_field(cars, size);
		update_cars(cars, size);
		Sleep(500);
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	const size_t size = 10;
	Car cars[size];
	
	initialize_field(cars, size);

	run_game(cars, size);
}