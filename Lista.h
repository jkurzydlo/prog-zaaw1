#include "Wezel.h"

class Lista{
    Wezel* poczatek;
    Wezel* koniec;

    public:
    Lista():poczatek(nullptr),koniec(nullptr){};

     ~Lista()
      {
          Wezel *tmp = nullptr;
          while (poczatek != nullptr)
          {
              tmp = poczatek;
              poczatek = poczatek->nastepny;
              delete tmp;
          }
          poczatek= nullptr;
      }
};