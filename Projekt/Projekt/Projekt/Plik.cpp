#include "Plik.hpp"

void Plik::zapiszDoPliku(std::string& nazwaPliku, ListaSal* pGlowaSal, ListaRezerwacji* pGlowaRezerwacji){
    std::string wyjscie = nazwaPliku + ".txt";
    std::ofstream plik(wyjscie);
    
    plik<<pGlowaSal->zwrocIloscSal()<<std::endl;
    Sala* sTemp = pGlowaSal->pHead;
    while(sTemp){
        plik<<sTemp->zwrocNumer()<<std::endl;
        plik<<sTemp->zwrocRzad()<<std::endl;
        plik<<sTemp->zwrocKolumne()<<std::endl;
        sTemp = sTemp->pNext;
    }
    Rezerwacja* rTemp = pGlowaRezerwacji->pHead;
    plik<<pGlowaRezerwacji->zwrocIloscRezerwacji()<<std::endl;
    while(rTemp){
        plik<<rTemp->zwrocNazwe()<<std::endl;
        plik<<rTemp->zwrocDate().zwrocDzien()<<std::endl;
        plik<<rTemp->zwrocDate().zwrocMiesiac()<<std::endl;
        plik<<rTemp->zwrocDate().zwrocRok()<<std::endl;
        plik<<rTemp->zwrocSale()->zwrocNumer()<<std::endl;
        plik<<rTemp->zwrocSale()->zwrocRzad()<<std::endl;
        plik<<rTemp->zwrocSale()->zwrocKolumne()<<std::endl;
        Status status;
        for(int i = 0; i < rTemp->zwrocSale()->zwrocRzad(); i++){
            for(int j = 0; j < rTemp->zwrocSale()->zwrocKolumne(); j++){
                status = rTemp->zwrocBilet(i, j)->zwrocStatus();
                if(status == Status::DOSTEPNY)
                    plik<<0<<std::endl;
                if(status == Status::REZERWACJA)
                    plik<<1<<std::endl;
                if(status == Status::SPRZEDANY)
                    plik<<2<<std::endl;
            }
        }
        rTemp = rTemp -> pNext;
        
    }
    plik.close();
}

void Plik::odczytajZPliku(std::string& nazwaPliku, ListaSal* pGlowaSal, ListaRezerwacji* pGlowaRezerwacji){
    std::string wejscie = nazwaPliku + ".txt";
    std::ifstream plik(wejscie);
    
    int liczbaRezerwacji, dzien, miesiac, rok, numerBiletu, rzad, kolumna, statusBiletu, iloscSal, numerSali, rzedySali, kolumnySali;
    std::string nazwa;
    Rezerwacja* rezerwacja = nullptr;
    plik>>iloscSal;
    for(int i=0; i<iloscSal; i++){
        plik>>numerSali;
        plik>>rzedySali;
        plik>>kolumnySali;
        pGlowaSal->dodajNaKoniecListy(new Sala(numerSali, rzedySali, kolumnySali));
    }
    plik>>liczbaRezerwacji;
    for(int i = 0; i < liczbaRezerwacji ; i++){
        std::getline(plik, nazwa);
        plik>>dzien;
        plik>>miesiac;
        plik>>rok;
        plik>>numerBiletu;
        plik>>rzad;
        plik>>kolumna;
        Sala* temp = pGlowaSal->pHead;
        for(int j = 0; j < pGlowaSal->zwrocIloscSal(); j++){
            if(temp->zwrocNumer() == numerBiletu)
                rezerwacja = new Rezerwacja(nazwa, Data(dzien, miesiac, rok), pGlowaRezerwacji->pHead->zwrocSale());
            temp = temp->pNext;
        }
        
        for(int i = 0; i<rzad; i++){
            for(int j = 0; j<kolumna; j++){
                plik >> statusBiletu;
                Status status = static_cast<Status>(statusBiletu);
                rezerwacja->ustawStatusNaFotelu(i, j, status);
            }
        }
        pGlowaRezerwacji->dodajNaKoniec(rezerwacja);
        pGlowaRezerwacji->pHead = pGlowaRezerwacji->pHead->pNext;
    }
}

void Plik::instrukcja(){
    std::cout<<"Obslugiwane komendy:                                  "<<std::endl;
    std::cout<<"instrukcja                                            "<<std::endl;
    std::cout<<"zapisz <nazwapliku>                                   "<<std::endl;
    std::cout<<"odczytaj <nazwapliku>                                   "<<std::endl;
    std::cout<<"wyjdz                                                 "<<std::endl;
    std::cout<<"dodajFilm <data> <sala> <nazwaFilmu>                  "<<std::endl;
    std::cout<<"usunFilm <nazwaFilmu>                                 "<<std::endl;
    std::cout<<"zabookuj <rzad> <kolumna> <data> <nazwaFilmu>         "<<std::endl;
    std::cout<<"kup <rzad> <kolumna> <data> <nazwaFilmu>              "<<std::endl;
    std::cout<<"odbookuj <rzad> <kolumna> <data> <nazwaFilmu>         "<<std::endl;
    std::cout<<"wypiszSale                                                 "<<std::endl;
    std::cout<<"rezerwacje [<data>] [<nazwaFilmu>]                      "<<std::endl<<std::endl;
}

std::vector<std::string> odczytajZKonsoli(const std::string& napis){
    std::vector<std::string> odczytane;
    std::string temp;
    for(int i=0; i < napis.size(); i++){
        if(napis[i] == ' ')
        {
            if(temp != "")
                odczytane.push_back(temp);
            temp = "";
        }
        else if(napis[i] == '"'){
            for(int j = i ; i < napis.size(); j++){
                temp += napis[j];
                if(napis[j] == '"' && j != i){
                    i = j;
                    odczytane.push_back(temp);
                    temp = "";
                    break;
                }
            }
        }
        else
            temp += napis[i];
    }
    if(temp.size() > 0)
        odczytane.push_back(temp);
    return odczytane;
}
