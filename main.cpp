#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("1+a");

   Lexer l(chaine);

   // Symbole * s;
   // while(*(s=l.Consulter())!=FIN) {
   //    s->Affiche();
   //    cout<<endl;
   //    l.Avancer();
   // }

   Automate a(&l);
   a.lecture();
   return 0;
}

