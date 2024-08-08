#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

class User {
public:
    std::string username;
    std::string password;

    User(const std::string& user, const std::string& pass)
        : username(user), password(pass) {}
};

// Function to check if a user file already exists
bool userExists(const std::string& username) {
    std::string filename = username + ".txt";
    return std::filesystem::exists(filename);
}

// Function to save user credentials to a file
void saveUser(const User& user) {
    std::string filename = user.username + ".txt";
    std::ofstream file(filename);
    if (file.is_open()) {
        file << user.password;  // Store the password in the file
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

// Function to register a new user
bool registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cout << "Username already exists. Please choose another one." << std::endl;
        return false;
    }

    User user(username, password);
    saveUser(user);
    std::cout << "Registration successful!" << std::endl;
    return true;
}

// Function to login a user
bool loginUser(const std::string& username, const std::string& password) {
    if (!userExists(username)) {
        std::cout << "Username does not exist." << std::endl;
        return false;
    }

    std::string filename = username + ".txt";
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string storedPassword;
        std::getline(file, storedPassword);  // Read the stored password

        if (storedPassword == password) {
            std::cout << "Login successful!" << std::endl;
            file.close();
            return true;
        } else {
            std::cout << "Invalid password." << std::endl;
            file.close();
            return false;
        }
    } else {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return false;
    }
}

int main() {
    int choice;
    std::string username, password;

    do {
        std::cout << "1. Register\n2. Login\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                registerUser(username, password);
                break;

            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                loginUser(username, password);
                break;

            case 3:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

