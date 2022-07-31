#include <iostream>
#include <cctype>

#include "Account.h"
#include "ScreenManager.h"
#include "StringTrimmer.h"

int main()
{   
    int accountMenuChoice;
    int mainMenuChoice;
    char createAccountChoice;
    std::string accountFirstName;
    std::string accountLastName;
    std::string accountName;
    bool mainMenuValid = true;

    drawLogo();

    while (true){
        showMainMenu();
        std::cin >> mainMenuChoice;

        switch(mainMenuChoice){
            case 1:
                std::cout << "Enter Your First Name : ";
                std::cin >> accountFirstName;
                std::cout << "Enter Your Last Name  : ";
                std::cin >> accountLastName;
                mainMenuValid = true;
                break;
            case 0:
                exit(0);
                break;
            default:
                std::cout << "Sorry, that wasn't a valid choice." << std::endl;
                exit(0);
                break;
        }

        Account account(trimString(accountFirstName), trimString(accountLastName));

        if (!account.getAccountExists()){
            std::cout << "\nSorry, your account does not exist, would you like to create one? (y/n): ";
            std::cin >> createAccountChoice;
            switch(toupper(createAccountChoice))
            {
            case 'Y':
                account.createAccount();
                break;
            case 'N':
                std::cout << "Thank You For Choosing Our Bank." << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Sorry, that wasn't a valid choice." << std::endl;
                exit(0);
                break;
            }
        }

        while(mainMenuValid)
        {   
            //Scoped Variables
            double depositAmount;
            double withdrawAmount;
            bool overdraw;
            char withdrawSelection;

            account.showWelcomeMessage();
            showAccountMenu();

            std::cin >> accountMenuChoice;

            switch(accountMenuChoice)
            {
            case 1: 
                account.showWelcomeMessage();
                showDepositScreen();
                std::cin >> depositAmount;
                account.depositToAccount(depositAmount);
                break;
            case 2:
                //TODO Check if account exists first.
                //TODO Read account file, pull balance information.
                //TODO If sufficient funds, remove from balance, else block.
                account.showWelcomeMessage();
                showWithdrawalScreen();
                std::cin >> withdrawAmount;
                overdraw = account.withdrawFromAccount(withdrawAmount);

                if (overdraw){
                    //Linux specific to clear terminal.
                    system("clear");
                    showOverDrawScreen();
                    std::cin >> withdrawSelection;
                }

                break;
            case 3:
                //TODO Check if account exists first.
                //TODO If funds are zero, remove account, else block.
                std::cout << "REMOVE ACCOUNT" << std::endl;
                break;
            case 0:
                mainMenuValid = false;
                break;
            default:
                std::cout << "Sorry, that wasn't a valid choice." << std::endl;
                exit(0);
            }
        }
    }

    return 0;
}