#include <iostream>

struct Book {
	char name[100];
	char author[100];
	char publisher[100];
};

struct Books {
	Book* pointer;
	size_t size;
};

void Book_Print(const Book& book) {
	std::cout << "��������: " << book.name << '\n';

	std::cout << "�����: " << book.author << '\n';

	std::cout << "��������: " << book.publisher << '\n';
}

void callBookEditing(Book* books, size_t size) {
	size_t index;
	std::cin >> index;

	std::cout << "��������: " << books[index].name << '\n'
		<< "����� ��������: ";
	std::cin >> books[index].name;

	std::cout << "�����: " << books[index].author << '\n'
		<< "����� �����: ";
	std::cin >> books[index].author;

	std::cout << "��������: " << books[index].publisher << '\n'
		<< "����� ��������: ";
	std::cin >> books[index].publisher;
}

void print_books(const Book* books, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		Book_Print(books[i]);
	}
}

const char* Book_Author(const Book& book) {
	return book.author;
}

void print_books_by(
	Book* books, 
	size_t size,
	const char* (key_getter) (const Book&)
) {
	char value[100]{ };

	std::cin >> value;

	for (size_t i = 0; i < size; i++)
	{
		if (strstr(key_getter(books[i]), value) != nullptr) {
			Book_Print(books[i]);
		}
	}
}

void sort_by(
	Book* books, 
	size_t size, 
	const char* (key_getter)(const Book&)) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (strcmp(key_getter(books[j]), key_getter(books[j + 1])) > 0) {
				std::swap(books[j], books[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	Book books[4]{
		{
			"aba",
			"abu",
			"abab"
		},
		{
			"giga",
			"gugu",
			"dada"
		},
		{
			"dio",
			"vio",
			"tao"
		},
		{
			"dom",
			"bon",
			"bom"
		}
	};

	std::cout << "1) ������������� �����\n" <<
		"2) ������ ���� ����\n" <<
		"3) ����� ���� �� ������\n" <<
		"4) ����� ����� �� ��������\n" <<
		"5) ���������� ������� �� �������� ����\n" <<
		"6) ���������� ������� �� ������\n" <<
		"7) ���������� ������� �� ������������\n";

	sort_by(books, 4, Book_Author);

	print_books(books, 4);
}
