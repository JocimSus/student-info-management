#ifndef ADMIN_FUNCTIONS_H
#define ADMIN_FUNCTIONS_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "passwordEncryption.h"

enum AdminChoice { Add_Student_Details = 1,
                   Delete_Students_Details = 2,
                   Admin_View_Table = 3,
                   Admin_Main_Menu = 4 };
enum DeleteOptions { All_Of_Target_Word = 1,
                     Single_Target_Word = 2,
                     By_Line_Number = 3 };
enum TableOptions { Change_Lines = 1 };

std::string student_filename = "student_data.csv";
int display_lines = 5;

std::vector<std::string> readCSV() {
    std::ifstream rfile(student_filename);
    std::vector<std::string> content;
    std::string line;
    while (std::getline(rfile, line)) {
        content.push_back(line);
    }
    return content;
}

void writeCSV(std::vector<std::string> &content) {
    std::ofstream wfile(student_filename);
    for (auto l : content) {
        wfile << l << std::endl;
    }
}

void addStudentsDetails() {
    std::string csv_headers = "Name,College/School,Branch,Attendance,AvgScores";
    if (!(std::filesystem::exists(student_filename))) {
        // if file not exist
        std::ofstream wfile(student_filename);
        if (!(wfile.is_open())) {
            // if file exist && is not open
            std::cerr << "Error: Unable to open file" << std::endl
                      << std::endl;
        }
        wfile << csv_headers << "\n";
        wfile.close();
    }
    // if file exists
    std::ofstream wfile(student_filename, std::ios::app);
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
            wfile << uinput << "\n";
        }
    }

    wfile.close();
}

void viewTable() {
    if (!(std::filesystem::exists(student_filename))) {
        std::cerr << "Error: File does not exist yet (do AddStudents first)";
    }
    // if file exists
    std::ifstream rfile(student_filename);
    if (!(rfile.is_open())) {
        // if file exist && is not open
        std::cerr << "Error: Unable to open file" << std::endl
                  << std::endl;
    }
    const int fieldWidth = 15;
    std::string name, school, branch, attendance, avgscores;

    while (true) {
        std::cout << "---------------------------------------------------------------------------" << std::endl;
        for (unsigned int i = 0; i < display_lines; ++i) {
            std::string line;
            if (std::getline(rfile, line)) {
                std::istringstream iss(line);

                std::getline(iss, name, ',');
                std::getline(iss, school, ',');
                std::getline(iss, branch, ',');
                std::getline(iss, attendance, ',');
                std::getline(iss, avgscores, ',');

                std::cout << std::setw(fieldWidth) << name
                          << std::setw(fieldWidth) << school
                          << std::setw(fieldWidth) << branch
                          << std::setw(fieldWidth) << attendance
                          << std::setw(fieldWidth) << avgscores << std::endl;
            } else {
                break;
            }
        }
        std::cout << "---------------------------------------------------------------------------" << std::endl;
        std::cout << "1. Change How Many Lines are displayed? (default:5)" << std::endl
                  << "2. Exit" << std::endl
                  << "> ";
        int uinput = 0;
        std::cin >> uinput;
        switch (uinput) {
            case Change_Lines:
                std::cout << "Enter a number :" << std::endl
                          << "> ";
                std::cin >> display_lines;
                return;

            default:
                return;
        }
    }
}

void deleteStudentsDetails() {
    viewTable();
    std::vector<std::string> content = readCSV();
    std::cout << "Enter the index of entry to delete :" << std::endl
              << "> ";
    unsigned int index = 0;
    std::cin >> index;
    if (index >= 1 && index <= content.size()) {
        content.erase(content.begin() + index);
        std::cout << "Entry deleted successfully" << std::endl;
    } else {
        std::cerr << "Error: Invalid entry number" << std::endl;
    }
    writeCSV(content);
}

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
            case Delete_Students_Details:
                deleteStudentsDetails();
                break;
            case Admin_View_Table:
                viewTable();
                break;
            case Admin_Main_Menu:
                return;
            default:
                std::cout << "Exiting..." << std::endl;
                exit(0);
        }
    }
}

#endif  // ADMIN_FUNCTIONS_H