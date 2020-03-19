//
// Created by LSWarss on 11/03/2020.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

//Zadanie 1
//Napisz program, który:
//• utworzy tablicę 10 liczb rzeczywistych i wypełni ją wartościami losowymi z
//przedziału [3.0, . . . , 9.0),
//• wyznaczy średnią arytmetyczną elementów tablicy,
//• wyznaczy ile elementów jest mniejszych, ile większych od średniej.
//Na ekranie należy wypisać wylosowane liczby w oryginalnej oraz odwrotnej kolejności, a także wszystkie wyznaczone wartości
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void arrayT(){
    double randomsArray[10];
    double sum = 0, avg, smaller = 0, bigger = 0;
    double lower_bound = 3.0, upper_bound = 9.0;
    std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
    std::default_random_engine re;
    for(int x : randomsArray){
        x = fRand(3.0, 9.0);
        sum += x;
    }

    std::cout << "Normal array: " << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << randomsArray[i] << " ";
    }
    std::cout << "\nReversed array: " << std::endl;
    for(int i = 10; i > 0; i--){
        std::cout << randomsArray[i] << " ";
    }
    avg = sum / 10;
    std::cout << "\nAverage: " << avg << std::endl;
    for(double x : randomsArray){
        if(x < avg){
            smaller++;
        }
        else{
            bigger++;
        }
    }
    std::cout << "Smaller then average: " << smaller << std::endl;
    std::cout << "Bigger then average: " << bigger << std::endl;
}

//Zadanie 5. Napisz program, który pobiera od użytkownika łańcuch znaków o maks. długości 40 znaków i sprawdza, czy jest on palindromem. W przypadku gdy podany
//tekst nie jest palindromem program powinien wyświetlić minimalną liczbę zmian
//znaków potrzebną, by zmienić podany ciąg w palindrom.
void palindrom_count(std::string word){
    std::string string;
    int length= word.length();
    if(length > 40){
        std::cout << "Za długi wyraz wprowadz raz jeszcze " << std::endl;
        std::cin >> string;
        palindrom_count(string);
    }
    else{
        int reversCount = 0;
        for(int i = 0; i < length/2 - 1; i++){
            if(word[i] != word[length-i-1]){
                reversCount++;
            }
        }
        if(reversCount == 0){
            std::cout << "Wyraz jest palindromem" << std::endl;
        }
        else{
            std::cout << "Ilość zmian aby stworzyć palindrom: " << reversCount << std::endl;
        }
    }

}

//Zadanie 4
//Napisz program, który wczytuje od użytkownika tekst znak po znaku aż do naciśnięcia sekwencji CTRL+Z oznaczającej koniec ciągu (EOF). Program powinien
//wyświetlić:
//• liczbę białych znaków w tekście,
//• liczbę liter w tekś+cie,
//• liczbę samogłosek w tekście (tylko z alfabetu angielskiego),
//• sumę wszystkich cyfr w podanym tekście.
void stringCounter(){
    std::string stream;
    int spaces = 0, vowel = 0, letters = 0, numberSum = 0;
    while(std::getline(std:: cin, stream)){
        for(int i = 0; i < stream.length() - 1; i++){
            if((int)stream[i] == 32){
                spaces++;
            }
            if(((int)stream[i] >= 65 && (int)stream[i] <= 90) || ((int)stream[i] >= 97 && (int)stream[i] < 122)){
                letters++;
            }
            if((int)stream[i] == 65 || (int)stream[i] == 97 || (int)stream[i] == 69 || (int)stream[i] == 101 || (int)stream[i] == 73 || (int)stream[i] == 105 || (int)stream[i] == 79 || (int)stream[i] == 111 ||
               (int)stream[i] == 85 || (int)stream[i] == 117){
                vowel++;
            }
            if((int)stream[i] == 49){
                numberSum++;
            }
            else if((int)stream[i] == 50){
                numberSum += 2;
            }
            else if((int)stream[i] == 51){
                numberSum += 3;
            }
            else if((int)stream[i] == 52){
                numberSum += 4;
            }
            else if((int)stream[i] == 53){
                numberSum += 5;
            }
            else if((int)stream[i] == 54){
                numberSum += 6;
            }
            else if((int)stream[i] == 55){
                numberSum += 7;
            }
            else if((int)stream[i] == 56){
                numberSum += 8;
            }
            else if((int)stream[i] == 57){
                numberSum += 9;
            }
        }

        std::cout << "Białe znaki:  " << spaces << std::endl;
        std::cout << "Litery: " << letters << std::endl;
        std::cout << "Samogłoski: " << vowel << std::endl;
        std::cout << "Suma cyfr: " << numberSum << std::endl;
    }
}

