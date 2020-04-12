//
// Created by Stachnik, Lukasz on 11/04/2020.
//

#include "Assignment_4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/*1. Napisać funkcję, która w pliku tekstowym o podanej nazwie zlicza:
• liczbę znaków w pliku,
• liczbę białych znaków w pliku,
• liczbę słów w pliku.
Funkcja w standardowy sposób zwraca liczbę znaków w pliku, natomiast liczba
białych znaków oraz słów przekazywana jest przez parametr.*/
int count(char fileName[], int &white_signs, int &words){
    fstream file;
    file.open(fileName, ios::in);
    string line;
    char ch;
    int characterCount = 0;
    words = 1;


    cout << "Reading from the file: "  << endl;

    if(!file.good()){
        cout << "Something is wrong with the file" << endl;
        exit(0);
    }

    file.seekg(0, ios::beg);

    while(file)
    {
        file.get(ch);
        if(ch==' '||ch  == '\n')
            words++;
        else{
            characterCount++;
        }
    }
    return characterCount;
}

void szukaj(const char nazwaPlikWe[], const char nazwaPlikWy[], const char word[]){

}