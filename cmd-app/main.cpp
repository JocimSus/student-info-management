#include <iostream>

int main()
{
    std::string login_choice = "";
    std::string admin_options = "";

    std::cout << "Login As :" << std::endl
              << std::endl
              << "1. Admin" << std::endl
              << "2. Student" << std::endl
              << "3. Exit" << std::endl
              << std::endl
              << "Enter Your Choice :" << std::endl
              << "> ";

    std::cin >> login_choice;

    if ((login_choice == "1") || (lowerString(login_choice) == "admin"))
    {
        std::cout << "| Logged in as Admin |" << std::endl
                  << "1. Add Students Details" << std::endl
                  << "2. Delete Students" << std::endl
                  << "3. View Table" << std::endl
                  << "4. Main Menu" << std::endl
                  << "5. Exit";
    }
    else if ((login_choice == "2") || (lowerString(login_choice) == "student"))
    {
        std::cout << "| Logged in as Student |";
    }

    return 0;
}

std::string lowerString(std::string string)
{
    std::string lowercase_string = 0;
    for (auto c : string)
    {
        lowercase_string.push_back(tolower(c));
    }
    return lowercase_string;
}