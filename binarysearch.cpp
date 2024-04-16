#include <cstdint>
#include <iostream>

void binarysearch() {
    // »нициализаци€ генератора случайных чисел
    srand(time(NULL));

    // «адание размера массива
    const size_t size = 20;
    // —оздание и инициализаци€ массива нул€ми
    int array[size]{};

    // «аполнение массива случайными значени€ми
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100 + 100 * i;
    }

    // ¬ывод массива на экран
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // »нициализаци€ переменных дл€ поиска числа в массиве
    size_t left = 0;
    size_t right = size - 1;
    size_t middle;

    // ¬вод числа, которое нужно найти в массиве
    int number = 0;
    std::cin >> number;

    // ѕоиск числа в отсортированном массиве методом бинарного поиска
    while (left <= right) {
        // Ќаходим средний индекс элемента в текущем диапазоне
        middle = (left + right) / 2;
        // ≈сли значение в среднем элементе равно искомому числу, то завершаем поиск
        if (array[middle] == number) break;

        // ≈сли значение в среднем элементе меньше искомого числа, сдвигаем левую границу поиска
        if (array[middle] < number) {
            left = middle + 1;
        }
        // »наче сдвигаем правую границу поиска
        else {
            right = middle - 1;
        }
    }

    // ѕровер€ем, было ли найдено число
    if (left > right) {
        // ¬ыводим сообщение, что число не найдено
        std::cout << "Number not found";
    }
    else {
        // ¬ыводим индекс числа в массиве (результат поиска)
        std::cout << middle;
    }
}
