#include <filesystem>
#include <iostream>
#include <string>

#include "./adminFunctions.h"
#include "./passwordEncryption.h"
#include "./utilities.h"

int main() {
    while (true) {
        std::cout << "Login As :" << std::endl
                  << std::endl
                  << "1. Admin" << std::endl
                  << "2. Student" << std::endl
                  << "3. Exit" << std::endl
                  << std::endl
                  << "Enter Your Choice :" << std::endl
                  << "> ";

        std::string login_choice = "";
        std::cin >> login_choice;
        login_choice = lowerString(login_choice);

        std::cout << std::endl;

        std::string admin_password = "";
        if ((login_choice == "1") || (login_choice == "admin")) {
            while (true) {
                if (std::filesystem::exists("password.txt")) {
                    // Login
                    std::cout << "| Log in |" << std::endl
                              << std::endl
                              << "Enter Password :" << std::endl
                              << "> ";
                    std::cin >> admin_password;
                    if ((admin_password != "") && (authenticatePassword(admin_password))) {
                        std::cout << "Login Successful" << std::endl
                                  << std::endl;
                        break;
                    } else {
                        std::cout << "Wrong Password" << std::endl
                                  << std::endl;
                    }
                } else {
                    // Register
                    std::cout << "| Create Password |" << std::endl
                              << std::endl
                              << "Enter Password :" << std::endl
                              << "> ";
                    std::cin >> admin_password;
                    if (admin_password != "") {
                        savePassword(admin_password);
                    }
                }
            }
            while (true) {
                char admin_choice = 0;
                std::cout << "| Logged in as Admin |" << std::endl
                          << std::endl
                          << "1. Add Students Details" << std::endl
                          << "2. Delete Students" << std::endl
                          << "3. View Table" << std::endl
                          << "4. Main Menu" << std::endl
                          << "5. Exit" << std::endl
                          << std::endl
                          << "Enter Your Choice :" << std::endl
                          << "> ";
                std::cin >> admin_choice;
                switch (admin_choice) {
                    case '1':
                        std::cout << "1";
                        break;
                    case '2':
                        std::cout << "2";
                        break;
                    case '3':
                        std::cout << "3";
                        break;
                    case '4':
                        std::cout << "4";

                    default:
                        std::cout << "Exiting...";
                        break;
                }
                break;
            }
        } else if ((login_choice == "2") || (login_choice == "student")) {
            while (true) {
                char student_choice = 0;
                std::cout << "| Logged in as Student |" << std::endl
                          << std::endl
                          << "1. View Table" << std::endl
                          << "2. Exit" << std::endl
                          << std::endl
                          << "Enter Your Choice :" << std::endl
                          << "> ";
                std::cin >> student_choice;
                switch (student_choice) {
                    case '1':
                        std::cout << "1";
                        break;

                    default:
                        std::cout << "Exiting...";
                        break;
                }
                break;
            }
            break;
        } else {
            std::cout << "Exiting...";
            break;
        }
    }

    return 0;
}