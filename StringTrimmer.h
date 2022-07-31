#ifndef stringtrimmer_h
#define stringtrimmer_h
#include <string>
#include <locale>

std::string& capitalizeString(std::string& stringIn){
    for(int i=0; i<stringIn.length(); i++){
        stringIn[i] = std::tolower(stringIn[i]);
    }
    stringIn[0] = std::toupper(stringIn[0]);
    return stringIn;
};

std::string& trimString(std::string& stringIn){
    const char* whitespaceTypes = " \t\n\r\f\v";
    stringIn.erase(stringIn.find_last_not_of(whitespaceTypes)+1);
    stringIn.erase(0, stringIn.find_first_not_of(whitespaceTypes));
    return capitalizeString(stringIn);
};


#endif