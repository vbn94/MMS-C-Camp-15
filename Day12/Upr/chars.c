#include "chars.h"
#include <string.h>

int isAlpha(char sym){
   //return (sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z');
   return isUpper(sym) || isLower(sym);
}

int isDigit(char sym){
    return sym >= '0' && sym <= '9';
}

int isLower(char sym){
    return sym >= 'a' && sym <= 'z';
}

int isUpper(char sym){
    return sym >= 'A' && sym <= 'Z';
}

int toInt(const char* str, int* number){
    int sign = 1;
    if (str[0] == '-'){
        sign = -1;
    }
    *number = 0;
    unsigned power = 1;
    for (int i = strlen(str) - 1; i >= 0; i--){
        if ((str[i] == '-' || str[i] == '+') && i == 0){
            continue;
        }
        if (!isDigit(str[i])){
            return -1;
        }
        *number += (str[i] - '0') * power;
        power *= 10;
    }
    *number *= sign;
    return 0;
}

int toDouble(const char* str, double* number){
    
    return 0;
}