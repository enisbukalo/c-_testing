#ifndef account_h
#define account_h

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

#include "TransactionStruct.h"

class Account{
    public:
        //Constructor
        Account(std::string&, std::string&);

        //Methods
        void showWelcomeMessage();
        void createAccount();
        void depositToAccount(double&);
        bool withdrawFromAccount(double);
        void removeAccount();

        //Getters
        bool getAccountExists();
        double getAccountBalance();
        std::string getAccountName();
        int getNumberOfTransactions();
        std::vector<Transaction> getTransactions();

    private:
        //Methods
        std::string parseAccountNameForFile();
        bool checkFileExists(std::filesystem::path&);
        void loadTransactions();
        void saveTransactions();
        void createFiles();
        void saveAccount();
        void loadAccount();
        void createTransaction(double&);

        //Members
        std::string firstName;
        std::string lastName;
        std::string accountName;
        double accountBalance;
        bool accountExists;
        std::filesystem::path accountFilePath;
        std::filesystem::path transactionFilePath;
        std::vector<Transaction> transactions;
        int numOfTransactions;
};

#endif