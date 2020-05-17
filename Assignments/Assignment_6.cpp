//
// Created by lswar on 13/05/2020.
//

#include "Assignment_6.h"
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <cmath>
using namespace std;

//Zadanie 1
class Wektor{
    private:
        double x_;
        double y_;

    public:
    Wektor();
    Wektor(double x, double y);
    double lenght();
    Wektor multiply(double a);
    Wektor add(const Wektor &w);
    Wektor substract(const Wektor &w);
    Wektor normalize();
    string toString();

};

Wektor::Wektor() {
    x_ = 0.0;
    y_ = 0.0;
}

Wektor::Wektor(double x, double y) {
    x_ = x;
    y_ = y;
}

double Wektor::lenght() {
    return sqrt(pow(x_, 2.0) + pow(y_, 2.0));
}

Wektor Wektor::multiply(double a) {
    return Wektor(a*x_,a*y_);
}

Wektor Wektor::add(const Wektor &w) {
    return Wektor(x_ + w.x_, y_ + w.y_);
}

Wektor Wektor::substract(const Wektor &w) {
    return Wektor(x_ - w.x_, y_ - w.y_);
}

Wektor Wektor::normalize() {
    return Wektor(x_/lenght(),y_/lenght());
}

string Wektor::toString() {
    return "[" + to_string(x_) + ", " + to_string(y_) + "]";
}


//Zadanie 2
class Czas{
    private:
        int godz_;
        int minuty_;

    public:
    Czas(int hours, int minutes);
    Czas(string time);
    ~Czas();
    string toString() const;
    Czas add(const Czas &t) const;
    Czas subtract(const Czas &t) const;
    Czas multiply(int ile) const;
    static Czas sum(Czas *tab[], int n);
};

Czas::Czas(int hours, int minutes) {
    godz_ = hours;
    minuty_ = minutes;
}

Czas::Czas(string time) {
    stringstream ss;
    list <int> hours;
    /* Storing the whole string into string stream */
    ss << time;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
            hours.push_front(found);

        /* To save from space at the end of string */
        temp = "";
    }

    godz_ = hours.back();
    minuty_ = hours.front();

}

string Czas::toString() const {
    return to_string(godz_) + " h"  +  to_string(minuty_) + " min";
}

Czas Czas::add(const Czas &t) const {
    return Czas(godz_ + t.godz_, minuty_ + t.minuty_);
}

Czas Czas::subtract(const Czas &t) const {
    return Czas(godz_ - t.godz_, minuty_ - t.minuty_);
}

Czas Czas::multiply(int ile) const {
    return Czas(ile * godz_, ile * minuty_);
}

Czas Czas::sum(Czas **tab, int n) {
    Czas result(0,0);

    for(int i= 0; i < n; i++){
        result.add(*tab[i]);
    }
    return result;
}

Czas::~Czas() {
    cout << "Destrukt";
}

//Zadanie 3  //TODO: Add this



//Zadanie 4
class ElementZamowienia{
private:
    string nazwa_;
    double cena_;
    int liczbaSztuk_;
public:
    ElementZamowienia();
    ElementZamowienia(string nazwa, double cena, int liczbaSztuk);
    string toString();
    double obliczKoszt();
    double obliczRabat();

};

ElementZamowienia::ElementZamowienia() {}

ElementZamowienia::ElementZamowienia(string nazwa, double cena, int liczbaSztuk) {
    nazwa_ = nazwa;
    cena_ = cena;
    liczbaSztuk_ = liczbaSztuk;
}

string ElementZamowienia::toString() {
    return nazwa_ + " " + to_string(cena_) + " zł, " + to_string(liczbaSztuk_) + " szt., łącznie " + to_string(cena_*liczbaSztuk_) + " zł";
}

double ElementZamowienia::obliczRabat() {
    if(liczbaSztuk_ >= 5) {
        return 0.9 * cena_;
    } else return cena_;
}

double ElementZamowienia::obliczKoszt() {
    return liczbaSztuk_ * obliczRabat();
}

class Zamowienie{
    private:
        ElementZamowienia *elementy_;
        int rozmiar_;
        int maksRozmiar_;

    public:
        Zamowienie(int maksRozmiar);
        ~Zamowienie();
        bool dodaj(const ElementZamowienia &p);
        double obliczKoszt();
        void pisz();

};

Zamowienie::Zamowienie(int maksRozmiar) {
    elementy_ = new ElementZamowienia();
    maksRozmiar_ = maksRozmiar;
    rozmiar_ = 0;
}

Zamowienie::~Zamowienie() {
    delete elementy_;
}

double Zamowienie::obliczKoszt() {
    return 0;  //TODO: Add this
}

void Zamowienie::pisz() {
    //TODO: Add this
}

bool Zamowienie::dodaj(const ElementZamowienia &p) {
    for(int i = 0; i < maksRozmiar_; i++){
        if(i == rozmiar_){
            rozmiar_++;
            elementy_[i] = p;
            break;
        }
    }
    return true;
}







