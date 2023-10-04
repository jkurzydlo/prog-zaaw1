#include <iostream>
#include "Lista.h"
int main(){
    Lista lista;
    lista.wstawNaPoczatek(5);
    lista.wstawNaPoczatek(6);
    lista.wstawNaPoczatek(7);
    lista.wstawNaKoniec(10);
    lista.wstawNa(2,4);
    lista.wyswietl();
}