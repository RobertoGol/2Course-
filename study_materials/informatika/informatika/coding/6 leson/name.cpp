#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

// �㭪�� ����� ����
void write_log(string message) {
    // ����砥� ⥪�饥 �६�
    auto current_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    // �८�ࠧ㥬 ��� � ��ப�
    string time_string = ctime(&current_time);
    // ����塞 ᨬ��� ��ॢ��� ��ப� � ����
    time_string.erase(time_string.length() - 1);

    // ���뢠�� 䠩� ��� ����� (� ०��� ����������)
    ofstream log_file("log.txt", ios::app);
    // �����뢠�� �६� � ᮮ�饭��
    log_file << time_string << " - " << message << endl;
    // ����뢠�� 䠩�
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
                // �����뢠�� ���
                write_log("User " + login + " has logged in.");
                break;
            }
        }

        if (!is_found) {
            cout << "Incorrect login or password, please try again.\n";
            // �����뢠�� ���
            write_log("Failed login attempt with username " + login + ".");
        }
    } while (!is_found);

    return 0;
}
