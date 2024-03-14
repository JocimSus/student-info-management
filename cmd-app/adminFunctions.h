#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "passwordEncryption.h"

enum AdminChoice { Add_Student_Details = 1,
                   Delete_Students = 2,
                   Admin_View_Table = 3,
                   Main_Menu = 4 };

std::string student_filename = "student_data.csv";

void addStudentsDetails();

void adminUI() {
    std::string admin_password = "";
    while (true) {
        if (!(std::filesystem::exists("password.txt"))) {
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
                addStudentsDetails();
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
                std::cout << "Exiting..." << std::endl;
                exit(0);
        }
    }
}

// TODO: FIX THIS SHIT!
void addStudentsDetails() {
    char csv_headers[] = "Name,College/School,Branch,Attendance,AvgScores";
    if (!(std::filesystem::exists(student_filename))) {
        // if file not exist
        std::ofstream initwfile(student_filename);
        initwfile << csv_headers << "\\n";
        initwfile.close();
    }
    // if file exists
    std::fstream wfile(student_filename);
    if (!(wfile.is_open())) {
        // if file exist && is not open
        std::cerr << "Error: Unable to open file" << std::endl
                  << std::endl;
    }
    while (true) {
        std::cout << csv_headers << std::endl;

        std::cout << "Write the students data according to the headers above ('e' to exit):" << std::endl
                  << "> ";
        std::string uinput = "";
        std::cin >> uinput;
        if (uinput.empty()) {
            std::cerr << "Error: Cannot be empty" << std::endl;
            break;
        } else if (uinput == "e") {
            std::cout << "Exiting mode" << std::endl;
            break;
        } else {
            wfile << uinput << "\\n";
        }
    }

    wfile.close();
}