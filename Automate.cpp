#include "Automate.h"
#include "Etat.h"

Symbole* Automate::popSymbole() {
    Symbole * s = symboles.back();
    symboles.pop_back();
    return s;
}

void Automate::decalage(Symbole * s, Etat * e) {
    if(*s == INT) {
        chaineLue += to_string(((Entier *) s)->getValue());
    } else {
        chaineLue += Etiquettes2[*s];
    }
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

    if(symboles.size() > 1 && *s == FIN && parentesesFermantesManquantes && ignoreErrors) {
        cout << "Valeur de l'expression: " << ((Expr *) symboles.back())->getValue() << endl;
        cout << "Expression evaluée: " << chaineLue;
        for(int k = 0; k < static_cast<int>(symboles.size()-1); k++) {
            cout << ")";
        }
        cout << endl;
    }
    
    if(symboles.size() == 1 && *s == FIN) {
        cout << "Valeur de l'expression: " << ((Expr *) symboles.back())->getValue() << endl;
        cout << "Expression evaluée: " << chaineLue << endl;
    }

    if(positionErrors.size() > 0) {
        cout << positionErrors.size() << " Erreur(s) de syntaxe trouvée(s) : " << endl;
        for(auto it = positionErrors.begin(); it != positionErrors.end(); it++) {
            cout << "    Erreur à la position " << it->first << ", " << (it->second)[0] << " trouvé alors que ";
            for(int j = 1; j < static_cast<int>(it->second.size()); j++) {
                cout << (it->second)[j];
                if(j == static_cast<int>(it->second.size()-2)) {
                    cout << " OU ";
                } else if(j == static_cast<int>(it->second.size()-1)) {
                    cout << " attendus." << endl;
                } else {
                    cout << ", ";
                }
            }
        }
    }


    delete(s);
}