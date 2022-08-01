#include "TransactionStruct.h"

namespace TransactionStructConverter
{
    std::string TransactionConversion(TransactionType &transactionTypeIn)
    {
        switch (transactionTypeIn)
        {
        case DEPOSIT:
            return "DEPOSIT";
        case WITHDRAWAL:
            return "WITHDRAWAL";
        default:
            return "UNKNOWN";
        }
    }
}