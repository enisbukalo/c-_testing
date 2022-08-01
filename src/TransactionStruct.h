#ifndef transactionstruct_h
#define transactionstruct_h

#include <string>

#include "TransactionType.h"

struct Transaction
{
    TransactionType transactionType;
    std::string transactionAmount;
    double balance;
    std::string timestamp;
};

namespace TransactionStructConverter
{
    std::string TransactionConversion(TransactionType &);
};

#endif