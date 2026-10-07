#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << " REGISTRATION _____________\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string savedUser, savedPass;

    while (file >> savedUser >> savedPass) {
        if (savedUser == username) {
            cout << "Username already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string savedUser, savedPass;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUser >> savedPass) {
        if (savedUser == username && savedPass == password) {
            cout << "Login successful!\n";
            file.close();
            return;
        }
    }

    file.close();

    cout << "Invalid username or password!\n";
}

int main() {
    int choice;

    do {

        cout << " LOGIN & REGISTRATION SYSTEM\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}