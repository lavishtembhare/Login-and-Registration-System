C++ Login and Registration System



This project is a simple C++ console application for a login and registration system. It allows users to register with a username and password and login with their credentials. User credentials are stored in individual text files for each user.

Features
Registration: Users can register with a unique username and password. Each user's credentials are stored in a separate file named after the username.

Login: Users can log in using their username and password. The system validates credentials against the stored data.

File Handling: Uses file handling to store and retrieve user credentials. The <filesystem> library is used to check the existence of files.

Getting Started
Prerequisites
To compile and run this project, you need a C++ compiler that supports C++17 or later.

Compilation
To compile the project, use a C++ compiler like g++. Open a terminal and run the following command:

bash
Copy code
g++ login_registration_system.cpp -o login_registration_system
Running the Program
After compilation, you can run the executable:

bash
Copy code
./login_registration_system
Usage
Register a New User:

Choose the "Register" option from the menu.
Enter a unique username and a password.
If the username does not already exist, a file will be created with the username, and the password will be stored in it.
Login with Existing User:

Choose the "Login" option from the menu.
Enter your username and password.
If the credentials are correct, you will be logged in successfully.
Exit the Program:

Choose the "Exit" option from the menu to quit the program.
Code Explanation
The main components of the code are:

User Class: Represents a user with a username and password.
File Handling:
userExists: Checks if a file for the username already exists.
saveUser: Creates a file for a new user and stores the password.
loginUser: Reads the stored password from the user's file and validates it.
Main Menu: Provides options for registration, login, and exit.
Security Considerations
Plain Text Passwords: Passwords are stored in plain text in this implementation. For a more secure system, consider using hashing algorithms to store passwords.
License
This project is open-source and available under the MIT License. Feel free to use, modify, and distribute it as needed.
