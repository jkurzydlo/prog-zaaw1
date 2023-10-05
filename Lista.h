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

    void wstawNaKoniec(int val){
        Wezel *nowy_wezel = new Wezel(val);
        if (koniec->nastepny == nullptr)
        {
            koniec->nastepny = nowy_wezel;
            koniec = nowy_wezel;
        }
    }

    void wyswietl(){
        Wezel *tmp = poczatek;
        std::cout << "\nElementy listy:";

        while (poczatek != nullptr)
        {
            std::cout << tmp->zawartosc << " ";
            tmp = tmp->nastepny;
        }
    }

    void wyswietlOdwrocona(){
        Wezel *tmp = koniec;
        std::cout << "\nElementy listy:";


        while (tmp != nullptr)
        {
            std::cout << tmp->zawartosc << " ";
            tmp = tmp->poprzedni;
        }
        std::cout<<tmp->zawartosc;

        }

    void usunZPozycji(int indeks){
        Wezel* tmp = poczatek;

           for(int i = 1; i < indeks-1; i++) {
            if(tmp != nullptr) tmp = tmp->nastepny;

        if(tmp != nullptr && tmp->nastepny != nullptr){
            Wezel* do_usuniecia = tmp->nastepny;
            tmp->nastepny = tmp->nastepny->nastepny;
            if(tmp->nastepny->nastepny != nullptr)
                tmp->nastepny->nastepny->poprzedni = tmp->nastepny;
                delete do_usuniecia;
        }

      
    }

    }

    void usunZKonca(){
        Wezel* aktualny = poczatek;

        while (aktualny->nastepny->nastepny != nullptr)
        {
            aktualny = aktualny->nastepny;
        }

        Wezel* tmp = aktualny->nastepny;
        aktualny->nastepny = nullptr;
        delete tmp;
        
    }

    void usunZPoczatku(){
        Wezel* tmp = poczatek;
        poczatek = poczatek->nastepny;
        delete(tmp);

        if(poczatek!=nullptr) poczatek->poprzedni = nullptr;
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