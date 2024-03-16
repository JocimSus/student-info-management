#include <iostream>

#include "./adminFunctions.h"

enum LoginChoice { Admin = 1,
                   Student = 2 };

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
            adminUI();
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