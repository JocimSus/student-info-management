#include <filesystem>
#include <iostream>
#include <string>

#include "./adminFunctions.h"
#include "./passwordEncryption.h"

enum LoginChoice { Admin = 1,
                   Student = 2 };
enum AdminChoice { Add_Student_Details = 1,
                   Delete_Students = 2,
                   Admin_View_Table = 3,
                   Main_Menu = 4 };
enum StudentChoice { Student_View_Table = 1 };

int main() {
    while (true) {
        std::cout << "Login As :" << std::endl
                  << std::endl
                  << "1. Admin" << std::endl
                  << "2. Student" << std::endl
                  << "3. Exit" << std::endl
                  << std::endl
                  << "Enter Your Choice (1-3):" << std::endl
                  << "> ";

        int login_choice;
        std::cin >> login_choice;

        std::cout << std::endl;

        if (login_choice == Admin) {
            std::string admin_password = "";
            while (true) {
                if (std::filesystem::exists("password.txt")) {
                    // Login
                    std::cout << "| Log in |" << std::endl
                              << std::endl
                              << "Enter Password :" << std::endl
                              << "> ";
                    std::cin >> admin_password;

                    if (!(admin_password.empty()) && (authenticatePassword(admin_password))) {
                        std::cout << "Login Successful" << std::endl
                                  << std::endl;
                        admin_password.clear();  // clears password from stack
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

                    if (!(admin_password.empty())) {
                        savePassword(admin_password);
                    }
                }
            }
            while (true) {
                std::cout << "| Logged in as Admin |" << std::endl
                          << std::endl
                          << "1. Add Students Details" << std::endl
                          << "2. Delete Students" << std::endl
                          << "3. View Table" << std::endl
                          << "4. Main Menu" << std::endl
                          << "5. Exit" << std::endl
                          << std::endl
                          << "Enter Your Choice (1-5):" << std::endl
                          << "> ";

                int admin_choice = 0;
                std::cin >> admin_choice;
                switch (admin_choice) {
                    case Add_Student_Details:
                        std::cout << "1";
                        // func
                        break;
                    case Delete_Students:
                        std::cout << "2";
                        // func
                        break;
                    case Admin_View_Table:
                        std::cout << "3";
                        // func
                        break;
                    case Main_Menu:
                        std::cout << "4";
                        break;
                    default:
                        std::cout << "Exiting...";
                        return 0;
                }
                break;
            }
        } else if (login_choice == Student) {
            while (true) {
                std::cout << "| Logged in as Student |" << std::endl
                          << std::endl
                          << "1. View Table" << std::endl
                          << "2. Exit" << std::endl
                          << std::endl
                          << "Enter Your Choice (1-2):" << std::endl
                          << "> ";
                int student_choice = 0;
                std::cin >> student_choice;
                switch (student_choice) {
                    case Student_View_Table:
                        std::cout << "1";
                        // func
                        break;
                    default:
                        std::cout << "Exiting...";
                        return 0;
                }
                break;
            }
        } else {
            std::cout << "Exiting...";
            break;
        }
    }
    return 0;
}