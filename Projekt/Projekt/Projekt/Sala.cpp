#include "Sala.hpp"
#include <cassert>
#include <utility>
#include <ostream>

Sala::Sala() : numer(0), rzad(15), kolumna(15) {}

Sala::Sala(int _numer, int _rzad, int _kolumna) : numer(_numer), rzad(_rzad), kolumna(_kolumna) {}

Sala::Sala(int _numer) : numer(_numer), rzad(15), kolumna(15) {}

Sala::Sala(const Sala& obj){
    this->numer = obj.numer;
    this->rzad = obj.rzad;
    this->kolumna = obj.kolumna;
}

Sala& Sala::operator=(const Sala& obj){
    if(this != &obj){
        this->numer = obj.numer;
        this->rzad = obj.rzad;
        this->kolumna = obj.kolumna;
    }
    return *this;
}

Sala& Sala::operator=(const Sala&& obj){
    this->numer = std::move(obj.numer);
    this->rzad = std::move(obj.rzad);
    this->kolumna = std::move(obj.kolumna);
    return *this;
}
 

std::ostream& operator<<(std::ostream& os, const Sala& sala){
    os<<"Sala numer: "<<sala.zwrocNumer()<<" o pojemnosci: "<<sala.zwrocPojemonsc()<<std::endl;
    return os;
}

int Sala::zwrocNumer() const{
    return this->numer;
}

int Sala::zwrocRzad() const{
    return this->rzad;
}

int Sala::zwrocKolumne() const{
    return this->kolumna;
}

int Sala::zwrocPojemonsc() const{
    return this->rzad * this->kolumna;
}

void Sala::ustawRzad(int _rzad){
    this->rzad = _rzad;
}

void Sala::ustawKolumne(int _kolumna){
    this->kolumna = _kolumna;
}

void Sala::ustawNumer(int _numer){
    this->numer = _numer;
}

