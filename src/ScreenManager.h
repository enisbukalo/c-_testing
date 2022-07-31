#ifndef logo_h
#define logo_h

#include <iostream>

void drawLogo(){
    //Linux specific to clear terminal.
    system("clear");
    std::cout << "                                " << std::endl;
    std::cout << "             |||                " << std::endl;
    std::cout << "             |||                " << std::endl;
    std::cout << "        $$$$$$$$$$$$$$          " << std::endl;
    std::cout << "      $$::::::::::::::$         " << std::endl;
    std::cout << "     $:::::$$$$$$$::::$         " << std::endl;
    std::cout << "     $::::$  |||  $$$$$         " << std::endl;
    std::cout << "     $::::$  |||                " << std::endl;
    std::cout << "     $::::$  |||                " << std::endl;
    std::cout << "     $:::::$$$$$$$$$            " << std::endl;
    std::cout << "      $$::::::::::::$$          " << std::endl;
    std::cout << "        $$$$$$$$$:::::$         " << std::endl;
    std::cout << "             ||| $::::$         " << std::endl;
    std::cout << "             ||| $::::$         " << std::endl;
    std::cout << "     $$$$$   ||| $::::$         " << std::endl;
    std::cout << "     $::::$$$$$$$:::::$         " << std::endl;
    std::cout << "     $::::::::::::::$$          " << std::endl;
    std::cout << "      $$$$$$$$$$$$$$            " << std::endl;
    std::cout << "             |||                " << std::endl;
    std::cout << "             |||                " << std::endl;
    std::cout << "                                " << std::endl;
    std::cout << "***Banking Information System***" << std::endl;
};

void showMainMenu(){
    drawLogo();
    std::cout << std::endl;
    std::cout << "***********Main Menu***********" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1 --> Enter Your Name" << std::endl;
    std::cout << "0 --> Quit" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter your choice: (0-1): ";
};

void showAccountMenu(){
    std::cout << std::endl;
    std::cout << "*********Account Menu*********" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "1 --> Deposit Into Account" << std::endl;
    std::cout << "2 --> Withdraw From Account" << std::endl;
    std::cout << "3 --> Remove Account" << std::endl;
    std::cout << "0 --> Quit" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter your choice: (0-4): ";
};

void showDepositScreen(){
    std::cout << std::endl;
    std::cout << "********Deposit Screen********" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Enter Amount To Deposit: ";
};

void showWithdrawalScreen(){
    std::cout << std::endl;
    std::cout << "*******Withdrawal Screen*******" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Enter Amount To Withdraw: ";
};

void showOverDrawScreen(){
    std::cout << std::endl;
    std::cout << "*****Withdrawal Prevented*****" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Sorry, You Don't Have Enough Money To Withdraw." << std::endl;
    std::cout << "Press Any Button To Continue...";
};

#endif