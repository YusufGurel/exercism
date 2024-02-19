#include "armstrong_numbers.h"

// #include <string.h>
 #include <math.h>
// #include <stdio.h>
bool is_armstrong_number(int number) {
    
    // char teststr[20];
    // sprintf(teststr, "%d", number);
    // int len = strlen(teststr);
    // int sum = 0;
    // for (int i = 0; i < len; i++) {
    //     int digit = teststr[i] - '0';
    //     sum += pow(digit, len);
    // }

    int sum = 0;
    int digits = 0;

    for(int i = number; i > 0; i /= 10) {
        digits++;
    }

    for(int i = number; i > 0; i /= 10) {
        sum += pow(i % 10, digits);
    }

    
    return sum == number;
}