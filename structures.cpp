#include <iostream>
#include <cmath>
#include <cstring>

struct User {
    const char* username;
    const char* password;
    int registration_year;
};

User* find(User* users, size_t size, const char* username) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return users + i;
        }
    }

    return nullptr;
}

User* add_user(
    User* users,
    size_t size,
    const char* username,
    const char* password,
    int year
) {
    User* found_user = find(users, size, username);

    if (found_user != nullptr) {
        return nullptr;
    }

    users[size] = User{
        username,
        password,
        year
    };

    return users + size;
}

User* authorize(
    User* users,
    size_t size,
    const char* username,
    const char* password
) {
    User* user = find(users, size, username);

    if (user == nullptr) return nullptr;

    if (strcmp(user->password, password) != 0) {
        return nullptr;
    }

    return user;
}

void User_Print(const User& user) {
    std::cout << user.username << '\n'
        << user.registration_year << "\n\n";
}

void User_Print(const User* users, size_t users_count) {
    for (size_t i = 0; i < users_count; i++)
    {
        User_Print(users[i]);
    }
}

int main() {
    size_t users_count = 0;
    size_t users_capacity = 100;
    User* users = new User[users_capacity];

    while (true) {
        int choice = 0;

        std::cout << "1) to register\n"
            << "2) to authorize\n"
            << "3) to sort by year";

        std::cin >> choice;

        if (choice == 1) {
            char* username = new char[100];
            char* password = new char[100];

            std::cin.ignore();
            std::cin.getline(username, 100, '\n');
 
            std::cin.getline(password, 100, '\n');

            int year;
            std::cin >> year;

            add_user(users, users_count, username, password, year);
            users_count++;
        }
        else if (choice == 2) {
            char username[100];
            char password[100];

            std::cin.ignore();
            std::cin.getline(username, 100);
            std::cin.clear();
            std::cin.getline(password, 100);

            User* user = authorize(users, users_count, username, password);

            if (user == nullptr) continue;

            std::cout << "Hello " << user->username << '\n';
            break;
        } else {
            for (size_t i = 0; i < users_count; i++)
            {
                for (size_t j = 0; j < users_count - 1; j++)
                {
                    if (
                        users[j].registration_year >
                        users[j + 1].registration_year
                    ) {
                        std::swap(users[j], users[j + 1]);
                    }
                }
            }
            User_Print(users, users_count);
        }
    }
}
