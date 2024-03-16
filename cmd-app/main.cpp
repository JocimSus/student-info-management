#include <iostream>

#include "adminFunctions.h"
#include "studentFunctions.h"

enum LoginChoice { Admin = 1,
                   Student = 2 };

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

        switch (login_choice) {
            case Admin:
                adminUI();
                break;
            case Student:
                studentUI();
                break;
            default:
                std::cout << "Exiting...";
                exit(0);
        }
    }
    return 0;
}