#include <string>
#include <iostream>
#include "Bilet.hpp"
#include "Sala.hpp"
#include "Data.hpp"

void Bilet::przypisz(const Bilet& obj){
    this->ID = obj.ID;
    this->nazwaFilmu = obj.nazwaFilmu;
    this->status = obj.status;
    this->rzad = obj.rzad;
    this->kolumna = obj.kolumna;
}

Bilet::Bilet() : ID("Brak"), nazwaFilmu(""), sala(nullptr), data(Data()), rzad(0), kolumna(0), status(Status::DOSTEPNY) {}

Bilet::Bilet(const Sala* sala) : ID("Brak"), nazwaFilmu(""), sala(sala), data(Data()), rzad(0), kolumna(0), status(Status::DOSTEPNY) {}

Bilet::Bilet(const Sala* _sala, const std::string& _nazwa, const Data& _data, int _rzad, int _kolumna, const Status& _status){
    this->sala = _sala;
    this->data = _data;
    
    char IDfilmu[21];
    IDfilmu[0] = '0' + this->data.zwrocDzien() / 10;
    IDfilmu[1] = '0' + this->data.zwrocDzien() % 10;
    
    IDfilmu[2] = '0' + this->data.zwrocMiesiac() / 10;
    IDfilmu[3] = '0' + this->data.zwrocMiesiac() % 10;
    
    IDfilmu[4] = '0' + this->data.zwrocRok() / 1000;
    IDfilmu[5] = '0' + (this->data.zwrocRok() / 100) % 10;
    IDfilmu[6] = '0' + (this->data.zwrocRok() / 10) % 10;
    IDfilmu[7] = '0' + this->data.zwrocRok() % 10;
    
    IDfilmu[8] = '|';
    
    IDfilmu[9] = '0' + this->sala->zwrocNumer() / 100;
    IDfilmu[10] = '0' + ( this->sala->zwrocNumer() / 10 ) % 10;
    IDfilmu[11] = '0' + this->sala->zwrocNumer() % 10;

    IDfilmu[12] = '|';
    
    IDfilmu[13] = '0' + this->rzad / 100;
    IDfilmu[14] = '0' + ( this->rzad / 10 ) % 10;
    IDfilmu[15] = '0' + this->rzad % 10;

    IDfilmu[16] = '|';
    
    IDfilmu[17] = '0' + this->kolumna / 100;
    IDfilmu[18] = '0' + ( this->kolumna / 10 ) % 10;
    IDfilmu[19] = '0' + this->kolumna % 10;

    IDfilmu[20] = '|';
    
    this->rzad = _rzad;
    this->kolumna = _kolumna;
    this->nazwaFilmu = _nazwa;
    this->ID = IDfilmu;
    this->ID += this->nazwaFilmu;
}

Bilet& Bilet::operator =(const Bilet& obj){
    if(this != &obj)
        przypisz(obj);
    return *this;
}

std::string Bilet::zwrocID() const{
    return this->ID;
}

std::string Bilet::zwrocNazweFilmu() const{
    return this->nazwaFilmu;
}

const Sala* Bilet::zwrocSale() const{
    return this->sala;
}

Data Bilet::zwrocDate() const{
    return this->data;
}

const int Bilet::zwrocRzad() const{
    return this->rzad;
}

const int Bilet::zwrocKolumne() const{
    return this->kolumna;
}

Status Bilet::zwrocStatus() const{
    return this->status;
}

std::string Bilet::zwrocStatusJakoNapis() const{
    switch (this->zwrocStatus()) {
        case Status::REZERWACJA:
            return "Rezerwacja";
            break;
        case Status::SPRZEDANY:
            return "Sprzedany";
            break;
        case Status::DOSTEPNY:
            return "Dostepny";
            break;
            
        default:
            break;
    }
    return "";
}

void Bilet::ustawID(const std::string _ID){
    this->ID = _ID;
}

void Bilet::ustawNazweFilmu(const std::string _nazwa){
    this->nazwaFilmu = _nazwa;
}

void Bilet::ustawSale(const Sala* _sala){
    this->sala = _sala;
}

void Bilet::ustawDate(const Data& _data){
    this->data = _data;
}

void Bilet::ustawRzad(int _rzad){
    this->rzad = _rzad;
}

void Bilet::ustawKolumne(int _kolumna){
    this->kolumna = _kolumna;
}

void Bilet::ustawStatus(const Status& _status){
    this->status = _status;
}

void Bilet::wypisz() const{
    std::cout<<this->nazwaFilmu<<this->sala->zwrocPojemonsc()<<this->rzad<<this->kolumna;
}

std::ostream& operator<<(std::ostream& os, const Bilet& bilet){
    os << "Bilet za film: "
              << bilet.nazwaFilmu << std::endl
              << "data: " <<
    bilet.data;
    os << "sala: "
              << bilet.zwrocSale()->zwrocNumer() << std::endl
              << "rzad: "
              << bilet.zwrocRzad() << std::endl
              << "kolumna: "
              << bilet.zwrocKolumne() << std::endl
              << "status: "
              << bilet.zwrocStatusJakoNapis() << std::endl;
    return os;
}


