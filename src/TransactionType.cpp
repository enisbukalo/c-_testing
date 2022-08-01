#include "TransactionType.h"

namespace TransactionTypeConverter
{
    TransactionType transactionTypeConversion(std::string &typeIn)
    {
        if (typeIn == "DEPOSIT")
            return DEPOSIT;
        else
            return WITHDRAWAL;
    };
};