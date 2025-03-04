#pragma once

#include "lexer.h"
#include "Symbole.h"


#include <string>
#include <deque>
#include <iostream>
using namespace std;

class Etat;

class Automate {
    public:
        Automate(Lexer* l) : lexer(l), erreur(false) {};
        virtual ~Automate();
        void decalage(Symbole * s, Etat * e);
        void lecture();
        void transitionSimple(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        Symbole* popSymbole();
        Lexer* getLexer() {return lexer;};
        bool getErreur() {return erreur;};
        void setErreur(bool e) { erreur=e; };
    
    private:
        Lexer * lexer;
        deque<Symbole *> symboles;
        deque<Etat *> etats;
        bool erreur;
};