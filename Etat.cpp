#include "Etat.h"
#include "Automate.h"

bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionSimple(s, new E1);
            break;
        case FIN:
            automate.setErreur(true);
            automate.addErreur(automate.getLexer()->getTete()+1, vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())    
                cout << "ERREUR DE SYNTAXE [E0] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 
            break;
        default:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E0] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            // Accepter
            return true;
        default:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "FIN"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E1] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT OU FIN ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionSimple(s, new E6);
            break;
        case FIN:
            automate.setErreur(true);
            automate.addErreur(automate.getLexer()->getTete()+1, vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())    
                cout << "ERREUR DE SYNTAXE [E2] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 
            break;
        default:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E2] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    Entier * e = (Entier *) automate.popSymbole();
    Expr * res;
    switch(*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            res = new Expr(e->getValue());
            automate.reduction(1, res);
            delete e;
            break;
        default:
            if(automate.getIgnoreErrors()) {
                res = new Expr(e->getValue());
                automate.reduction(1, res);
                delete e;
            } else {
                automate.setErreur(true);
            }
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR", "FIN"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E3] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT, CLOSEPAR OU FIN ATTENDUS." << endl; 
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionSimple(s, new E7);
            break;
        case FIN:
            automate.setErreur(true);
            automate.addErreur(automate.getLexer()->getTete()+1, vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())    
                cout << "ERREUR DE SYNTAXE [E4] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 
            break;
        default:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E4] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionSimple(s, new E8);
            break;
        case FIN:
            automate.setErreur(true);
            automate.addErreur(automate.getLexer()->getTete()+1, vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())    
                cout << "ERREUR DE SYNTAXE [E5] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 
            break;
        default:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "INT", "OPENPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E5] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE INT OU OPENPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    Expr *e;
    Symbole * p2;
    switch(*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        case OPENPAR:
        case INT:
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E6] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT OU CLOSEPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
        case FIN:
            automate.addErreur(automate.getLexer()->getTete()+1, vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR"}));
            if(automate.getIgnoreErrors()) {
                automate.addParenteseManquante();
                e = (Expr *) automate.popSymbole();
                p2 = automate.popSymbole();
                automate.reduction(2, e);
                delete p2;
            } else {
                automate.setErreur(true);
            }
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E6] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT OU CLOSEPAR ATTENDUS." << endl; 

            break;
        default: // cas de ERREUR
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E6] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT OU CLOSEPAR ATTENDUS." << endl; 

            if(automate.getIgnoreErrors()) {
                automate.getLexer()->Avancer();
                delete s;
            } else {
                automate.setErreur(true);
            }
            break;
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    Expr *e1, *e2, *res;
    Symbole * p;
    switch(*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr *) automate.popSymbole();
            p = automate.popSymbole();
            e2 = (Expr *) automate.popSymbole();

            res = new Expr(e1->getValue() + e2->getValue());
            automate.reduction(3, (Symbole *) res);

            delete e1; delete e2; delete p;
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        default:
            if(automate.getIgnoreErrors()) {
                e1 = (Expr *) automate.popSymbole();
                p = automate.popSymbole();
                e2 = (Expr *) automate.popSymbole();

                res = new Expr(e1->getValue() + e2->getValue());
                automate.reduction(3, (Symbole *) res);

                delete e1; delete e2; delete p;
            } else {
                automate.setErreur(true); 
            }
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR", "FIN"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E7] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT, CLOSEPAR OU FIN ATTENDUS." << endl; 
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    Expr *e1, *e2, *res;
    Symbole * p;
    switch(*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = (Expr *) automate.popSymbole();
            p = automate.popSymbole();
            e2 = (Expr *) automate.popSymbole();

            res = new Expr(e1->getValue() * e2->getValue());
            automate.reduction(3, (Symbole *) res);

            delete e1; delete e2; delete p;
            break;
        default:
            if(automate.getIgnoreErrors()) {
                e1 = (Expr *) automate.popSymbole();
                p = automate.popSymbole();
                e2 = (Expr *) automate.popSymbole();

                res = new Expr(e1->getValue() * e2->getValue());
                automate.reduction(3, (Symbole *) res);

                delete e1; delete e2; delete p;
            } else {
                automate.setErreur(true); 
            }
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR", "FIN"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E8] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT, CLOSEPAR OU FIN ATTENDUS." << endl; 
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    Expr *e;
    Symbole * p1, * p2;
    switch(*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            p1 = automate.popSymbole();
            e = (Expr *) automate.popSymbole();
            p2 = automate.popSymbole();
            automate.reduction(3, e);
            delete p1; delete p2;
            break;
        default:
            if(automate.getIgnoreErrors()) {
                p1 = automate.popSymbole();
                e = (Expr *) automate.popSymbole();
                p2 = automate.popSymbole();
                automate.reduction(3, e);
                delete p1; delete p2;
            } else {
                automate.setErreur(true); 
            }
            automate.addErreur(automate.getLexer()->getTete(), vector<string>({Etiquettes[*s], "PLUS", "MULT", "CLOSEPAR", "FIN"}));
            if(automate.getTrace())
                cout << "ERREUR DE SYNTAXE [E9] : " << Etiquettes[*s] << " TROUVÉ ALORS QUE PLUS, MULT, CLOSEPAR OU FIN ATTENDUS." << endl;
            break;
    }
    return false;
}
