//
// Created by lswar on 11/03/2020.
//

#include "Assignment_3.h"

#include <iostream>
#include <float.h>
#include <algorithm>
#include <cstdarg>
#include <cmath>


//Zestaw 4
//Zadanie 1
double min(double tap[], int rozmiar){
    double min = DBL_MAX;
    for(int x = 0; x < rozmiar; x++){
        if(tap[x] < min) {
            min = tap[x];
        }
    }
    return min;
}

void max_ref(double tap[], int rozmiar, double& wynik){
    wynik  = DBL_MIN;
    for(int i = 0; i < rozmiar; i++){
        if(tap[i] > wynik){
            wynik = tap[i];
        }
    }
}

//Zadanie 2
int analiza(int tap[], int rozmiar, float& mediana, float& srednia){
    int suma = 0;
    std::sort(&tap[0], &tap[rozmiar]);
    for(int i = 0; i < rozmiar; i++){
        suma += tap[i];
    }
    mediana = rozmiar % 2 ? tap[rozmiar/2] : (tap[rozmiar / 2 - 1] + tap[rozmiar / 2 + 1]) / 2;
    srednia = suma/rozmiar;
    return suma;
}

//Zadanie 3
double obl_wiel(double x, int n, ...){
    va_list v1;
    va_start(v1, n);

    double wynik = 0;

    while(n > -1){
        wynik += std::pow(x, n) * va_arg(v1, int);
        n--;
    }
    va_end(v1);
    return wynik;
}

//Zadanie 4  - niestety tylko iteracyjne
void dywan(int n){
    int i, j, dim, d;
    int depth = n-1;
    for (i = 0, dim = 1; i < depth; i++, dim *= 3) {
        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                for (d = dim / 3; d; d /= 3)
                    if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
                        break;
                printf(d ? " " : "#");
            }
            printf("\n");
        }
    }
}

//Zadanie 5
void polacz(int tab1[], int tab2[], int rozmiar1, int rozmiar2){
    int tab3[rozmiar1+rozmiar2];
    for(int i = 0; i < (rozmiar1+rozmiar2); i++){
        if(i % 2 == 0){
            tab3[i] == tab1[i];
        }
        else if(i % 2 != 0){
            tab3[i] == tab2[i];
        }
    }
    for(int x : tab3) {
        std::cout << x << " ";
        std::cout << std::endl;
    }
}



//Zestaw 5
//Zadanie 1
int strpos(char str[], char z){
    for(int i = 0; i < (sizeof(str)/ sizeof(*str)); i++){
        if(str[i] == z){
            return i;
        }
    }
}