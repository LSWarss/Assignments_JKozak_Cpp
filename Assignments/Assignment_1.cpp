//
// Created by LSWarss on 11/03/2020.
//

#include <iostream>
#include "Assignment_1.h"

using namespace std;

// Zadanie 9
void drukuj(int n){
    if(n > 0 && n < 6){
        for(int i = 0; i <= 8; i++){
            for(int j = 0; j <= 8; j++){
                if((i == 0 && j == 7) || (i == 0 && j == 0) || (i == 7 && j == 0) || (i == 7 && j == 7)){
                    cout << "+";
                }
                else if((i == 0 && j != 7 && j != 0 && j != 8) || (i == 7 && j != 0 && j != 7 && j != 8)){
                    cout << "-";
                }
                else if((i > 0 && i < 7 && j == 0) || (i > 0 && i < 7 && j == 7)){
                    cout << "|";
                }
                else if((i > 0 && i < 7 && i % 2 != 0 && j > 0 && j < 7 && j % 2 == 0))
                {
                    for(int c = 0; c < n; c++){
                        cout << "#";
                    }
                }
                else if((i > 0 && i < 7 && i % 2 == 0 && j > 0 && j < 7 && j % 2 != 0)) {
                    for (int c = 0; c < n; c++) {
                        cout << "#";
                    }
                }
                else if(j == 8){
                    cout << endl;
                }
                else{
                    cout << " ";
                }
            }
        }
    }
    else{
        cout << "Niepoprawna liczba n (musi być w przedziale od 1 do 5)" << endl;
        cin >> n;
        drukuj(n);
    }
}

//Zadanie 8
void czy_pierwsza(int n)
{
    if(n<2) {
        cout << "Liczba nie jest pierwsza" << endl; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą
    }
    for(int i=2;i*i<=n;i++) {
        if (n % i == 0) {
            cout << "Liczba nie jest pierwsza" << endl; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
        }
        cout << "Liczba jest pierwsza" << endl;
    }
}
// Zadanie 7
void czy_palindrom(int n){
    int number, digit, reverse = 0;
    number = n;
    if(n > 0){
        do{
            digit = number % 10;
            reverse = (reverse * 10) + digit;
            number = number / 10;
        }
        while (number != 0);
    }
    else {
        cout << "Liczba musi być dodatnia! Wprowadź jeszcze raz: ";
        cin >> n;
        czy_palindrom(n);
    }

    if(n == reverse){
        cout << "Liczba jest palindromem" << endl;
    }
    else{
        cout << "Liczba nie jest palindromem" << endl;
    }
}
// Zadanie 6
int suma_cyfr(int n){
    int number, digit, sum = 0;
    number = n;
    do{
        digit = number % 10;
        sum += digit;
        number = number / 10;
    }
    while (number != 0);

    return sum;
}

void stosunek_liczb(int n){
    int number, digit,sumP = 0, sumN = 0, iteratorP = 0, iteratorN = 0;
    number = n;
    do{
        digit = number % 10;
        if(digit % 2 != 0){
            sumN += digit;
            iteratorN++;
        }
        else{
            sumP += digit;
            iteratorP++;
        }
        number = number / 10;
    }
    while(number != 0);

    int sredniaP = sumP / iteratorP;
    int sredniaN = sumN / iteratorN;
    cout << "Srednia arytmetyczna cyfr parzystych: " << sredniaP << endl;
    cout << "Srednia arytmetyczna cyfr nieparzystych: " << sredniaN << endl;

    if(sredniaN > sredniaP){
        cout << "Stosunek tych srednich to: " << sredniaP%sredniaN << endl;
    }
    else{
        cout << "Stosunek tych srednich to: " << sredniaN%sredniaP << endl;
    }
}

// Zadanie 5
void choinka(int n){
    int down = n - 2, up = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2 - 1; j++ ){
            if(i == 0 && j == n-1){
                cout << "+";
            }
            else if(i != 0 && j >= down && j <= up){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        if(i > 0){
            up ++;
            down --;
        }
        cout << endl;
    }
}
// Zadanie 4
/*Napisać program działający w trybie konsolowym (tekstowym) i rysujący na ekranie prostokąt. Użytkownik podaje znak wypełnienia prostokąta, pozycję lewego
górnego rogu prostokąta (x, y) oraz długości boków prostokąta (ab). Przyjmujemy,
że lewy górny narożnik konsoli ma współrzędne (x, y) = (1, 1).*/
void prostokat(int x, int y, char wyp, int a, int b)
{
    for(int i = 0; i < y+a; i++){
        for(int j = 0; j < x+b; j++){
            if(i >= y && j >= x){
                cout << wyp;
            }
            else if(i >= y && j <= x){
                cout << "_";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

//Zadanie 3
/*Napisać program, który pobiera od użytkownika ciąg liczb całkowitych. Pobieranie
danych kończone jest podaniem wartości 0 (nie wliczana do danych). W następnej kolejności program powinien wyświetlić sumę największej oraz najmniejszej z
podanych liczb, średnią arytmetyczną wprowadzonych liczb, a także ile z wprowadzonych liczb było jest większych od średniej.*/
//TODO: Poprawić tą pętle
void ciag() {
    int n, sum = 0, min = 0, max = 0, iterator = 0;
    cout << "Podaj ciag liczb: " << endl;
    while(n != 0){
        cin >> n;
        sum += n;
        iterator++;
        if(n > max && n != 0){
            max = n;
        }
        else if(n < min && min < max && n != 0){
            min = n;
        }
    }


    cout << "Średnia arytmetyczna to: " << sum / iterator << endl;
    cout << "Suma największej i najmniejszej to: " << max + min;
}

// Zadanie 2
/*. Napisać program pobierający od użytkownika dwie liczby całkowite A oraz B,
A < B, a następnie wyznaczający sumę ciągu liczb (A, A + 1, . . . , B). Obliczenia
należy wykonać trzykrotnie stosując kolejno pętle: while, do-while, for.
*/
void suma_ciagu(int A, int B){
    cout << "Wykonanie whilem" << endl;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    while(A <= B){
        sum1 += A;
        A++;
    }
    cout << "Suma while : " << sum1 << endl;
    cout << "Wykonanie do whilem" << endl;
    do{
        sum2 +=A;
        A++;
    }
    while(A <= B);
    cout << "Suma do while : " << sum2 << endl;
    cout << "Wykonanie forem: " << endl;
    for(int i = A; i <= B; i++){
        sum3 += A;
        A++;
    }
    cout << "Suma fora : " << sum3 << endl;

}
