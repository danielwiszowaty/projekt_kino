/** @file */

#ifndef REZERWACJA_HPP
#define REZERWACJA_HPP

#include <iostream>
#include "Bilet.hpp"
#include <vector>

/** Klasa reprezentująca rezerwację tj. nazwa filmu, data, sala, tablica dwuwymiarowa biletów
*/
class Rezerwacja{
private:
    std::string nazwa; ///< nazwa filmu
    Data data; ///< data
    std::vector<std::vector<Bilet*>> bilety; ///< bilety
    const Sala* sala; ///< sala
    int iloscWizyt;
    
    void przypisz(const Rezerwacja& obj);
    
    /** Metoda czyszcząca wektor
     */
    void usun();
    
public:
    Rezerwacja* pNext; ///< wskaźnik na następny element rezerwacji
    
    /** Konstruktor bezargumentowy- lista inicjalizacyjna
     */
    Rezerwacja();
    
    /** Konstruktor wieloargumentowy- lista inicjalizacyjna
     @param _nazwa nazwa filmu reprezentowana w klasie
     @param data data -||-
     @param sala sala -||-
     */
    Rezerwacja(const std::string& _nazwa, const Data& data, const Sala* sala);
    
    /** Przeładowany operator przypisania
     @param obj rezerwacja do przypisania
     @return zwraca przypisaną salę
     */
    Rezerwacja& operator =(const Rezerwacja& obj);
    
    /** Zaprzyjaźniony operator strumieniowy służący do wypisania rezerwacji do strumienia
     @param os output stream
     @param rez rezerwacja do wypisania
     @retrun zwraca strumień
     */
    friend std::ostream& operator<<(std::ostream& os, const Rezerwacja& rez);
    
    /** Destruktor czyszczący wektor
     */
    ~Rezerwacja();
    
    /** Metoda typu getter, zwracająca nazwę filmu
       @return nazwa filmu
     */
    std::string zwrocNazwe() const;
    
    /** Metoda typu getter, zwracająca datę
       @return data
     */
    Data zwrocDate() const;
    
    /** Metoda zwracająca ilość sprzedanych biletów dla danego seansu
       @return ilość sprzedanych biletów
     */
    int zwrocIleSprzedanych() const;
    
    /** Metoda zwracająca ilość sprzedanych i zarezerwowanych biletów dla danego seansu
       @return ilość sprzedanych i zarezerwowanych biletów
     */
    int zwrocIleSprzedanychIZarezerwowanych() const;
    
    /** Metoda typu getter, zwracająca bilet na danym krzesełku
     @param _rzad rząd
     @param _kolumna kolumna
       @return bilet
     */
    Bilet* zwrocBilet(int _rzad, int _kolumna) const;
    
    /** Metoda typu getter, zwracająca salę
       @return sala
     */
    const Sala* zwrocSale() const;
    int zwrocIloscWizyt() const;
    
    /** Metoda typu setter, ustawiająca nazwę filmu
     @param _nazwa nazwa do ustawienia
     */
    void ustawNazwe(std::string _nazwa);
    
    /** Metoda typu setter, ustawiająca datę
     @param _data data do ustawienia
     */
    void ustawDate(const Data& _data);
    
    /** Metoda typu setter, ustawiająca status na fotelu
     @param _rzad rząd krzesełka
     @param _kolumna kolumna krzesełka
     @param _status status do ustawienia
     */
    void ustawStatusNaFotelu(const int& _rzad, const int& _kolumna, const Status& _status);
    
    /** Metoda typu setter, ustawiająca salę
     @param sala sala do ustawienia
     */
    void ustawSale(const Sala* sala);
    void ustawLiczbeGosci(const int& _liczba);
    
    void wypisz() const;

    
};

#endif
