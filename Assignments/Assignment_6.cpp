//
// Created by lswar on 13/05/2020.
//

#include "Assignment_6.h"
#include <string>
#include <iostream>

using namespace std;

class Czas{
    Czas(int hours, int minutes);
    Czas(string time);
    ~Czas();
    private:
        int godz_;
        int minuty_;

    public:
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
    //TODO: Add function taking string and making time from it
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










