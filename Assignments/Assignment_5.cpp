#include "Assignment_5.h"
#include <iostream>

using namespace std;

/*Napisz funkcję void minMax(int tab[], int w, int* wmin, int* wmax) ,
 * która szuka w podanym ciągu najmniejszego i największego elementu.
 * Znalezione wartości mają zostać zapisane w zmiennych wskazywanych przez parametry
 * (wskaźniki) wmin oraz wmax .Parametr dl określa liczbę elementów w ciągu (tablicy) tab.*/
void minMax(int tab[], int w, int* wmin, int* wmax) {
    *wmax = tab[0];
    *wmin = tab[0];
    for(int i = 0; i < w; i++) {
        if(*wmax < tab[i]) {
            *wmax = tab[i];
        }
        if(*wmin > tab[i]) {
            *wmin = tab[i];
        }
    }
}

/*Zdefiniuj funkcję:void strsl(char s1[], char s2[], char* &dluzszy, char* &krotszy) ,
 *która przyjmuje jako parametry dwa łańcuchy ( s1 oraz s2 ) i dwa wskaźniki
 *( dluzszy , krotszy ). Funkcja ta ma przypisać wskaźnikom dluzszy i krotszy
 *odpowiednio adres dłuższego oraz krótszego z podanych łańcuchów. W przypadku, gdy są one równej długości to wskaźnik dluzszy ma wskazywać na s1 ,
 *natomiast wskaźnik krotszy na łańcuch s2 .*/
void strls(char s1[], char s2[], char* &dluzszy, char* &krotszy){
    if(my_strlen(s1) > my_strlen(s2)){
        dluzszy = s1;
        krotszy = s2;
    }
    else if(my_strlen(s1) == my_strlen(s2)){
        dluzszy = s1;
        krotszy = s2;
    }
    else{
        dluzszy = s2;
        krotszy = s1;
    }
}

unsigned int my_strlen(char *p)
{
    unsigned int count = 0;

    while(*p!='\0')
    {
        count++;
        p++;
    }

    return count;
}

/*Napisz funkcję void ptradv(int* wsk, int n) , która wyświetla adres przechowywany we wskaźniku wsk oraz wartość zmiennej przez niego wskazywanej.
 *W kolejnym kroku funkcja przesuwa wskaźnik ( wsk += 1 ) i powtarza powyższe
 *czynności tyle razy ile wynosi wartość parametru n.*/
void ptradv(int* wsk, int n){
    for(int i = 0; i < n; i++){
        cout << "Address: " << &wsk[i] << " Number: " << wsk[i] <<endl;
        wsk += 1;
    }
}