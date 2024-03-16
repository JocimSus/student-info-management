#ifndef STUDENT_FUNCTIONS_H
#define STUDENT_FUNCTIONS_H

#include "adminFunctions.h"

enum StudentChoice { Student_View_Table = 1,
                     Student_Main_Menu = 2 };

void studentUI() {
    while (true) {
        std::cout << "| Logged in as Student |" << std::endl
                  << std::endl
                  << "1. View Table" << std::endl
                  << "2. Main Menu" << std::endl
                  << "3. Exit" << std::endl
                  << std::endl
                  << "Enter Your Choice (1-2):" << std::endl
                  << "> ";
        int student_choice = 0;
        std::cin >> student_choice;
        switch (student_choice) {
            case Student_View_Table:
                viewTable();
                break;
            case Student_Main_Menu:
                return;
            default:
                std::cout << "Exiting...";
                exit(0);
        }
    }
}

#endif  // STUDENT_FUNCTIONS_H