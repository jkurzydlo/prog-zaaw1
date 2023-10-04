class Wezel{

int zawartosc;
public:
Wezel* poprzedni;
Wezel* nastepny;

Wezel(int zawartosc):zawartosc(zawartosc),nastepny(nullptr),poprzedni(nullptr){};

};