class Wezel{

public:
int zawartosc;
Wezel* poprzedni;
Wezel* nastepny;

Wezel(int zawartosc):zawartosc(zawartosc),nastepny(nullptr),poprzedni(nullptr){};

};