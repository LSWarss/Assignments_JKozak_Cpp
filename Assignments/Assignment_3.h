//
// Created by LSWarss on 11/03/2020.
//

#ifndef ASSIGNMENTS_JKOZAK_CPP_ASSIGNMENT_3_H
#define ASSIGNMENTS_JKOZAK_CPP_ASSIGNMENT_3_H

extern double min(double tap[], int rozmiar);
extern void max_ref(double tap[], int rozmiar, double& wynik);
extern int analiza(int tap[], int rozmiar, float& mediana, float& srednia);
extern double obl_wiel(double x, int n, ...);
extern void polacz(int tab1[], int tab2[], int rozmiar1, int rozmiar2);
extern int strpos(char str[], char z);
extern void dywan(int n);
extern void printSierpinski(int n);
extern int strint(char str[]);
extern int strfind(char gdzie[], char co[]);
extern void strcut(char lan[], int od, int ile);
extern bool strprefix(char str1[], char str2[]);
extern int strcountfind(char gdzie[], char co[]);
extern void szyfruj(const char tekst[], int przesuniecie, char wynik[]);
extern void deszyfruj(char tekst[], int przesuniecie);
#endif //ASSIGNMENTS_JKOZAK_CPP_ASSIGNMENT_3_H
