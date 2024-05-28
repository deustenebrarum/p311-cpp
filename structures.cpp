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

int main() {
	const size_t size = 3;
	Car cars[size];
	for (size_t i = 0; i < size; i++)
	{
		cars[i].distance = 0;
		cars[i].speed = 1 + rand() % 3;
	}

	for (size_t _ = 0; _ < 20; _++) {
		system("cls");
		for (size_t i = 0; i < size; i++)
		{
			std::cout << i << '.';
			Car_Print(cars[i]);
			cars[i].distance += cars[i].speed;
			cars[i].speed = 1 + rand() % 3;
		}
		Sleep(500);
	}
}