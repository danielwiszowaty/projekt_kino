/** @file */

#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>

/** Klasa reprezentująca date tj. dzień, miesiąc i rok
 */
class Data{
private:
    int dzien; ///< dzień
    int miesiac; ///< miesiąc
    int rok; ///< rok
    
public:
    /** Konstruktor bezargumentowy- lista inicjalizacyjna
     */
    Data();
    
    /** Konstruktor wieloargumentowy- lista inicjalizacyjna
     @param _dzien dzień reprezentowany w klasie
     @param _miesiac miesiąc -||-
     @param _rok rok -||-
     */
    Data(int _dzien, int _miesiac, int _rok);
    
    /** Przeładowany operator przypisania
     @param obj data do przypisania
     @return zwraca przypisaną datę
     */
    Data& operator =(const Data& obj);
    
    /** Przeładowany operator porównania, porównujący dwie daty
     @param obj data do porównania
     @return metoda zwraca true jeżeli daty są takie same
     */
    bool operator ==(const Data& obj);
    
    /** Przeładowany operator >=, porównujący dwie daty
     @param obj referencja do obiektu który jest typu Data
     @return metoda zwraca true jeżeli this->data jest większa
     */
    bool operator >=(const Data& obj);
    
    /** Przeładowany operator inkrementacji, inkrementuje datę
     uwzględniając warunek 12 miesięcy w roku kalendarzowym
     @return metoda zwraca obiekt
     */
    Data& operator ++();
    
    /** Zaprzyjaźniony operator większy lub równy, porównuje dwie daty
     @param pierwsza pierwsza data do porównania
     @param druga druga data do porównania
     @return true jeżeli pierwsza data jest większa
     */
    friend bool operator >=(const Data& pierwsza, const Data& druga);
    
    /** Zaprzyjaźniony operator strumieniowy służący do wypisania daty do strumienia
     @param os output stream
     @param data data do wypisania
     @retrun zwraca strumień
     */
    friend std::ostream& operator<<(std::ostream& os, const Data& data);
    
    /** Zaprzyjaźniony operator strumieniowy służący do wpisania daty do strumienia
     @param is input stream
     @param data data do wpisania
     @retrun zwraca strumień
     */
    friend std::istream& operator>>(std::istream& is, Data& data);
    
    /** Destruktor
     */
    ~Data();
    
    /** Metoda typu getter, zwracająca dzień
     @return dzień
     */
    int zwrocDzien() const;
    
    /** Metoda typu getter, zwracająca miesiąc
     @return miesiąc
     */
    int zwrocMiesiac() const;
    
    /** Metoda typu getter, zwracająca rok
     @return rok
     */
    int zwrocRok() const;
    
    /** Metoda typu setter, ustawiająca dzień
     @param _dzien dzień do ustawienia
     */
    void ustawDzien(const int _dzien);
    
    /** Metoda typu setter, ustawiająca miesiąc
     @param _miesiac miesiąć do ustawienia
     */
    void ustawMiesiac(const int _miesiac);
    
    /** Metoda typu setter, ustawiająca rok
     @param _rok rok do ustawienia
     */
    void ustawRok(const int _rok);
    
    /** Metoda sprawdzjąca czy jest koniec miesiąca
     @return true jeżeli dzień w miesiącu jest poprawny
     */
    bool czyKoniecMiesiaca() const;
    
    /** Metoda sprawdzająca czy dwa przedziały dat kolidują ze sobą
     @param pocz1 początek pierwszego przedziału
     @param koniec1 koniec pierwszego przedziału
     @param pocz2 początek drugiego przedziału
     @param koniec2 koniec drugiego przedziału
     @return true jeżeli daty kolidują
     */
    bool czyDatyKoliduja(const Data pocz1, const Data koniec1, const Data pocz2, const Data koniec2);
};

#endif
