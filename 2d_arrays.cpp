#include <iostream>

int random_int(const int min, const int max) {
	return rand() % (max - min + 1) + min;
}

void print_line(int count, char sign) {
	for (int _ = 0; _ < count; _++)
	{
		std::cout << sign;
	}
	std::cout << '\n';
}

void d_arrays() {
	

	/*int sum = 0;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			sum += array[i][j];
		}
	}

	std::cout << "Sum: " << sum << '\n'
		<< "Mean: " << (float)sum / (rows * cols) << '\n';

	int min, max;
	min = max = array[0][0];

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (array[i][j] < min) {
				min = array[i][j];
			}
			if (array[i][j] > max) {
				max = array[i][j];
			}
		}
	}

	std::cout << "Min: " << min << '\n'
		<< "Max: " << max << '\n';*/

	//const size_t rows = 3;
	//const size_t cols = 3;
	//const int array[rows][cols] = {
	//	{ 1, 2, 3 },
	//	{ 4, 5, 6 },
	//	{ 7, 8, 9 }
	//};

	/*int col_sums[cols]{ 0 };

	for (size_t row = 0; row < rows; row++)
	{
		int sum = 0;
		for (size_t col = 0; col < cols; col++)
		{
			std::cout << array[row][col] << ' ';
			sum += array[row][col];
			col_sums[col] += array[row][col];
		}
		std::cout << " | " << sum << '\n';
	}

	print_line(cols * 4, '-');

	int sum = 0;
	for (size_t col = 0; col < cols; col++)
	{
		std::cout << col_sums[col] << ' ';
		sum += col_sums[col];
	}
	std::cout << " | " << sum << '\n';*/

	/*const size_t rows1 = 5;
	const size_t cols1 = 10;
	int array1[rows1][cols1];

	for (size_t i = 0; i < rows1; i++)
	{
		for (size_t j = 0; j < cols1; j++) {
			array1[i][j] = random_int(0, 50);
			std::cout << array1[i][j] << ' ';
		}
		std::cout << '\n';
	}

	

	const size_t rows2 = rows1;
	const size_t cols2 = cols1/2;
	int array2[rows2][cols2]{};

	for (size_t i = 0; i < rows2; i++)
	{
		for (size_t j = 0; j < cols1; j+=2) {
			array2[i][j/2] = array1[i][j] + array1[i][j + 1];
		}
	}

	for (size_t i = 0; i < rows2; i++)
	{
		for (size_t j = 0; j < cols2; j++) {
			std::cout << array2[i][j] << ' ';
		}
		std::cout << '\n';
	}*/

	/*const size_t rows = 3;
	const size_t cols = 4;
	int array[rows][cols] {};

	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			std::cin >> array[row][col];
		}
	}

	int array_trans[cols][rows] {};

	for (size_t col = 0; col < cols; col++) {
		for (size_t row = 0; row < rows; row++) {
			array_trans[col][row] = array[row][col];
			std::cout << array_trans[col][row] << ' ';
		}
		std::cout << '\n';
	}*/

	/*const size_t rows = 5;
	const size_t cols = 4;
	int array[rows][cols]{};

	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			array[row][col] = rand() % 10;
			std::cout << array[row][col] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	for (size_t i = 0; i < rows / 2 + 1; i++) {
		for (size_t col = i; col < cols - i; col++) {
			std::cout << array[i][col] << ' ';
		}
		std::cout << ' ';

		for (size_t row = 1 + i; row < rows - i; row++) {
			std::cout << array[row][cols - 1 - i] << ' ';
		}
		std::cout << ' ';

		for (size_t col = cols - 1 - i; col > i; col--) {
			std::cout << array[rows - 1 - i][col - 1] << ' ';
		}
		std::cout << ' ';

		for (size_t row = rows - 1 - i; row > i + 1; row--) {
			std::cout << array[row - 1][i] << ' ';
		}
		std::cout << '\n';
	}*/
	/*for (size_t row = 0; row <= rows / 2; row++) {
		for (size_t col = row; col < cols - row; col++) {
			std::cout << array[row][col] << ' ';
		}
		for (size_t row_i = row; row_i < rows - row; row_i++) {
			std::cout << array[row_i][rows - row - 1] << ' ';
		}
		for (size_t col_i = rows - row - 1; col_i > row; col_i--) {
			std::cout << array[rows - row - 1][col_i] << ' ';
		}
		for (size_t row_i = rows - row - 1; row_i > row; row_i--) {
			std::cout << array[row_i][row] << ' ';
		}
	}*/

	// pastebin.com/igSWzJpW

	const size_t rows = 5;
	const size_t cols = 4;
	int array[rows][cols]{};

	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			array[row][col] = rand() % 10;
			std::cout << array[row][col] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	// право
	for (size_t row = 0; row < rows; row++) {
		int number = array[row][0];
		for (size_t col = 0; col < cols - 1; col++) {
			array[row][col] = array[row][col + 1];
		}
		array[row][cols - 1] = number;
	}

	// лево
	for (size_t row = 0; row < rows; row++) {
		int number = array[row][cols - 1];
		for (size_t col = 0; col < cols - 1; col++) {
			array[row][cols - col - 1] = array[row][cols - col - 2];
		}
		array[row][0] = number;
	}

	// низ
	for (size_t col = 0; col < cols; col++) {
		int number = array[rows - 1][col];
		for (size_t row = 0; row < rows - 1; row++) {
			array[rows - row - 1][col] = array[rows - row - 2][col];
		}
		array[0][col] = number;
	}

	// верх
	for (size_t col = 0; col < cols; col++) {
		int number = array[0][col];
		for (size_t row = 0; row < rows - 1; row++) {
			array[row][col] = array[row + 1][col];
		}
		array[rows - 1][col] = number;
	}

	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			std::cout << array[row][col] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
