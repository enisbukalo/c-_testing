#include "Account.h"

Account::Account(std::string &firstNameIn, std::string &lastNameIn) : firstName(firstNameIn),
                                                                      lastName(lastNameIn),
                                                                      accountName(firstNameIn + lastNameIn),
                                                                      accountFilePath(firstNameIn + lastNameIn + ".bank"),
                                                                      transactionFilePath(firstNameIn + lastNameIn + ".transactions")
{
    // Check if account exists
    if (checkFileExists(accountFilePath))
    {
        loadAccount();
        loadTransactions();
    };
};

// Constructor
void Account::createAccount()
{
    double initialBalance;
    createFiles();

    // Linux specific to clear terminal.
    system("clear");
    std::cout << "\n***Welcome To Account Creation***\n"
              << std::endl;
    std::cout << "Account Name: " << getAccountName() << std::endl;
    std::cout << "What Is Your Initial Deposit?: $";
    std::cin >> initialBalance;
    std::cout << std::endl;

    if (std::cin.good())
    {
        accountBalance = std::ceil(initialBalance * 100.0) / 100.0;
        saveAccount();
        std::cout << "Congratulations! Your Account Balance Is Now: $" << getAccountBalance() << std::endl;
        numOfTransactions = 0;
    }
    else
    {
        std::cout << "Invalid Deposit Input." << std::endl;
        exit(0);
    }
};

// Methods
void Account::createFiles()
{
    std::ofstream accountFile(accountFilePath);
    accountFile.close();

    std::ofstream transactionFile(transactionFilePath);
    transactionFile.close();
};

bool Account::checkFileExists(std::filesystem::path &filePath)
{
    accountExists = std::filesystem::exists(filePath) ? true : false;
    return getAccountExists();
};

void Account::showWelcomeMessage()
{
    loadAccount();

    // Linux specific to clear terminal.
    system("clear");
    std::cout << "****Welcome To Your Account " << firstName + " " + lastName + "****" << std::endl;
    std::cout << "****Account Name   : " << accountName << std::endl;
    std::cout << "****Account Balance:$" << accountBalance << std::endl;
    std::cout << "****Transactions   : " << numOfTransactions << std::endl;
};

void Account::saveAccount()
{
    std::string accountBalanceString = std::to_string(getAccountBalance());

    std::ofstream outfile;
    outfile.open(accountFilePath);
    outfile << firstName + " " + lastName + " " + accountBalanceString;
    outfile.close();
};

void Account::loadAccount()
{
    int i = 0;
    std::string firstNameIn, lastNameIn;
    double accountBalanceIn;

    std::ifstream infile;
    infile.open(accountFilePath);

    while (!infile.eof())
    {
        infile >> firstNameIn >> lastNameIn >> accountBalanceIn;
    };

    firstName = firstNameIn;
    lastName = lastNameIn;
    accountBalance = accountBalanceIn;

    infile.close();
};

void Account::saveTransactions()
{
    std::ofstream outfile;
    outfile.open(transactionFilePath);

    for (Transaction &transaction : transactions)
    {
        outfile << TransactionStructConverter::TransactionConversion(transaction.transactionType) + " " + transaction.transactionAmount + " " + std::to_string(transaction.balance) + " " + transaction.timestamp + "\n";
    }

    outfile.close();
};

void Account::loadTransactions()
{
    std::string tempTypeIn;

    TransactionType transTypeIn;
    std::string transAmountIn;
    double transBalanceIn;
    std::string transTimestampIn;

    std::ifstream infile;
    infile.open(transactionFilePath);

    while (!infile.eof())
    {
        infile >> tempTypeIn >> transAmountIn >> transBalanceIn >> transTimestampIn;
        transTypeIn = TransactionTypeConverter::transactionTypeConversion(tempTypeIn);

        Transaction transaction = {transTypeIn, transAmountIn, transBalanceIn, transTimestampIn};
        transactions.push_back(transaction);
    };

    infile.close();

    numOfTransactions = transactions.size();
};

void Account::depositToAccount(double &amountToDeposit)
{
    createTransaction(amountToDeposit);
    accountBalance += amountToDeposit;
    saveAccount();
}

bool Account::withdrawFromAccount(double amountToWithdraw)
{
    double negativeValue = amountToWithdraw * -1.0;
    bool toReturn;

    if (amountToWithdraw > accountBalance)
    {
        toReturn = true;
    }
    else
    {
        createTransaction(negativeValue);
        accountBalance -= amountToWithdraw;
        saveAccount();
        toReturn = false;
    }
    return toReturn;
};

void Account::createTransaction(double &amountToDiff)
{
    std::string transAmount = std::to_string(amountToDiff);
    TransactionType transType;
    double balanceToBe;
    time_t ttime = std::time(nullptr);
    std::string timestamp = std::to_string(uintmax_t(ttime));

    if (amountToDiff >= 0)
    {
        transType = TransactionType::DEPOSIT;
        balanceToBe = accountBalance + amountToDiff;
    }
    else
    {
        transType = TransactionType::WITHDRAWAL;
        balanceToBe = accountBalance - amountToDiff;
    }

    Transaction currentTranscation = {transType, transAmount, balanceToBe, timestamp};
    transactions.push_back(currentTranscation);
    numOfTransactions = transactions.size();

    saveTransactions();
};

void Account::removeAccount()
{
    std::filesystem::remove(accountFilePath);
};

// Getters
double Account::getAccountBalance() { return accountBalance; }

bool Account::getAccountExists() { return accountExists; }

std::string Account::getAccountName() { return accountName; }

int Account::getNumberOfTransactions() { return numOfTransactions; }

std::vector<Transaction> Account::getTransactions() { return transactions; }