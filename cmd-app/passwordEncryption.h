#ifndef PASSWORD_ENCRYPTION_H
#define PASSWORD_ENCRYPTION_H

#include <openssl/evp.h>
#include <openssl/sha.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string password_filename = "password.txt";

std::string hashPassword(const std::string password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();

    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, password.c_str(), password.length());
    EVP_DigestFinal_ex(mdctx, hash, NULL);
    EVP_MD_CTX_free(mdctx);

    // Convert to hex string
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void savePassword(const std::string password) {
    std::string hashed_password = hashPassword(password);
    if (!(std::filesystem::exists(password_filename))) {
        // if file not exist
        std::ofstream wfile(password_filename);
        wfile.close();
    }
    // if file exists
    std::ofstream wfile(password_filename);
    if (!(wfile.is_open())) {
        // if file exist && is not open
        std::cerr << "Error: Unable to open file" << std::endl
                  << std::endl;
    }
    wfile << hashed_password;
    wfile.close();
    std::cout << "Successfully saved password" << std::endl
              << std::endl;
}

bool authenticatePassword(const std::string password) {
    std::ifstream rfile(password_filename);
    if (rfile.is_open()) {
        std::string stored_hashed_password = "";
        std::string hashed_password = hashPassword(password);

        std::getline(rfile, stored_hashed_password);
        rfile.close();

        return (hashed_password == stored_hashed_password);
    } else {
        std::cerr << "Error: Unable to open file";
        return false;
    }
}

#endif  // PASSWORD_ENCRYPTION_H