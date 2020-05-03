//
// Created by lswar on 03/05/2020.
//

#include "Repetition_2.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

double przepisz(char* inputFile, int wiek){
    ifstream input(inputFile);

    if(!input.is_open()){
        cout << "Nie ma dostępu do pliku";
    }

    ofstream wyjsciowyM("wyjsciowyM.txt");
    ofstream wyjsciowyK("wyjsciowyK.txt");

    if(!wyjsciowyM.is_open() && !wyjsciowyK.is_open()){
        cout << "Nie ma dostępu do pliku";
    }

    double średniWiekM = 0;
    char płeć;
    string imie, nazwisko;
    double pensja;

    int i = 0, wiekTymczasowy;

    while (input >> imie >> nazwisko >> płeć >> wiekTymczasowy >> pensja){
        if(płeć == 'M'){
            wyjsciowyM << imie << nazwisko << wiekTymczasowy << pensja + pensja*((double)wiekTymczasowy/100) << endl;
            średniWiekM += pensja;
        }
        else if(płeć == 'K'){
            wiekTymczasowy > wiek ? (pensja += pensja * ((double) 5 / 100)) : (pensja == pensja * ((double)3/100));
            wyjsciowyK << imie << nazwisko << wiekTymczasowy << pensja << endl;
        }
        i++;
    }

    return średniWiekM/i;
}

int fif(char* pl, char* slowo, char* &wsk){
    ifstream input(pl);

    if(!input.is_open())
        cout << "Nie ma dostępu do pliku";

    char* pointer = wsk;
    string wyrazTymczasowy;


    int length = 0, rozwiązanie = -1, i = 0;

    while(input >> wyrazTymczasowy){
        if(wyrazTymczasowy == slowo) {
            rozwiązanie = 0;
        }
        if(wyrazTymczasowy.length() > length){
            length = wyrazTymczasowy.length();
            strcpy(pointer, wyrazTymczasowy.c_str());
            rozwiązanie = i;
        }
        i += wyrazTymczasowy.length() + 1;
    }

    return rozwiązanie;
}