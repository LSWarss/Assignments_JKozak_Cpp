//
// Created by lswar on 25/05/2020.
//

#include "statki.h"

/*
 * Do napisanego programu (gry w statki) dodać następujące funkcje:
 *   1. Możliwość dodawania jednomasztowców, trójmasztowców i czteromasztowców. #DONE
 *   2. Dodać informację o zatopieniu statku (Statek).
 *   3. Dodać informację o zatopieniu wszystkich statków – koniec gry (Plansza).
 *   4. Możliwość dotykania przez statki ścian planszy.
 *   5. Pozwolić na pionowy układ statków.
 *   6. Stworzyć drugą planszę.
 *   7. Zezwolić użytkownikowi na ustawienie statków (zadana liczba każdego rodzaju) dla dwóch plansz.
 *   8. Pozwolić na grę pomiędzy dwoma użytkownikami.
 *   9. Pozwolić na inny układ większych statków.
 */


#include <iostream>
#include <rpcndr.h>

using namespace std;

class Statek {
public:
    virtual void rysuj(int x, int y){}
    virtual void traf(int x, int y){};
};

class Jednomasztowiec : public Statek {
private:
    int x, y;
    char poklad[1];
public:
    Jednomasztowiec(int x, int y) : x(x), y(y) {
        poklad[0] = '_';
    }
    virtual void rysuj(int x, int y){
        cout << poklad[y - this->y];
    }
    virtual void traf(int x, int y){
        poklad[y - this->y] = 'T';
    }

    boolean isSunk(){
        if(poklad[y - this->y] == 'T')
            return true;
        else return false;
    }
};

class Dwumasztowiec : public Statek {
private:
    int x, y;
    char poklad[2];
public:
    Dwumasztowiec(int x, int y) : x(x), y(y) {
        poklad[0] = '_';
        poklad[1] = '_';
    }
    virtual void rysuj(int x, int y){
        cout << poklad[y - this->y];
    }
    virtual void traf(int x, int y){
        poklad[y - this->y] = 'T';
    }
};

class Trojmasztowiec : public Statek {
private:
    int x, y, z;
    char poklad[3];
public:
    Trojmasztowiec(int x, int y) : x(x), y(y) {
        poklad[0] = '_';
        poklad[1] = '_';
        poklad[2] = '_';
    }
    virtual void rysuj(int x, int y){
        cout << poklad[y - this->y];
    }
    virtual void traf(int x, int y){
        poklad[y - this->y] = 'T';
    }
};

class Czteromasztowiec : public Statek {
private:
    int x, y, z;
    char poklad[4];
public:
    Czteromasztowiec(int x, int y) : x(x), y(y) {
        poklad[0] = '_';
        poklad[1] = '_';
        poklad[2] = '_';
        poklad[3] = '_';
    }
    virtual void rysuj(int x, int y){
        cout << poklad[y - this->y];
    }
    virtual void traf(int x, int y){
        poklad[y - this->y] = 'T';
    }
};


char getChar(int z){
    return z+'a';
}

int getInt(char z){
    return z-'a';
}

class Plansza {
private:
    int wys, szer;
    int lStatkow;
    Statek * statki[10];
    int ** mapa; //0 - wolne pole, -1 - pudło, x - numer statku.
public:
    Plansza(int wys, int szer);
    ~Plansza();
    int dajWys();
    int dajSzer();
    bool pustePole(int x, int y);
    void dodajStatek(int x, int y, int w);
    int dajLStatkow();
    void zniszczoneWszystkie();
    void strzel(int w, int k);
    void rysuj();
};

Plansza::Plansza(int wys, int szer){
    this->wys = wys;
    this->szer = szer;
    lStatkow = 0;

    mapa = new int*[wys];
    for(int i=0; i<szer; i++)
        mapa[i] = new int[szer];

    for(int i=0; i<wys; i++)
        for(int j=0; j<szer; j++)
            mapa[i][j]=-1;

    dodajStatek(2, 2, 2); //3 c
    dodajStatek(3, 3, 2); //4 d Kolizja
    dodajStatek(6, 3, 2); //7 d
    dodajStatek(4, 1, 2); //5 b
}

Plansza::~Plansza(){
    for(int i=0; i<dajWys(); i++)
        delete [] mapa[i];
    delete [] mapa;
    for(int i=0; i<lStatkow; i++)
        delete statki[i];
}

int Plansza::dajWys(){
    return wys;
}

int Plansza::dajSzer(){
    return szer;
}

bool Plansza::pustePole(int x, int y){
    if(x<dajWys() && x>0 && y<dajSzer() && y>0){
        bool wynik = true;
        for(int i=x-1; i<x+2; i++)
            for(int j=y-1; j<y+2; j++)
                if(mapa[i][j]!=-1)
                    wynik=false;
        return wynik;
    }
    return false;
}

void Plansza::dodajStatek(int x, int y, int w){
    bool wolne=true;
    for(int i=0; i<w; i++)
        if(!pustePole(x,y+1))
            wolne=false;
    if(wolne){
        for(int i=0; i<w; i++)
            mapa[x][y+i] = lStatkow;
        Statek *st;

        switch(w) {
            case 1:
                st = new Jednomasztowiec(x, y);
                statki[lStatkow++] = st;
                break;
            case 2:
                st = new Dwumasztowiec(x, y);
                statki[lStatkow++] = st;
                break;
            case 3:
                st = new Trojmasztowiec(x, y);
                statki[lStatkow++] = st;
                break;
            case 4:
                st = new Czteromasztowiec(x, y);
                statki[lStatkow++] = st;
                break;
        }
    }
    else
        cout << endl << "Bledna pozycja statku" << endl << endl;
}

void Plansza::strzel(int w, int k){
    if(mapa[w][k]>=0)
        statki[mapa[w][k]]->traf(w,k);
    else
        mapa[w][k]=-2;
}

void Plansza::zniszczoneWszystkie(){
    for (int i = 0; i < dajSzer(); ++i) {
        for (int j = 0; j < dajWys(); ++j) {
            strzel(i, j);
        }

    }
}

void Plansza::rysuj(){
    cout << ' ';
    for(int j=0; j<dajSzer(); j++)
        cout << ' ' << getChar(j);
    cout << endl;
    for(int i=0; i<dajWys(); i++){
        cout << i+1;
        for(int j=0; j<dajSzer(); j++)
            switch(mapa[i][j]) {
                case -2: cout << ' ' << 'X'; break;
                case -1: cout << ' ' << '_'; break;
                default: cout << ' '; statki[mapa[i][j]]->rysuj(i, j);
            }
        cout << endl;
    }
    cout << "____________________" << endl << endl;
}

int main() {
    Plansza pl(8, 8);
    pl.rysuj();

    int statki = pl.dajLStatkow();
    bool graWTrakcie = true;
    while (graWTrakcie) {
        if(statki != pl.dajLStatkow()){
            statki = pl.dajLStatkow();
            cout << "Zatopiono statki!" << endl;
        }

        int l;
        char z;
        //cout << "Strzel (wiersz - liczba, kolumna - znak): ";
        //cin >> l >> z;

        //pl.shoot(l-1, getInt(z));
        //pl.draw();

        //pl.shoot(l-1, getInt(z));
        pl.zniszczoneWszystkie();
        pl.rysuj();
        if(pl.dajLStatkow() == 0)
            graWTrakcie = false;
    }


    return 0;
}