/** @file */

#ifndef REZERWACJE_HPP
#define REZERWACJE_HPP

#include "Rezerwacja.hpp"
#include "Sala.hpp"
#include <fstream>

/** Lista jednokierunkowa reprezentująca rezerwacje
 */
class ListaRezerwacji{
public:
    Rezerwacja* pHead; ///< wskaźnik na głowę listy
    
    /** Konstruktor bezargumentowy- lista inicjalizacyjna.
     Inicjalizuje głowę do nullptr.
     */
    ListaRezerwacji() : pHead(nullptr) {}
    
    /** Przeładowany konstruktor kopiujący
     @param obj lista rezerwacji do skopiowania
     */
    ListaRezerwacji(const ListaRezerwacji& obj);
    
    /** Destruktor zwalniający pamięć listy
     */
    ~ListaRezerwacji();
    
    /** Metoda dodająca rezerwacje na początek listy jednokierunkowej
     @param rezerwacja rezerwacja do dodania
     */
    void dodajNaKoniec(Rezerwacja* rezerwacja);
    
    /** Metoda dodająca rezerwacje na początek listy jednokierunkowej z uwzględnieniem braku powtórzeń
     @param sala sala do dodania
     @param data data do dodania
     @param nazwa nazwa filmu
     */
    void dodajNaKoniecListy(Sala* sala, const Data& data, const std::string& nazwa);
    
    /** Metoda wypisująca listę jednokierunkową
     */
    void wypisz();
    
    /** Metoda zwracająca ilość wolnych krzeseł dla danej rezerwacji
     @param data data rezerwacji
     @param nazwa nazwa filmu
     @return ile wolnych krzeseł
     */
    int ileWolnychKrzesel(const Data& data, const std::string& nazwa);
    
    /** Metoda wypisująca zarezerwowane bilety dla rezerwacji danego dnia i o podanej nazwie
     @param data data
     @param nazwa nazwa filmu
     */
    void wypiszZarezerwowaneBilety(const Data& data, const std::string& nazwa);
    
    /** Metoda wypisująca zarezerwowane bilety dla rezerwacji danego dnia
      @param data data
      */
    void wypiszWszystkieRezerwacje(const Data& data);
    
    /** Metoda zwracająca ilość wszystkich elementów listy jednokierunkowej
     @return ile elementów listy
     */
    int zwrocIloscRezerwacji();
    
    /** Metoda zwracająca element listy o podanym indeksie
     @param index indeks do iteracji
     @return rezerwacja o indeksie
     */
    Rezerwacja* zwrocRezerwacjeNumer (const int& index);
    
    /** Metoda usuwająca element listy o podanej nazwie
     @param nazwa nazwa do usunięcia
     */
    void usunRezerwacje(const std::string& nazwa);
    
    /** Metoda rezerwująca bilet dla konkretnego filmu
     @param rzad rząd krzesła
     @param kolumna kolumna krzesła
     @param data data filmu
     @param nazwa nazwa filmu
     */
    void zarezerwuj(const int rzad, const int kolumna, const Data& data, const std::string nazwa);
    
    /** Metoda usuwająca rezerwację dla konkretnego filmu
     @param rzad rząd krzesła
     @param kolumna kolumna krzesła
     @param data data filmu
     @param nazwa nazwa filmu
     */
    void usunRezerwacje(const int rzad, const int kolumna, const Data& data, const std::string nazwa);
    
    /** Metoda kupująca bilet dla konkretnego filmu
     @param rzad rząd krzesła
     @param kolumna kolumna krzesła
     @param data data filmu
     @param nazwa nazwa filmu
     */
    void kupBilet(const int rzad, const int kolumna, const Data& data, const std::string nazwa);
    
    /** Metoda usuwająca całą listę jednokierunkową
     */
    void usunListe();
};

/** Lista jednokierunkowa reprezentująca sale
*/
class ListaSal{
public:
    Sala* pHead; ///< wskaźnik na głowę listy
    
    /** Konstruktor bezargumentowy- lista inicjalizacyjna.
     Inicjalizuje głowę do nullptr.
     */
    ListaSal() : pHead(nullptr) {}
    
    /** Destruktor zwalniający pamięć listy
     */
    ~ListaSal();
    
    /** Metoda dodająca rezerwacje na początek listy jednokierunkowej
     @param sala sala do dodania
     */
    void dodajNaKoniecListy(Sala* sala);
    
    /** Metoda dodająca salę na początek listy jednokierunkowej z uwzględnieniem braku powtórzeń
     @param sala sala do dodania
     */
    void dodajNaKoniecListyGut(Sala* sala);
    
    /** Metoda wyszukjąca w liście taki sam element
     @param sala sala do znalezienia
     @return wskaźnik na salę lub nullptr
     */
    Sala* zwrocTakaSamaSale(Sala* sala);
    
    /** Metoda wypisująca listę jednokierunkowa
     */
    void wypiszListe();
    
    /** Metoda zwracająca element listy o podanym indeksie
     @param index indeks do iteracji
     @return wskaźnik na salę o indeksie
     */
    Sala* zwrocSaleNumer (const int& index);
    
    /** Metoda zwracająca ilość wszystkich elementów listy jednokierunkowej
     @return ile elementów listy
     */
    int zwrocIloscSal();
    
    /** Metoda usuwająca całą listę jednokierunkową
     */
    void usunListe();

};


#endif
