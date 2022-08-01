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
    bool accountMenuValid = true;

    drawLogo();

    while (true)
    {
        showMainMenu();
        std::cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
            std::cout << "Enter Your First Name: ";
            std::cin >> accountFirstName;
            std::cout << " Enter Your Last Name: ";
            std::cin >> accountLastName;
            accountMenuValid = true;
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

        if (!account.getAccountExists())
        {
            std::cout << "\nSorry, your account does not exist, would you like to create one? (y/n): ";
            std::cin >> createAccountChoice;
            switch (toupper(createAccountChoice))
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

        while (accountMenuValid)
        {
            // Scoped Variables
            double depositAmount;
            double withdrawAmount;
            bool overdraw;
            std::string withdrawSelection;
            std::string removalSelection;
            std::string transactionSelection;

            account.showWelcomeMessage();
            showAccountMenu();

            std::cin >> accountMenuChoice;

            switch (accountMenuChoice)
            {
            case 1:
                account.showWelcomeMessage();
                showDepositScreen();
                if (!(std::cin >> depositAmount))
                {
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }
                else
                {
                    account.depositToAccount(depositAmount);
                }
                break;
            case 2:
                account.showWelcomeMessage();
                showWithdrawalScreen();
                if (!(std::cin >> withdrawAmount))
                {
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }
                else
                {
                    overdraw = account.withdrawFromAccount(withdrawAmount);

                    if (overdraw)
                    {
                        clearScreen();
                        showOverDrawScreen();
                        std::cin >> withdrawSelection;
                    }
                }
                break;
            case 3:
                showTransactionsScreen();
                for (Transaction &transaction : account.getTransactions())
                {
                    std::cout << "-----------------------------------------------------------" << std::endl;
                    std::cout << "Transaction Timestamp: " << transaction.timestamp << std::endl;
                    std::cout << "     Transaction Type: " << TransactionStructConverter::TransactionConversion(transaction.transactionType) << std::endl;
                    std::cout << "   Transaction Amount:$" << std::stod(transaction.transactionAmount) << std::endl;
                    std::cout << "      Running Balance:$" << std::fixed << std::cout.precision(2) << transaction.balance << std::endl;
                }
                std::cout << "-----------------------------------------------------------" << std::endl;
                std::cout << "Press Any Button To Continue...";
                std::cin >> transactionSelection;
                break;
            case 4:
                if (account.getAccountBalance() > 0.0)
                {
                    clearScreen();
                    showCantRemoveAccountScreen();
                    std::cin >> removalSelection;
                }
                else
                {
                    account.removeAccount();
                    accountMenuValid = false;
                }
                break;
            case 0:
                accountMenuValid = false;
                break;
            default:
                std::cout << "Sorry, that wasn't a valid choice." << std::endl;
                exit(0);
            }
        }
    }

    return 0;
}