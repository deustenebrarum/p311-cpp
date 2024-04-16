#include <cstdint>
#include <iostream>

void binarysearch() {
    // ������������� ���������� ��������� �����
    srand(time(NULL));

    // ������� ������� �������
    const size_t size = 20;
    // �������� � ������������� ������� ������
    int array[size]{};

    // ���������� ������� ���������� ����������
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100 + 100 * i;
    }

    // ����� ������� �� �����
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // ������������� ���������� ��� ������ ����� � �������
    size_t left = 0;
    size_t right = size - 1;
    size_t middle;

    // ���� �����, ������� ����� ����� � �������
    int number = 0;
    std::cin >> number;

    // ����� ����� � ��������������� ������� ������� ��������� ������
    while (left <= right) {
        // ������� ������� ������ �������� � ������� ���������
        middle = (left + right) / 2;
        // ���� �������� � ������� �������� ����� �������� �����, �� ��������� �����
        if (array[middle] == number) break;

        // ���� �������� � ������� �������� ������ �������� �����, �������� ����� ������� ������
        if (array[middle] < number) {
            left = middle + 1;
        }
        // ����� �������� ������ ������� ������
        else {
            right = middle - 1;
        }
    }

    // ���������, ���� �� ������� �����
    if (left > right) {
        // ������� ���������, ��� ����� �� �������
        std::cout << "Number not found";
    }
    else {
        // ������� ������ ����� � ������� (��������� ������)
        std::cout << middle;
    }
}
