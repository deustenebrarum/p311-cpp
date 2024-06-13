#include <iostream>
#include <sstream>

#include "Array.h"

struct Date {
	int year;int month;
	int day;
};

std::string to_string(const Date& date) {
	std::stringstream ss;

	ss << (date.day < 10 ? "0" : "") << date.day << '.'
		<< (date.month < 10 ? "0" : "") << date.month << '.'
		<< date.year;

	return ss.str();
}

struct Note {
	char title[100];
	char text[100];
	Date date;
};

void print(const Note& note) {
	std::cout << to_string(note.date) << '\n'
		<< note.title << '\n'
		<< note.text << '\n';
}

void showNotes(const Array<Note> notes) {
	for (size_t i = 0; i < notes.size; i++)
	{
		std::cout << i + 1 << ".\n";
		print(get(notes, i));

		std::cout << '\n';
	}
}

void callAddNoteMenu(Array<Note>& notes) {
	Note note;

	std::cout << "Введите дату(год, месяц, день):\n";
	std::cin >> note.date.year >> note.date.month
		>> note.date.day;
	std::cout << "Введите заголовок:";
	std::cin.clear();
	std::cin.ignore();
	std::cin.getline(note.title, 100);
	std::cout << "Введите текст:";
	std::cin.getline(note.text, 100);

	append(notes, note);
	system("cls");
}

void callRemoveNoteMenu(Array<Note>& notes) {
	std::cout << "Выберите номер записи для удаления:\n";
	size_t note_number;
	std::cin >> note_number;

	pop(notes, note_number - 1);
	system("cls");
}

void callMenu(Array<Note>& notes) {
	std::cout << "Выберите пункт:\n"
		<< "1) Посмотреть записи\n"
		<< "2) Добавить запись\n"
		<< "3) Удалить запись\n";
	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1: showNotes(notes); break;
	case 2: callAddNoteMenu(notes); break;
	case 3: callRemoveNoteMenu(notes); break;
	default:
		std::cout << "Нет такого пункта\n";
		break;
	}
}

int notes_menu_example() {
	setlocale(LC_ALL, "Russian");
	Array<Note> notes;
	
	while (true) {
		callMenu(notes);
	}

	return 0;
}
	
