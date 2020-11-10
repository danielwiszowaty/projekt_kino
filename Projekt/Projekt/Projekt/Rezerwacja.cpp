#include "Rezerwacja.hpp"

void Rezerwacja::przypisz(const Rezerwacja& obj){
    this->nazwa = obj.nazwa;
    this->data = obj.data;
    this->sala = obj.sala;
    this->iloscWizyt = obj.iloscWizyt;
    
    for(int i = 0; i < this->sala->zwrocRzad(); i++)
        this->bilety.push_back(std::vector<Bilet*>());
    for(int i=0; i < this->sala->zwrocRzad(); i++){
        for(int j=0; j < this->sala->zwrocKolumne(); j++)
            this->bilety[i].push_back(obj.bilety[i][j]);
    }
}

void Rezerwacja::usun(){
    for(int i=0; i<bilety.size(); i++)
        this->bilety[i].clear();
    this->bilety.clear();
}

Rezerwacja::Rezerwacja() : nazwa(""), data(Data()), bilety(), sala(nullptr), iloscWizyt(0) {}

Rezerwacja::Rezerwacja(const std::string& _nazwa, const Data& data, const Sala* sala){
    this->sala = sala;
    this->data = data;
    this->nazwa = _nazwa;
    
    
    for(int i=0; i < this->sala->zwrocRzad(); i++)
    {
        this->bilety.push_back(std::vector<Bilet*>());
        for(int j=0; j < this->sala->zwrocKolumne(); j++)
            this->bilety[i].push_back(new Bilet(this->sala, this->nazwa, this->data, i, j, Status::DOSTEPNY));
    }
}

Rezerwacja& Rezerwacja::operator =(const Rezerwacja& obj){
    if(this != &obj){
        usun();
        przypisz(obj);
    }
    return *this;
}

Rezerwacja::~Rezerwacja(){
    usun();
}

std::string Rezerwacja::zwrocNazwe() const{
    return this->nazwa;
}

Data Rezerwacja::zwrocDate() const{
    return this->data;
}

int Rezerwacja::zwrocIleSprzedanych() const{
    int ile = 0;
    for(int i=0; i < this->sala->zwrocRzad(); i++)
        for(int j=0; j < this->sala->zwrocKolumne(); j++)
        {
            if(this->bilety[i][j]->zwrocStatus() == Status::SPRZEDANY)
                ile++;
        }
    return ile;
}

int Rezerwacja::zwrocIleSprzedanychIZarezerwowanych() const{
    int ile = 0;
    for(int i=0; i < this->sala->zwrocRzad(); i++)
        for(int j=0; j < this->sala->zwrocKolumne(); j++)
        {
            if(this->bilety[i][j]->zwrocStatus() == Status::SPRZEDANY || this->bilety[i][j]->zwrocStatus() == Status::REZERWACJA)
                ile++;
        }
    return ile;
}

Bilet* Rezerwacja::zwrocBilet(int _rzad, int _kolumna) const{
    return this->bilety[_rzad][_kolumna];
}

const Sala* Rezerwacja::zwrocSale() const{
    return this->sala;
}

int Rezerwacja::zwrocIloscWizyt() const{
    return this->iloscWizyt;
}

void Rezerwacja::ustawNazwe(std::string _nazwa){
    this->nazwa = _nazwa;
}

void Rezerwacja::ustawDate(const Data& data){
    this->data = data;
}

void Rezerwacja::ustawStatusNaFotelu(const int& _rzad, const int& _kolumna, const Status& _status){
    this->bilety[_rzad][_kolumna]->ustawStatus(_status);
}

void Rezerwacja::ustawSale(const Sala* sala){
    this->sala = sala;
}

void Rezerwacja::ustawLiczbeGosci(const int& _liczba){
    this->iloscWizyt = _liczba;
}

void Rezerwacja::wypisz() const{
    std::cout<<this->nazwa<<this->data<<this->sala->zwrocNumer()<<this->zwrocIleSprzedanych()<<this->sala->zwrocPojemonsc();
}

std::ostream& operator<<(std::ostream& os, const Rezerwacja& rez){
    os << "Nazwa filmu: "
              << rez.nazwa << std::endl
              << "Data: " <<
    rez.data;
    std::cout << "Numer sali: "
              << rez.sala->zwrocNumer() << std::endl
              << "Sprzedane bilety: "
              << rez.zwrocIleSprzedanychIZarezerwowanych()
              << " na miejsc: "
              << rez.sala->zwrocPojemonsc() <<std::endl;
    return os;
}
