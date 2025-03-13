#pragma once

#include "lexer.h"
#include "Symbole.h"


#include <string>
#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Etat;


class Automate {
    public:
        Automate(Lexer* l, bool t, bool i) : lexer(l), erreur(false), trace(t), ignoreErrors(i), parentesesFermantesManquantes(0) {
            positionErrors = map<int,vector<string>>();
            chaineLue = string(""); 
        };
        virtual ~Automate();
        void decalage(Symbole * s, Etat * e);
        void lecture();
        void transitionSimple(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        Symbole* popSymbole();
        Lexer* getLexer() {return lexer;};
        bool getErreur() {return erreur;};
        void setErreur(bool e) { erreur=e; };
        bool getIgnoreErrors() {return ignoreErrors;};
        map<int,vector<string>> getPositionErrors() {return positionErrors;};
        string getChaineLue() {return chaineLue;};
        void setChaineLue(string c) {chaineLue = c;};
        void addErreur(int pos, vector<string> symboles) {positionErrors[pos] = symboles;};
        bool getTrace() {return trace;};
        void addParenteseManquante() {parentesesFermantesManquantes++;};
    
    private:
        Lexer * lexer;
        deque<Symbole *> symboles;
        deque<Etat *> etats;
        bool erreur;
        bool trace;
        bool ignoreErrors;
        string chaineLue;
        // La clé c'est la position de l'erreur et la valeur c'est une liste de symboles
        // le premier de la liste c'est le symbole trouvé et les autres ce sont les symbole attendus
        map<int,vector<string>> positionErrors;
        int parentesesFermantesManquantes;
};