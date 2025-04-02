#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

// Функция записи лога
void write_log(string message) {
    // Получаем текущее время
    auto current_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    // Преобразуем его в строку
    string time_string = ctime(&current_time);
    // Удаляем символ перевода строки в конце
    time_string.erase(time_string.length() - 1);

    // Открываем файл для записи (в режиме добавления)
    ofstream log_file("log.txt", ios::app);
    // Записываем время и сообщение
    log_file << time_string << " - " << message << endl;
    // Закрываем файл
    log_file.close();
}

int main() {
    string login;
    string password;
    string usernames[3] = {"user1", "user2", "user3"};
    string passwords[3] = {"pass1", "pass2", "pass3"};
    bool is_found = false;

    do {
        cout << "Please enter your login: ";
        cin >> login;
        cout << "Please enter your password: ";
        cin >> password;

        for (int i = 0; i < 3; i++) {
            if (login == usernames[i] && password == passwords[i]) {
                is_found = true;
                cout << "Welcome, " << login << "!\n";
                // Записываем лог
                write_log("User " + login + " has logged in.");
                break;
            }
        }

        if (!is_found) {
            cout << "Incorrect login or password, please try again.\n";
            // Записываем лог
            write_log("Failed login attempt with username " + login + ".");
        }
    } while (!is_found);

    return 0;
}
