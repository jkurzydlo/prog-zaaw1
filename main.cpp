#include <iostream>
#include "Lista.h"
int main(){
    Lista lista;
    lista.wstawNaPoczatek(5);
    lista.wstawNaPoczatek(6);
    lista.wstawNaPoczatek(7);
    lista.wstawNaKoniec(10);
    lista.usunZPozycji(2);
    lista.wyswietl();
    //lista.wyswietlOdwrocona();
    //commit usun z poczatku i konca i pozycji 
}