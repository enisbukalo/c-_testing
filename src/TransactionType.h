#ifndef transactiontype_h
#define transactiontype_h

#include <string>

enum TransactionType
{
    DEPOSIT,
    WITHDRAWAL
};

namespace TransactionTypeConverter
{
    TransactionType transactionTypeConversion(std::string &);
};

#endif