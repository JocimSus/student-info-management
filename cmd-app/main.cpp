#include <iostream>
#include <string>
#include <filesystem>
#include <utilities.h>
#include <adminFunctions.h>
#include <passwordEncryption.h>

int main()
{
    std::string login_choice = "";
    std::string admin_options = "";
    std::string admin_password = "";

    while (true)
    {
        std::cout << "Login As :" << std::endl
                  << std::endl
                  << "1. Admin" << std::endl
                  << "2. Student" << std::endl
                  << "3. Exit" << std::endl
                  << std::endl
                  << "Enter Your Choice :" << std::endl
                  << "> ";

        std::cin >> login_choice;
        std::cout << std::endl;
    }

    if ((login_choice == "1") || (lowerString(login_choice) == "admin"))
    {
        while (true)
        {
            if (std::filesystem::exists("password.txt"))
            {
                admin_password = "";
                std::cout << "| Log in |" << std::endl
                          << std::endl
                          << "Enter Password :" << std::endl
                          << "> ";
                std::cin >> admin_password;
                if ((admin_password != "") || (authenticatePassword(admin_password)))
                {
                    break;
                }
            }
            else
            {
                admin_password = "";
                std::cout << "| Create Password |" << std::endl
                          << "Enter Password :" << std::endl
                          << "> ";
                std::cin >> admin_password;
            }
        }
        std::cout << "| Logged in as Admin |" << std::endl
                  << std::endl
                  << "1. Add Students Details" << std::endl
                  << "2. Delete Students" << std::endl
                  << "3. View Table" << std::endl
                  << "4. Main Menu" << std::endl
                  << "5. Exit" << std::endl
                  << std::endl
                  << "Enter Your Choice :" << std::endl;
    }
    else if ((login_choice == "2") || (lowerString(login_choice) == "student"))
    {
        std::cout << "| Logged in as Student |";
    }

    return 0;
}
