#include <iostream>
#include <openssl/sha.h>
#include <fstream>
#include <string>
#include <ctime>

std::string hashPassword(const std::string &password)
{
    std::string hashed_password = "";

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        hashed_password += hash[i];
    }
    return hashed_password;
}

void savePassword(const std::string &hashed_password)
{
    std::fstream file;
    file.open("password.txt");
    if (file.is_open())
    {
        file << hashed_password;
        file.close();
        std::cout << "Successfully saved password";
    }
    else
    {
        std::cerr << "Error: Unable to open file";
    }
}

bool authenticatePassword(const std::string &password)
{
    std::fstream file;
    std::string stored_hashed_password = "";
    file.open("password.txt");
    if (file.is_open())
    {
        std::string hashed_password = hashPassword(password);
        std::getline(file, stored_hashed_password);
        file.close();
        if (hashed_password == stored_hashed_password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file";
    }
}