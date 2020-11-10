/** @file */

#ifndef BILET_HPP
#define BILET_HPP

#include "Sala.hpp"
#include "Data.hpp"
#include "Status.h"
#include <string>

/** Klasa reprezentująca bilet tj. unikalne ID, nazwa zakupionego filmu, sala, data, krzesełko i status biletu
 */
class Bilet{
private:
    std::string ID; ///< unikalne ID
    std::string nazwaFilmu; ///< nazwa filmu
    const Sala* sala; ///< sala
    Data data; ///< data
    int rzad; ///< rząd krzesła
    int kolumna; ///< kolumna krzesła
    Status status; ///< status biletu
    
    void przypisz(const Bilet& obj);
public:
    
    /** Konstruktor bezargumentowy- lista inicjalizacyjna
     */
    Bilet();
    
    /** Konstruktor wieloargumentowy- lista inicjalizacyjna
     @param _sala sala reprezentowana w klasie
     @param _nazwa nazwa filmu -||-
     @param _data data -||-
     @param _rzad rząd krzesełka -||-
     @param _kolumna kolumna krzesełka -||-
     @param _status status biletu -||-
     */
    Bilet(const Sala* _sala, const std::string& _nazwa, const Data& _data, int _rzad, int _kolumna, const Status& _status);
    
    /** Konstruktor jednoargumentowy- lista inicjalizacyjna
     @param sala sala reprezentowana w klasie
     */
    Bilet(const Sala* sala);
    
    /** Przeładowany operator przypisania
     @param obj sala do przypisania
     @return zwraca przypisaną salę
     */
    Bilet& operator =(const Bilet& obj);
    
    /** Zaprzyjaźniony operator strumieniowy służący do wypisania biletu do strumienia
     @param os output stream
     @param bilet bilet do wypisania
     @retrun zwraca strumień
     */
    friend std::ostream& operator<<(std::ostream& os, const Bilet& bilet);
    
    /** Metoda typu getter, zwracająca unikalne ID biletu
       @return numer ID
       */
    std::string zwrocID() const;
    
    /** Metoda typu getter, zwracająca nazwę filmu
       @return nazwa filmu
       */
    std::string zwrocNazweFilmu() const;
    
    /** Metoda typu getter, zwracająca salę
       @return sala
     */
    const Sala* zwrocSale() const;
    
    /** Metoda typu getter, zwracająca datę
       @return data
       */
    Data zwrocDate() const;
    
    /** Metoda typu getter, zwracająca rząd krzesła
       @return rząd
       */
    const int zwrocRzad() const;
    
    /** Metoda typu getter, zwracająca kolumnę krzesła
       @return kolumna
       */
    const int zwrocKolumne() const;
    
    /** Metoda typu getter, zwracająca status
       @return status
       */
    Status zwrocStatus() const;
    
    /** Metoda zwracająca enum jako string
       @return status jako napis
       */
    std::string zwrocStatusJakoNapis() const;
    
    /** Metoda typu setter, ustawiająca ID
     @param _ID ID do ustawienia
     */
    void ustawID(const std::string _ID);
    
    /** Metoda typu setter, ustawiająca nazwę filmu
     @param _nazwa nazwa do ustawienia
     */
    void ustawNazweFilmu(const std::string _nazwa);
    
    /** Metoda typu setter, ustawiająca salę
     @param _sala sala do ustawienia
     */
    void ustawSale(const Sala* _sala);
    
    /** Metoda typu setter, ustawiająca datę
     @param _data data do ustawienia
     */
    void ustawDate(const Data& _data);
    
    /** Metoda typu setter, ustawiająca rząd krzesła
     @param _rzad rząd do ustawienia
     */
    void ustawRzad(int _rzad);
    
    /** Metoda typu setter, ustawiająca kolumnę krzesła
     @param _kolumna kolumna do ustawienia
     */
    void ustawKolumne(int _kolumna);
    
    /** Metoda typu setter, ustawiająca status biletu
     @param _status status do ustawienia
     */
    void ustawStatus(const Status& _status);
    
    void wypisz() const;

};

#endif
