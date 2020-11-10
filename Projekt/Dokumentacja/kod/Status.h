/** @file */

#ifndef STATUS_H
#define STATUS_H

/**
 Typ wyliczeniowy służący do reprezentowania statusu biletu
 */
enum class Status{DOSTEPNY = 0, ///< bilet dostępny
    REZERWACJA, ///< zarezerwowany
    SPRZEDANY ///< sprzedany
    
};

#endif
