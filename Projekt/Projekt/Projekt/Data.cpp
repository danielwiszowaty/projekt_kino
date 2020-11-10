#include "Data.hpp"
#include<iostream>
#include<cassert>
using namespace std;


Data::Data() : dzien(0), miesiac(0), rok(0) {}

Data::Data(int _dzien, int _miesiac, int _rok) : dzien(_dzien), miesiac(_miesiac), rok(_rok) {}

Data::~Data() {}

Data& Data::operator =(const Data& obj){
    if(this != &obj){
        this->dzien = obj.dzien;
        this->miesiac = obj.miesiac;
        this->rok = obj.rok;
    }
    return *this;
}

bool Data::operator ==(const Data& obj){
    return (this->dzien == obj.dzien && this->miesiac == obj.miesiac && this->rok == obj.rok);
}

bool Data::operator >=(const Data& obj){
    if(this->rok < obj.rok)
        return false;
    else if(this->rok > obj.rok)
        return true;
    else{
        if(this->miesiac < obj.miesiac)
            return false;
        else if(this->miesiac > obj.miesiac)
            return true;
        else{
            if(this->dzien < obj.dzien)
                return false;
            else if(this->dzien > obj.dzien)
                return true;
        }
    }
    return true;
}

bool operator >=(const Data& pierwsza, const Data& druga){
    if(pierwsza.rok < druga.rok)
        return false;
    else if(pierwsza.rok > druga.rok)
        return true;
    else{
       if(pierwsza.miesiac < druga.miesiac)
            return false;
        else if(pierwsza.miesiac > druga.miesiac)
            return true;
        else{
           if(pierwsza.dzien < druga.dzien)
                return false;
            else if(pierwsza.dzien > druga.dzien)
                return true;
        }
    }
    return true;
}

Data& Data::operator++(){
    if(this->czyKoniecMiesiaca()){
        if(this->miesiac == 12){
            this->dzien = 1;
            this->miesiac = 1;
            this->rok++;
        }
        else{
            this->dzien = 1;
            this->miesiac++;
        }
    }
    else this->dzien++;
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& data){
    os << data.dzien << "/" << data.miesiac << "/" << data.rok << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Data& data){
    is >> data.dzien >> data.miesiac >> data.rok;
    return is;
}

bool Data::czyKoniecMiesiaca() const{
    if(this->miesiac == 1 ||
       this->miesiac == 3 ||
       this->miesiac == 5 ||
       this->miesiac == 7 ||
       this->miesiac == 8 ||
       this->miesiac == 10 ||
       this->miesiac == 12)
        
        return this->dzien == 31;
    
    else if (this->miesiac == 2){
        if(this->rok % 4 != 0 || (this->rok % 100 == 0 && this->rok % 400 != 0))
            return this->dzien == 28;
        else
            return this->dzien == 29;
    }
    else
        return this->dzien == 30;
}

void Data::ustawDzien(const int _dzien){
    assert(dzien > 0);
    if(this->miesiac == 1 ||
       this->miesiac == 3 ||
       this->miesiac == 5 ||
       this->miesiac == 7 ||
       this->miesiac == 8 ||
       this->miesiac == 10 ||
       this->miesiac == 12)
        
        assert(dzien < 32);
    
    else if(this->miesiac == 2)
    {
        if(this->rok % 4 != 0 || (this->rok%100 == 0 && this->rok%400 != 0))
            assert(dzien < 29);
        else
            assert(dzien < 30);
    }
    else
        assert(dzien < 31);
    this->dzien = _dzien;
}

void Data::ustawMiesiac(const int _miesiac){
    this->miesiac = _miesiac;
}

void Data::ustawRok(const int _rok){
    this->rok = _rok;
}

int Data::zwrocRok() const{
    return this->rok;
}

int Data::zwrocMiesiac() const{
    return this->miesiac;
}

int Data::zwrocDzien() const{
    return this->dzien;
}

bool Data::czyDatyKoliduja(const Data pocz1, const Data koniec1, const Data pocz2, const Data koniec2){
    if((koniec2>=pocz1) && (koniec1>=pocz2))
        return true;
    return false;
}





