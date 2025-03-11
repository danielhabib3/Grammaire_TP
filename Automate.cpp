#include "Automate.h"
#include "Etat.h"

Symbole* Automate::popSymbole() {
    Symbole * s = symboles.back();
    symboles.pop_back();
    return s;
}

void Automate::decalage(Symbole * s, Etat * e) {
    symboles.push_back(s);
    etats.push_back(e);
    lexer->Avancer();
}

void Automate::transitionSimple(Symbole * s, Etat * e) {
    symboles.push_back(s);
    etats.push_back(e);
}

void Automate::reduction(int n, Symbole * s) {
    for(int i=0; i<n; i++) {
        delete(etats.back());
        etats.pop_back();
    }
    etats.back()->transition(*this, s);
}

Automate::~Automate() {
    while (!symboles.empty()) {
        delete symboles.back();
        symboles.pop_back();
    }

    while (!etats.empty()) {
        delete etats.back();
        etats.pop_back();
    }
}

void Automate::lecture() {
    Symbole * s = lexer->Consulter();
    etats.push_back(new E0());
    bool accept = false;
    
    while(!etats.empty() && !accept && !erreur) {
        if(this->trace) {
            // print la pile des etats
            cout << "Pile des etats: ";
            for(auto it = etats.begin(); it != etats.end(); it++) {
                cout << (*it)->getName() << " ";
            }
            cout << endl;
            // print la pile des symboles
            cout << "Pile des symboles: ";
            for(auto it = symboles.begin(); it != symboles.end(); it++) {
                (*it)->Affiche();
                cout << " ";
            }
            cout << endl;

            cout << "Etat courant: " << etats.back()->getName() << " | Symbole courant : " << Etiquettes[*s] << endl;
        }

        accept = etats.back()->transition(*this, s);
        
        s = lexer->Consulter();
        
        if (this->trace) {
            cout << "Symbole suivant: " << Etiquettes[*s] << endl;
            cout << endl;
        }
        
        
        
    }

    if(accept) {
        cout << "Accepté" << endl;
    } else {
        cout << "Refusé" << endl;
    }

    if(this->trace) {
        cout << "Pile des symboles: ";
        for(auto it = symboles.begin(); it != symboles.end(); it++) {
            (*it)->Affiche();
            cout << " ";
        }
        cout << endl;
    }

    cout << "Taille de la pile des symboles: " << symboles.size() << endl;
    cout << "Etiquettes: " << Etiquettes[*s] << endl;
    if(symboles.size() == 1 && *s == EXPR) {
        cout << "Valeur de l'expression: " << ((Expr *) symboles.back())->getValue() << endl;
    }


    delete(s);
}