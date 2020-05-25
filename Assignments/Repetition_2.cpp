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

    double sredniWiek = 0;
    char plec;
    string imie, nazwisko;
    double pensja;

    int i = 0, wiekTymczasowy;

    while (input >> imie >> nazwisko >> plec >> wiekTymczasowy >> pensja){
        if(plec == 'M'){
            wyjsciowyM << imie << nazwisko << wiekTymczasowy << pensja + pensja*((double)wiekTymczasowy/100) << endl;
            sredniWiek += pensja;
        }
        else if(plec == 'K'){
            wiekTymczasowy > wiek ? (pensja += pensja * ((double) 5 / 100)) : (pensja == pensja * ((double)3/100));
            wyjsciowyK << imie << nazwisko << wiekTymczasowy << pensja << endl;
        }
        i++;
    }

    return sredniWiek / i;
}

int fif(char* pl, char* slowo, char* &wsk){
    ifstream input(pl);

    if(!input.is_open())
        cout << "Nie ma dostępu do pliku";

    char* pointer = wsk;
    string wyrazTymczasowy;


    int length = 0, rozwiazanie = -1, i = 0;

    while(input >> wyrazTymczasowy){
        if(wyrazTymczasowy == slowo) {
            rozwiazanie = 0;
        }
        if(wyrazTymczasowy.length() > length){
            length = wyrazTymczasowy.length();
            strcpy(pointer, wyrazTymczasowy.c_str());
            rozwiazanie = i;
        }
        i += wyrazTymczasowy.length() + 1;
    }

    return rozwiazanie;
}