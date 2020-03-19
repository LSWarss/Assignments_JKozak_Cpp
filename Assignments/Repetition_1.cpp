//
// Created by LSWarss on 19/03/2020.
//
#include <iostream>
#include <string>
#include "Repetition_1.h"


// 1. Konwerter
void convert(char a[]){
    int convertCount = 0;
    char b[std::char_traits<char>::length(a)];
    for(int i = 0; i < std::char_traits<char>::length(a); i++) {
        if (a[i] == '0' || a[i] == '2' || a[i] == '4' || a[i] == '6' || a[i] == '8') {
            b[i] = '.';
            convertCount++;
        } else if ((a[i] == '1' || a[i] == '3' || a[i] == '5' || a[i] == '7' || a[i] == '9') &&
                   a[i + 1] < std::char_traits<char>::length(a)) {
            b[i] = a[i + 1];
            convertCount++;
        } else if (a[i] == 'L' || a[i] == 'l' || a[i] == 's' || a[i] == 'S') {
            b[i] = '*';
            convertCount++;
        } else {
            b[i] = a[i];
        }
    }

    for(int i = 0; i < std::char_traits<char>::length(a); i++){
        std::cout << b[i];
    }
    std::cout << std::endl;
    std::cout << "Liczba konwersji: " << convertCount << std::endl;

}

//2. Suma cyfr
int sum(char s[]){
    int numberArray[std::char_traits<char>::length(s)];
    int sum = 0;
    for(int i = 0; i < std::char_traits<char>::length(s);i++){
        if((int)s[i] >= 48 && (int)s[i] <= 57){
            numberArray[i] = (int)s[i] - '0';
        }
        else{
            numberArray[i] = 0;
        }
    }

    for(int x : numberArray){
        sum += x;
    };

    return sum;
}


