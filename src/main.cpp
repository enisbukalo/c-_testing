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
            std::string withdrawSelection;
            std::string removalSelection;

            account.showWelcomeMessage();
            showAccountMenu();

            std::cin >> accountMenuChoice;

            switch(accountMenuChoice)
            {
            case 1: 
                account.showWelcomeMessage();
                showDepositScreen();
                if (!(std::cin >> depositAmount)){
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }else{
                    account.depositToAccount(depositAmount);
                }
                break;
            case 2:
                account.showWelcomeMessage();
                showWithdrawalScreen();
                if (!(std::cin >> withdrawAmount)){
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }else{
                    overdraw = account.withdrawFromAccount(withdrawAmount);

                    if (overdraw){
                        //Linux specific to clear terminal.
                        system("clear");
                        showOverDrawScreen();
                        std::cin >> withdrawSelection;
                    }
                }

                break;
            case 3:
                if (account.getAccountBalance() > 0.0){
                    //Linux specific to clear terminal.
                    system("clear");
                    showCantRemoveAccountScreen();
                    std::cin >> removalSelection;
                }else{
                    account.removeAccount();
                    mainMenuValid = false;
                }
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