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

    void wstawNa(int indeks, int val){
        Wezel* nowy = new Wezel(val);

        if(indeks == 0){
          wstawNaPoczatek(val);
        }else{
            Wezel* tmp = poczatek;
            
            for(int i =1;i<indeks -1;i++){
                tmp = tmp->nastepny;
            }

            if(tmp!=nullptr){
                nowy->nastepny = tmp->nastepny;
                nowy->poprzedni = tmp;
                tmp->nastepny = nowy;

                if(nowy->nastepny != nullptr) nowy->nastepny->poprzedni = nowy;
            }
        }
    }
};