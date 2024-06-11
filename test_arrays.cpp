#include <iostream>
#include <stdexcept>
#include "Array.h"

int test_arrays() {
	Array<int> array {};

	append(array, 1);
	append(array, 4);
	append(array, 5);

	get(array, 1) = 8;

	pop(array, 0);

	print(array);

	delete[] array.data;

	return 0;
}

