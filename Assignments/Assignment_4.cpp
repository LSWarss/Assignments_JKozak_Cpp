
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


/*2. Napisać funkcję:
void szukaj(const char nazwaPlikWe[], const char nazwaPlikWy[],
            const char slowo[])
której zadaniem jest znalezienie wszystkich wierszy w pliku, które zawierają szukane słowo. Wszystkie wiersze, które zawierają słowo powinny zostać zapisane w
pliku wynikowym wraz z nr wiersza (z pierwszego pliku). Nazwa pierwszego pliku
        zapamiętana jest w parametrze nazwaPlikWe, nazwa pliku wynikowego podana
        jest w parametrze nazwaPlikWy, natomiast szukane słowo w parametrze slowo*/

void lookfor(const char *inFile, const char *outFile, const char *word) {
    fstream inStream;
    fstream outStream;
    string line;
    int lineNumber = 0;
    inStream.open(inFile, ios::in);
    outStream.open(outFile, ios::out);
    bool same = false;
    if (inStream.good()) {
        while (getline(inStream, line)) {
            lineNumber++;
            for (int i = 0; line[i] != '\0'; ++i) {
                if (line[i] == word[0] && (i == 0 || !isalpha(line[i - 1]))) {
                    same = true;
                    int j;
                    for (j = 0; word[j] != '\0'; j++) {
                        if (line[i + j] != word[j]) {
                            same = false;
                            break;
                        }
                    }
                    if (same && (line[i + j + 1] == '\0' || isalpha(line[i + j]))) {
                        same = false;
                    }
                    if (same) {
                        outStream << "Line number: " << lineNumber << ": " << line << endl;
                        cout << "lineNumber: " << line << endl;
                        break;
                    }
                }
            }
        }
    } else {
        cout << "Something went wrong";
    }
}

void retirement(char *fileName) {
    fstream inFile;
    fstream womanFile;
    fstream menFile;
    string line;
    inFile.open(fileName, ios::in);
    womanFile.open("woman.txt", ios::out);
    menFile.open("men.txt", ios::out);
    bool gender = false;
    int age;
    if (inFile.good()) {
        while (getline(inFile, line)) {
            string imie, nazwisko;
            int wiek = 0;
            char plec;
            int counter = 0;
            while (line[counter] != ' ') {
                imie += line[counter];
                counter++;
            }
            counter++;
            while (line[counter] != ' ') {
                nazwisko += line[counter];
                counter++;
            }
            counter++;
            plec = line[counter];
            counter ++;
            while(line[counter] != '\0'){
                counter++;
            }
            wiek = (line[counter - 1] - '0') + 10 * (line[counter - 2] - '0');
            if (plec == 'M'){
                menFile << nazwisko << " " << imie << " " << 65 - wiek << "\n";
            } else {
                womanFile << nazwisko << " " << imie << " " << 60 - wiek << "\n";
            }
        }
    }
}
