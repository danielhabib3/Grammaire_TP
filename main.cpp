#include <iostream>
#include "lexer.h"
#include "Automate.h"



int main(int argc, char **argv) {
   string chaine("(1+34)*123");

   bool t = false;
   bool i = false;

   if(argc > 1) {
      for(int i = 1; i < argc; i++) {
         if(string(argv[i]) == "-t") {
            t = true;
         }
         else if(string(argv[i]) == "-i") {
            i = true;
         }
         else {
            chaine = string(argv[i]);
            cout << "UNKNOWN OPTION: " << argv[i] << endl;
         }
      }
   }


   Lexer l(chaine);

   Automate a(&l, t, i);
   a.lecture();
   return 0;
}

