#ifndef account_h
#define account_h

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <cmath>

class Account{
    public:
        //Constructor
        Account(std::string firstName, std::string lastName);

        //Methods
        void showWelcomeMessage();
        bool checkAccountExists();
        void createAccount();
        void depositToAccount(double);
        bool withdrawFromAccount(double);
        void removeAccount();

        //Getters
        bool getAccountExists();
        double getAccountBalance();
        std::string getAccountName();

    private:
        //Methods
        std::string parseAccountNameForFile();
        void createFile();
        void saveAccount();
        void loadAccount();

        //Members
        std::string firstName;
        std::string lastName;
        std::string accountName;
        double accountBalance;
        bool accountExists;
        std::filesystem::path accountFilePath;
};

#endif