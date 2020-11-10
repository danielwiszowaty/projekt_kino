/** @file */

#ifndef SALA_HPP
#define SALA_HPP
#include <ostream>

/** Klasa reprezentująca salę tj. ilość rzędów, kolumn i jej numer
 */
class Sala{
private:
    int rzad; ///< ilośc rzędów
    int kolumna; ///< ilość kolumn
    int numer; ///< numer sali
    
public:
    Sala* pNext; ///< wskaźnik na następny element sali
    
    /** Konstruktor bezargumentowy- lista inicjalizacyjna
     */
    Sala();
    
    /** Konstruktor wieloargumentowy- lista inicjalizacyjna
     @param _numer numer sali reprezentowany w klasie
     @param _rzad rząd -||-
     @param _kolumna kolumna -||-
     */
    Sala(int _numer, int _rzad, int _kolumna);
    
    /** Konstruktor jednoargumentowy- lista inicjalizacyjna
     @param _numer numer sali reprezentowany w klasie
     */
    Sala(int _numer);
    
    /** Przeładowany konstruktor kopiujący
     @param obj sala do skopiowania
     */
    Sala(const Sala& obj);
    
    /** Przeładowany operator przypisania
     @param obj sala do przypisania
     @return zwraca przypisaną salę
     */
    Sala& operator =(const Sala& obj);
    
    /** Przeładowany operator przeniesienia
     @param obj sala do przeniesienia
     @return zwraca przeniesioną salę
     */
    Sala& operator =(const Sala&& obj);
    
    /** Zaprzyjaźniony operator strumieniowy służący do wypisania sali do strumienia
     @param os output stream
     @param sala sala do wypisania
     @retrun zwraca strumień
     */
    friend std::ostream& operator<<(std::ostream& os, const Sala& sala);

    /** Metoda typu getter, zwracająca numer sali
       @return numer sali
       */
    int zwrocNumer() const;
    
    /** Metoda typu getter, zwracająca ilość rzędów
       @return ilość rzędów
       */
    int zwrocRzad() const;
    
    /** Metoda typu getter, zwracająca ilość kolumn
        @return ilość kolumn
        */
    int zwrocKolumne() const;
    
    /** Metoda typu getter, zwracająca pojemność sali
        @return ilość rzędów * ilość kolumn
        */
    int zwrocPojemonsc() const;
    
    /** Metoda typu setter, ustawiająca numer sali
     @param _numer numer do ustawienia
     */
    void ustawNumer(int _numer);
    
    /** Metoda typu setter, ustawiająca ilość rzędów
     @param _rzad ilość rzędów do ustawienia
     */
    void ustawRzad(int _rzad);
    
    /** Metoda typu setter, ustawiająca ilość kolumn
     @param _kolumna ilość kolumn do ustawienia
     */
    void ustawKolumne(int _kolumna);
    
};

#endif
