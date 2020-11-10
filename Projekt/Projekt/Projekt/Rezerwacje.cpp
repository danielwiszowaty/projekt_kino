#include "Rezerwacje.hpp"
#include "Sala.hpp"

ListaRezerwacji::ListaRezerwacji(const ListaRezerwacji& obj){
    Rezerwacja* temp = nullptr;
    Rezerwacja* temp1 = nullptr;
    if(not obj.pHead)
        this->pHead = nullptr;
    else{
        this->pHead = new Rezerwacja();
        this->pHead->zwrocDate() = obj.pHead->zwrocDate();
        this->pHead->zwrocNazwe() = obj.pHead->zwrocNazwe();
        temp = this->pHead;
        temp1 = obj.pHead->pNext;
    }
    while(temp1){
        temp->pNext = new Rezerwacja();
        temp = temp->pNext;
        this->pHead->zwrocDate() = obj.pHead->zwrocDate();
        this->pHead->zwrocNazwe() = obj.pHead->zwrocNazwe();
        temp1 = temp1->pNext;
        
    }
    temp->pNext = nullptr;
}



ListaRezerwacji::~ListaRezerwacji(){
while(this->pHead){
      Rezerwacja* temp = this->pHead->pNext;
      delete pHead;
      pHead = temp;
  }
}

void ListaRezerwacji::dodajNaKoniec(Rezerwacja* rezerwacja){
    Rezerwacja* temp = rezerwacja;
    temp->pNext = this->pHead;
    this->pHead = temp;
}
 
 void ListaRezerwacji::dodajNaKoniecListy(Sala* sala, const Data& data, const std::string& nazwa){
     bool wolnaRezerwacja = true;
     Rezerwacja* iteruj = this->pHead;
     while(iteruj){
         if(iteruj->zwrocDate() == data && iteruj->zwrocSale()->zwrocNumer() == sala->zwrocNumer() && iteruj->zwrocNazwe() == nazwa){
             wolnaRezerwacja = false;
             std::cout<<"Film "<<nazwa<<" na ten dzien jest juz w sali numer "<<sala->zwrocNumer()<<std::endl;
             break;            }
         iteruj = iteruj->pNext;
     }
     if(wolnaRezerwacja){
         Rezerwacja* temp = new Rezerwacja(nazwa, data, sala);
         for(int i=0; i<temp->zwrocSale()->zwrocRzad(); i++){
             for(int j=0; j<temp->zwrocSale()->zwrocKolumne(); j++)
                 temp->ustawStatusNaFotelu(i, j, Status::DOSTEPNY);
         }
         temp->pNext = this->pHead;
         this->pHead = temp;
     }
 }
 
 void ListaRezerwacji::wypisz(){
     Rezerwacja* temp = this->pHead;
     while(temp){
         std::cout<<*temp<<std::endl;
         temp = temp->pNext;
     }
 }
 
int ListaRezerwacji::ileWolnychKrzesel(const Data& data, const std::string& nazwa){
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(temp->zwrocNazwe() == nazwa && temp->zwrocDate() == data)
             return (temp->zwrocSale()->zwrocPojemonsc() - temp->zwrocIleSprzedanychIZarezerwowanych());
         temp = temp->pNext;
     }
    std::cout<<"W tym dniu nie ma filmu"<<std::endl;
    return 0;
 }
 
 void ListaRezerwacji::wypiszZarezerwowaneBilety(const Data& data, const std::string& nazwa){
     Rezerwacja* temp = this->pHead;
     while(temp){
         for(int i = 0; i < temp->zwrocSale()->zwrocRzad(); i++){
         for(int j = 0; j < temp->zwrocSale()->zwrocKolumne(); j++){
             if(temp->zwrocDate() == data && temp->zwrocNazwe() == nazwa){
                 if(temp->zwrocBilet(i, j)->zwrocStatus() == Status::REZERWACJA
                    || temp->zwrocBilet(i, j)->zwrocStatus() == Status::SPRZEDANY)
                        std::cout<<*temp->zwrocBilet(i, j);
                }
             
             }
         }
         temp = temp->pNext;
     }
 }
 
 void ListaRezerwacji::wypiszWszystkieRezerwacje(const Data& data){
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(temp->zwrocDate() == data)
             std::cout<<*temp;
         temp = temp->pNext;
     }
 }
 
 
 int ListaRezerwacji::zwrocIloscRezerwacji(){
     int ile = 0;
     Rezerwacja* temp = this->pHead;
     while(temp){
         ile++;
         temp = temp->pNext;
     }
     return ile;
 }
 
 Rezerwacja* ListaRezerwacji::zwrocRezerwacjeNumer (const int& index){
     int iteruj = 0;
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(iteruj == index)
             return temp;
         iteruj++;
         temp = temp->pNext;
     }
     return nullptr;
 }
 
 void ListaRezerwacji::usunRezerwacje(const std::string& nazwa){
     Rezerwacja* temp = this->pHead;
     Rezerwacja* temp2 = nullptr;
     
     if(temp && temp->zwrocNazwe() == nazwa){
         pHead = temp->pNext;
         delete temp;
         return;
     }
     
     while(temp && temp->zwrocNazwe() != nazwa){
         temp2 = temp;
         temp = temp->pNext;
     }
     if(not temp)
         return;
     
     temp2->pNext = temp->pNext;
     delete temp;
 }
 
 void ListaRezerwacji::zarezerwuj(const int rzad, const int kolumna, const Data& data, const std::string nazwa){
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(temp->zwrocNazwe() == nazwa && temp->zwrocDate() == data){
             if(temp->zwrocBilet(rzad, kolumna)->zwrocStatus() == Status::REZERWACJA || temp->zwrocBilet(rzad, kolumna)->zwrocStatus() == Status::SPRZEDANY)
                 std::cout<<"Ten bilet jest już zarezerwowany!"<<std::endl;
             else
                 temp->ustawStatusNaFotelu(rzad, kolumna, Status::REZERWACJA);
         }
         temp = temp->pNext;
     }
 }
 
 void ListaRezerwacji::usunRezerwacje(const int rzad, const int kolumna, const Data& data, const std::string nazwa){
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(temp->zwrocNazwe() == nazwa && temp->zwrocDate() == data && temp->zwrocBilet(rzad, kolumna)->zwrocStatus() == Status::REZERWACJA)
             temp->ustawStatusNaFotelu(rzad, kolumna, Status::DOSTEPNY);
     else
         std::cout<<"BLAD: Bilet nie jest zarezerwowany!"<<std::endl;
         temp = temp->pNext;
     }
 }
 
 void ListaRezerwacji::kupBilet(const int rzad, const int kolumna, const Data& data, const std::string nazwa){
     Rezerwacja* temp = this->pHead;
     while(temp){
         if(temp->zwrocNazwe() == nazwa && temp->zwrocDate() == data){
             if(temp->zwrocBilet(rzad, kolumna)->zwrocStatus() == Status::SPRZEDANY)
                 std::cout<<"Ten bilet jest już sprzedany!"<<std::endl;
             else
                 temp->ustawStatusNaFotelu(rzad, kolumna, Status::SPRZEDANY);
         }
         temp = temp->pNext;
     }
 }
 
 void ListaRezerwacji::usunListe(){
     while(this->pHead){
         Rezerwacja* temp = this->pHead->pNext;
         delete pHead;
         pHead = temp;
     }
 }

ListaSal::~ListaSal(){
while(this->pHead){
    Sala* temp = this->pHead->pNext;
    delete pHead;
    pHead = temp;
    }
}

void ListaSal::dodajNaKoniecListy(Sala* sala){
    Sala* temp = sala;
    temp->pNext = this->pHead;
    this->pHead = temp;
}

void ListaSal::dodajNaKoniecListyGut(Sala* sala){
    bool wolnaRezerwacja = true;
    Sala* iteruj = this->pHead;
    while(iteruj){
        if(iteruj->zwrocNumer() == sala->zwrocNumer()){
            wolnaRezerwacja = false;
            break;            }
        iteruj = iteruj->pNext;
    }
    if(wolnaRezerwacja){
        Sala* temp = new Sala(sala->zwrocNumer());
        temp->pNext = this->pHead;
        this->pHead = temp;
    }
}


void ListaSal::wypiszListe(){
    Sala* temp = this->pHead;
    while(temp){
        std::cout<<*temp<<std::endl;
        temp = temp->pNext;
    }
}

Sala* ListaSal::zwrocTakaSamaSale(Sala* sala){
    Sala* temp = this->pHead;
    while(temp){
        if(temp->zwrocNumer() == sala->zwrocNumer())
            return temp;
        temp = temp->pNext;
    }
    return nullptr;
}

Sala* ListaSal::zwrocSaleNumer (const int& index){
    int iteruj = 0;
    Sala* temp = this->pHead;
    while(temp){
        if(iteruj == index)
            return temp;
        iteruj++;
        temp = temp->pNext;
    }
    return nullptr;
}

int ListaSal::zwrocIloscSal(){
    int ile = 0;
    Sala* temp = this->pHead;
    while(temp){
        ile++;
        temp = temp->pNext;
    }
    return ile;
}

void ListaSal::usunListe(){
    while(this->pHead){
        Sala* temp = this->pHead->pNext;
        delete pHead;
        pHead = temp;
    }
}

