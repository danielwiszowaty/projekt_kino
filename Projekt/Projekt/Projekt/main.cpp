
#include <iostream>
#include <fstream>
#include "Bilet.hpp"
#include "Rezerwacja.hpp"
#include "Rezerwacje.hpp"
#include "Plik.hpp"

int main(int argc, const char * argv[]) {
    
    ListaRezerwacji* pListaRezerwacji = new ListaRezerwacji();
    ListaSal* pListaSal = new ListaSal();
    Plik p;
    std::string napis;
    
    std::cout<<"Witaj w programie do obslugi rezerwacji kin           "<<std::endl;
    std::cout<<"______________________________________________________"<<std::endl<<std::endl;
    
    p.instrukcja();
    
    while(std::getline(std::cin, napis)){
        std::vector<std::string> slowa = odczytajZKonsoli(napis);
        if(slowa.size() == 1 && slowa[0] == "instrukcja")
            p.instrukcja();
        else if(slowa.size() == 2 && slowa[0] == "zapisz"){
            p.zapiszDoPliku(slowa[1], pListaSal, pListaRezerwacji);
        }
        
        else if(slowa.size() == 2 && slowa[0] == "odczyt"){
            p.odczytajZPliku(slowa[1], pListaSal, pListaRezerwacji);
        }

        else if(slowa.size() == 1 && slowa[0] == "wyjdz"){
            delete pListaRezerwacji;
            delete pListaSal;
            return 0;
        }
        else if(slowa.size() == 6 && slowa[0] == "dodajFilm"){
            int dzien = std::stoi(slowa[1]);
            int miesiac = std::stoi(slowa[2]);
            int rok = std::stoi(slowa[3]);
            int numerSali = std::stoi(slowa[4]);
            Data data(dzien, miesiac, rok);
            Sala* sala = new Sala(numerSali);
            pListaSal->dodajNaKoniecListy(sala);
            pListaRezerwacji->dodajNaKoniecListy(sala, data, slowa[5]);
        }
        
        else if(slowa.size()== 2 && slowa[0] == "usunFilm"){
            pListaRezerwacji->usunRezerwacje(slowa[1]);
        }
        
        else if(slowa.size() >= 6 && slowa[0] == "zabookuj"){
            int rzad = std::stoi(slowa[1]);
            int kolumna = std::stoi(slowa[2]);
            int dzien = std::stoi(slowa[3]);
            int miesiac = std::stoi(slowa[4]);
            int rok = std::stoi(slowa[5]);
            pListaRezerwacji->zarezerwuj(rzad, kolumna, Data(dzien, miesiac, rok), slowa[6]);
        }
        
        else if(slowa.size() >= 6 && slowa[0] == "kup"){
            int rzad = std::stoi(slowa[1]);
            int kolumna = std::stoi(slowa[2]);
            int dzien = std::stoi(slowa[3]);
            int miesiac = std::stoi(slowa[4]);
            int rok = std::stoi(slowa[5]);
            pListaRezerwacji->kupBilet(rzad, kolumna, Data(dzien, miesiac, rok), slowa[6]);
        }
        
        else if(slowa.size() >= 6 && slowa[0] == "odbookuj"){
            int rzad = std::stoi(slowa[1]);
            int kolumna = std::stoi(slowa[2]);
            int dzien = std::stoi(slowa[3]);
            int miesiac = std::stoi(slowa[4]);
            int rok = std::stoi(slowa[5]);
            pListaRezerwacji->usunRezerwacje(rzad, kolumna, Data(dzien, miesiac, rok), slowa[6]);
        }
        else if(slowa[0] == "lista"){
            pListaSal->wypiszListe();
        }
        
        else if((slowa.size() >= 1 || slowa.size() >= 4) && slowa[0] == "rezerwacje"){
            if(slowa.size() == 1)
                pListaRezerwacji->wypisz();
            if(slowa.size() == 4){
                int dzien = std::stoi(slowa[1]);
                int miesiac = std::stoi(slowa[2]);
                int rok = std::stoi(slowa[3]);
                pListaRezerwacji->wypiszWszystkieRezerwacje(Data(dzien, miesiac, rok));
            }
            else if(slowa.size() >= 5){
                int dzien = std::stoi(slowa[1]);
                int miesiac = std::stoi(slowa[2]);
                int rok = std::stoi(slowa[3]);
                pListaRezerwacji->wypiszZarezerwowaneBilety(Data(dzien,miesiac, rok), slowa[4]);
            }
            
        }
    }
    delete pListaRezerwacji;
    delete pListaSal;
    
    return 0;
}
