#include <iostream>

struct Contact {
	const char* name;
	const char* mobile_phone;
	const char* home_phone;
};

void Contact_Print(const Contact contact) {
	std::cout << "Name: "
		<< contact.name
		<< std::endl
		<< "Mobile phone: "
		<< contact.mobile_phone
		<< std::endl
		<< "Home phone: "
		<< contact.home_phone;
}

int main() {
	Contact contact{
		"John",
		"123-456-7890",
		"987-654-3210"
	};

	Contact_Print(contact);
}