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
        default:
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
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
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
    }
    return false;
}
