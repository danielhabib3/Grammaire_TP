#include <iostream>
#include "lexer.h"
#include "Automate.h"



int main(int argc, char **argv) {
   string chaine("(1++34)++123");

   bool t = false;
   bool i = false;

   if(argc > 1) {
      for(int j = 1; j < argc; j++) {
         if(string(argv[j]) == "-t") {
            t = true;
         }
         else if(string(argv[j]) == "-i") {
            i = true;
         }
         else {
            cout << "UNKNOWN OPTION: " << argv[j] << endl;
         }
      }
   }


   Lexer l(chaine);

   Automate a(&l, t, i);
   a.lecture();
   return 0;
}

