#include <iostream>

#include "Account.h"

Account::Account(std::string firstNameIn, std::string lastNameIn) :
    firstName(firstNameIn), lastName(lastNameIn), accountName(firstNameIn + lastNameIn), accountFilePath(firstNameIn + lastNameIn + ".bank"){
    if (checkAccountExists()){
        loadAccount();
    };
};

//Constructor
void Account::createAccount(){
    double initialBalance;
    createFile();

    //Linux specific to clear terminal.
    system("clear");
    std::cout << "\n***Welcome To Account Creation***\n" << std::endl;
    std::cout << "Account Name: " << getAccountName() << std::endl;
    std::cout << "What Is Your Initial Deposit?: $";
    std::cin >> initialBalance;
    std::cout << std::endl;

    if (std::cin.good()){
        accountBalance = std::ceil(initialBalance * 100.0) / 100.0;
        saveAccount();
        std::cout << "Congratulations! Your Account Balance Is Now: $" << getAccountBalance() << std::endl;
    } else {
        std::cout << "Invalid Deposit Input." << std::endl;
        exit(0);
    }
};

//Methods
void Account::createFile(){
    std::ofstream outfile(accountFilePath);
    outfile.close();
};

bool Account::checkAccountExists(){
    accountExists = true ? std::filesystem::exists(accountFilePath) : false;
    return getAccountExists();
};

void Account::showWelcomeMessage(){
    loadAccount();

    //Linux specific to clear terminal.
    system("clear");
    std::cout << "****Welcome To Your Account " << firstName + " " + lastName + "****" << std::endl;
    std::cout << "****Account Name   : " << accountName << std::endl;
    std::cout << "****Account Balance: " << accountBalance << std::endl;
};

void Account::saveAccount(){
    std::string accountBalanceString = std::to_string(getAccountBalance());

    std::ofstream outfile;
    outfile.open(accountFilePath);
    outfile << firstName + "\n";
    outfile << lastName + "\n";
    outfile << accountBalanceString + "\n";
    outfile.close();
};

void Account::loadAccount(){
    int i = 0;
    std::string tempLine;

    std::ifstream infile;
    infile.open(accountFilePath);
    while (infile >> tempLine){
        if (i==0){
            firstName = tempLine;
        } else if (i==1){
            lastName = tempLine;
        } else{
            accountBalance = std::stod(tempLine);
        }
        i++;
    }
    infile.close();
};

void Account::depositToAccount(double amountToDeposit){
    accountBalance += amountToDeposit;
    saveAccount();
};

bool Account::withdrawFromAccount(double amountToWithdraw){
    bool toReturn;
    if (amountToWithdraw > accountBalance){
        toReturn = true;
    } else{
        accountBalance -= amountToWithdraw;
        saveAccount();
        toReturn = false;
    }
    return toReturn;
};

//Getters
double Account::getAccountBalance(){return accountBalance;}

bool Account::getAccountExists(){return accountExists;}

std::string Account::getAccountName(){return accountName;}