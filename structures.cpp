#include <iostream>
#include <Windows.h>

struct Worker {
	char name[32]{};
	char position[32]{};
	int salary = 0;
};

void workers_example() {
	size_t length = 0;
	std::cin >> length;
	Worker* workers = new Worker[length];

	for (size_t i = 0; i < length; i++)
	{
		std::cin >> workers[i].name;
		std::cin >> workers[i].position;
		std::cin >> workers[i].salary;
	}

	int programmers_salary = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (strcmp(workers[i].position, "programmer") == 0) {
			std::cout << workers[i].name << '\n';
			programmers_salary += workers[i].salary;
		}
	}
}

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

void run_game(
	Car* cars,
	size_t size,
	const int distance
) {
	for (size_t _ = 0; _ < distance; _++) {
		print_field(cars, size);
		update_cars(cars, size);
		Sleep(500);
	}
}

void cars2_lightning_mcqueen() {
	std::ios::sync_with_stdio(false);

	const size_t size = 10;
	Car cars[size];
	
	initialize_field(cars, size);

	run_game(cars, size, 100);
}

struct Mashinka {
	int speed;
	char view_symbol;
	int track_position;
};

int rand_int(int min, int max) {
	return min + rand() % (max - min + 1);
}


Mashinka* generate_mashinkas(
	size_t mashinkas_count,
	int speed_min,
	int speed_max
) {
	const char* symbols_variants = "qigktumnakz";

	Mashinka* mashinkas = new Mashinka[mashinkas_count];

	for (size_t i = 0; i < mashinkas_count; i++)
	{
		mashinkas[i].speed = rand_int(speed_min, speed_max);
		mashinkas[i].view_symbol = symbols_variants[
			rand_int(0, strlen(symbols_variants) - 1)
		];
		mashinkas[i].track_position = 0;
	}

	return mashinkas;
}

int get_average_speed(
	const Mashinka* mashinkas,
	size_t mashinkas_count
) {
	int sum = 0;

	for (size_t i = 0; i < mashinkas_count; i++)
	{
		sum += mashinkas[i].speed;
	}

	return sum / mashinkas_count;
}

void update_mashinkas(
	Mashinka* mashinkas, 
	size_t mashinkas_count,
	int average_speed
) {
	for (size_t i = 0; i < mashinkas_count; i++)
	{
		mashinkas[i].track_position += mashinkas[i].speed;
		mashinkas[i].speed = (
			average_speed - 
			rand_int(-average_speed / 2, average_speed / 2)
		);
		if (mashinkas[i].speed < 1)
		{
			mashinkas[i].speed = 1;
		}
	}
}

void show_mashinka_track(
	const Mashinka& mashinka,
	const int destination
) {
	for (int i = 0; i < destination; i++)
	{
		if (i == mashinka.track_position)
		{
			std::cout << mashinka.view_symbol;
			continue;
		}

		std::cout << ' ';
	}
	std::cout << '|' << '\n';
}

void show_track(
	const Mashinka* mashinkas, 
	size_t mashinkas_count,
	const int destination
) {
	system("cls");
	for (size_t i = 0; i < mashinkas_count; i++)
	{
		std::cout << i + 1 << (i + 1 < 10 ? " " : "") << '.';
		show_mashinka_track(mashinkas[i], destination);
	}
}

int car_tracks() {
	srand(time(NULL));
	const size_t mashinkas_count = 10;
	Mashinka* mashinkas = generate_mashinkas(
		mashinkas_count, 1, 3
	);

	const int destination = 50;
	int average_speed = get_average_speed(mashinkas, mashinkas_count);

	show_track(mashinkas, mashinkas_count, destination);
	Sleep(5000);

	for (size_t _ = 0; _ < 25; _++)
	{
		update_mashinkas(mashinkas, mashinkas_count, average_speed);
		show_track(mashinkas, mashinkas_count, destination);
		Sleep(1000);
	}

	return 0;
}
