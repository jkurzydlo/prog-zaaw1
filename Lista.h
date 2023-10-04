#include "Wezel.h"
#include <iostream>
class Lista
{
    Wezel *poczatek;
    Wezel *koniec;

public:
    Lista() : poczatek(nullptr), koniec(nullptr){};

    ~Lista()
    {
        Wezel *tmp = nullptr;
        while (poczatek != nullptr)
        {
            tmp = poczatek;
            poczatek = poczatek->nastepny;
            delete tmp;
        }
        poczatek = nullptr;
    }

    void wstawNaPoczatek(int val)
    {
        Wezel *nowy_wezel = new Wezel(val);
        Wezel *tmp = poczatek;

        if (poczatek == nullptr)
        {
            poczatek = nowy_wezel;
            koniec = nowy_wezel;
        }
        else
        {
            poczatek->poprzedni = poczatek;
            nowy_wezel->nastepny = poczatek;
            poczatek = nowy_wezel;
        }
    }

    void wstawNaKoniec(int val)
    {
        Wezel *nowy_wezel = new Wezel(val);
        if (koniec->nastepny == nullptr)
        {
            koniec->nastepny = nowy_wezel;
            koniec = nowy_wezel;
        }
    }

    void wyswietl()
    {
        Wezel *tmp = poczatek;
        std::cout << "\nElementy listy:";

        while (poczatek != nullptr)
        {
            std::cout << tmp->zawartosc << " ";
            tmp = tmp->nastepny;
        }
    }
};