/** @file */

#ifndef PLIK_HPP
#define PLIK_HPP
#include "Rezerwacje.hpp"
#include <vector>

/** Klasa pomocnicza służąca do obsługi plików i menu
 */
class Plik{
public:
    /** Metoda zapisująca wszystkie rezerwacje do pliku
     @param nazwaPliku nazwapliku
     @param pGlowaSal głowa listy sal
     @param pGlowaRezerwacji głowa listy rezerwacji
     */
    void zapiszDoPliku(std::string& nazwaPliku, ListaSal* pGlowaSal, ListaRezerwacji* pGlowaRezerwacji);
    
    /** Metoda odczytująca wszystkie rezerwacje z pliku
     @param nazwaPliku nazwapliku
     @param pGlowaSal głowa listy sal
     @param pGlowaRezerwacji głowa listy rezerwacji
     */
    void odczytajZPliku(std::string& nazwaPliku, ListaSal* pGlowaSal, ListaRezerwacji* pGlowaRezerwacji);
    
    /** Metoda wypisująca instrukcję obsługi
     */
    void instrukcja();
};

/** Funkcja pomocnicza służąca do zczytania napisu z konsoli do wektora
 @param napis napis do wczytania
 @return wektor napisów
 */
std::vector<std::string> odczytajZKonsoli(const std::string& napis);


#endif
