#include <iostream>
#include "lexer.h"
#include "Automate.h"

using namespace std;

void test_valid_1(bool ignoreError) {
   string testInput = "(5+3)*2";
   cout << "==== Running test1 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 16" << endl;
   cout << "==== Test1 finished ====" << endl << endl;
}

void test_valid_2(bool ignoreError) {
   string testInput = "1+2*3";
   cout << "==== Running test2 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 7" << endl;
   cout << "==== Test2 finished ====" << endl << endl;
}

void test_valid_3(bool ignoreError) {
   string testInput = "10+20*30";
   cout << "==== Running test3 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 610" << endl;
   cout << "==== Test3 finished ====" << endl << endl;
}

void test_valid_4(bool ignoreError) {
   string testInput = "(8*3)+4";
   cout << "==== Running test4 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 28" << endl;
   cout << "==== Test4 finished ====" << endl << endl;
}

void test_valid_5(bool ignoreError) {
   string testInput = "7*(6+5)";
   cout << "==== Running test5 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 77" << endl;
   cout << "==== Test5 finished ====" << endl << endl;
}

void test_valid_6(bool ignoreError) {
   string testInput = "((1+2)*3)";
   cout << "==== Running test6 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 9" << endl;
   cout << "==== Test6 finished ====" << endl << endl;
}

void test_valid_8(bool ignoreError) {
   string testInput = "(4+5)*6";
   cout << "==== Running test8 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 54" << endl;
   cout << "==== Test8 finished ====" << endl << endl;
}

void test_valid_9(bool ignoreError) {
   string testInput = "2*(3+4*5)";
   cout << "==== Running test9 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 46" << endl;
   cout << "==== Test9 finished ====" << endl << endl;
}

void test_valid_10(bool ignoreError) {
   string testInput = "(1+(2*(3+(4*(5+(6*7))))))";
   cout << "==== Running test10 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 383" << endl;
   cout << "==== Test10 finished ====" << endl;
}

void test_valid_11(bool ignoreError) {
   string testInput = "(((3+2)))";
   cout << "==== Running test14 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 5" << endl;
   cout << "==== Test14 finished ====" << endl << endl;
}

void test_valid_12(bool ignoreError) {
   string testInput = "2+3*4+5*6";
   cout << "==== Running test12 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 2 + (3*4) + (5*6) = 2 + 12 + 30 = 44" << endl;
   cout << "==== Test12 finished ====" << endl << endl;
}

void test_valid_13(bool ignoreError) {
   string testInput = "2+3*4+5*6";
   cout << "==== Running test13 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : 2 + (3*4) + (5*6) = 2 + 12 + 30 = 44" << endl;
   cout << "==== Test13 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_14(bool ignoreError) {
   string testInput = "+()1**2)";
   cout << "==== Running test14 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1*2) = 2, Erreurs positions: 1, 3 et 6" << endl;
   cout << "==== Test14 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_15(bool ignoreError) {
   string testInput = "(1**2)++3";
   cout << "==== Running test15 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1*2) + 3 = 5, Erreurs positions: 4 et 8" << endl;
   cout << "==== Test15 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_16(bool ignoreError) {
   string testInput = "1**2";
   cout << "==== Running test16 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1*2) = 2, Erreur position: 3" << endl;
   cout << "==== Test16 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_17(bool ignoreError) {
   string testInput = "1++2";
   cout << "==== Running test17 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : 1 + 2 = 3, Erreur position: 3" << endl;
   cout << "==== Test17 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_18(bool ignoreError) {
   string testInput = "1+2(";
   cout << "==== Running test18 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : 1 + 2 = 3, Erreur position: 4" << endl;
   cout << "==== Test18 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_19(bool ignoreError) {
   string testInput = "(1+2)(";
   cout << "==== Running test19 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1+2) = 3, Erreur position: 6" << endl;
   cout << "==== Test19 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_20(bool ignoreError) {
   string testInput = "1*2(";
   cout << "==== Running test20 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : 1 * 2 = 2, Erreur position: 4" << endl;
   cout << "==== Test20 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_21(bool ignoreError) {
   string testInput = "(1*2)(";
   cout << "==== Running test21 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1*2) = 2, Erreur position: 6" << endl;
   cout << "==== Test21 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_22(bool ignoreError) {
   string testInput = "(1+2()";
   cout << "==== Running test22 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1 + 2) = 3, Erreur position: 5" << endl;
   cout << "==== Test22 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_23(bool ignoreError) {
   string testInput = "(1*2()";
   cout << "==== Running test23 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1 * 2) = 2, Erreur position: 5" << endl;
   cout << "==== Test23 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_24(bool ignoreError) {
   string testInput = "(1+2y)";
   cout << "==== Running test24 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1 + 2) = 3, Erreur position: 5" << endl;
   cout << "==== Test24 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_25(bool ignoreError) {
   string testInput = "(1*y2)";
   cout << "==== Running test25 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1 * 2) = 2, Erreur position: 4" << endl;
   cout << "==== Test25 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_26(bool ignoreError) {
   string testInput = "((1+2";
   cout << "==== Running test26 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : ((1 + 2)) = 3, Erreur position: 6" << endl;
   cout << "==== Test26 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_27(bool ignoreError) {
   string testInput = "(1+2";
   cout << "==== Running test27 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1 + 2) = 3, Erreur position: 5" << endl;
   cout << "==== Test27 finished ====" << endl << endl;
}

void test_valid_ignoreErrors_28(bool ignoreError) {
   string testInput = "(1+(2*3";
   cout << "==== Running test28 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : (1+(2*3)) = 7, Erreur position: 8" << endl;
   cout << "==== Test28 finished ====" << endl << endl;
}

void test_valid_29(bool ignoreError) {
   string testInput = "1";
   cout << "==== Running test29 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : 1" << endl;
   cout << "==== Test29 finished ====" << endl << endl;
}

void test_valid_30(bool ignoreError) {
   string testInput = "1+2+3";
   cout << "==== Running test30 : ====" << endl;
   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);
   cout << "Processing expression: " << testInput << endl;
   automate.lecture();
   cout << "Attendu : 1 + 2 + 3 = 6" << endl;
   cout << "==== Test30 finished ====" << endl << endl;
}

void test_invalid_1(bool ignoreError) {
   string testInput = "";
   cout << "==== Running test_invalid_1 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 1" << endl;
   cout << "==== Test_invalid_1 finished ====" << endl << endl;
}

void test_invalid_2(bool ignoreError) {
   string testInput = "()";
   cout << "==== Running test_invalid_2 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 2" << endl;
   cout << "==== Test_invalid_2 finished ====" << endl << endl;
}

void test_invalid_3(bool ignoreError) {
   string testInput = "(";
   cout << "==== Running test_invalid_3: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 2" << endl;
   cout << "==== Test_invalid_3 finished ====" << endl << endl;
}

void test_invalid_4(bool ignoreError) {
   string testInput = ")";
   cout << "==== Running test_invalid_4: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 1" << endl;
   cout << "==== Test_invalid_4 finished ====" << endl << endl;
}

void test_invalid_5(bool ignoreError) {
   string testInput = "1+";	
   cout << "==== Running test_invalid_5: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 3" << endl;
   cout << "==== Test_invalid_5 finished ====" << endl << endl;
}

void test_invalid_6(bool ignoreError) {
   string testInput = "1+2+";
   cout << "==== Running test_invalid_6: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 5" << endl;
   cout << "==== Test_invalid_6 finished ====" << endl << endl;
}

void test_invalid_7(bool ignoreError) {
   string testInput = "1-2";
   cout << "==== Running test_invalid_7: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 2 et 3" << endl;
   cout << "==== Test_invalid_7 finished ====" << endl << endl;
}

void test_invalid_8(bool ignoreError) {
   string testInput = "1^2";
   cout << "==== Running test_invalid_8: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 2 et 3" << endl;
   cout << "==== Test_invalid_8 finished ====" << endl << endl;
}

void test_invalid_9(bool ignoreError) {
   string testInput = "1*2+";
   cout << "==== Running test_invalid_9: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 5" << endl;
   cout << "==== Test_invalid_9 finished ====" << endl << endl;
}

void test_invalid_10(bool ignoreError) {
   string testInput = "1+2*";
   cout << "==== Running test_invalid_10: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur à la position 5" << endl;
   cout << "==== Test_invalid_10 finished ====" << endl << endl;
}





// Fonction pour exécuter tous les tests
void runTests() {
   cout << "===== Running All Tests =====" << endl;
   test_valid_1(true);
   test_valid_2(true);
   test_valid_3(true);
   test_valid_4(true);
   test_valid_5(true);
   test_valid_6(true);
   test_valid_8(true);
   test_valid_9(true);
   test_valid_10(true);
   test_valid_11(true);
   test_valid_12(true);
   test_valid_13(true);
   test_valid_ignoreErrors_14(true);
   test_valid_ignoreErrors_15(true);
   test_valid_ignoreErrors_16(true);
   test_valid_ignoreErrors_17(true);
   test_valid_ignoreErrors_18(true);
   test_valid_ignoreErrors_19(true);
   test_valid_ignoreErrors_20(true);
   test_valid_ignoreErrors_21(true);
   test_valid_ignoreErrors_22(true);
   test_valid_ignoreErrors_23(true);
   test_valid_ignoreErrors_24(true);
   test_valid_ignoreErrors_25(true);
   test_valid_ignoreErrors_26(true);
   test_valid_ignoreErrors_27(true);
   test_valid_ignoreErrors_28(true);
   test_valid_29(true);
   test_valid_30(true);
   test_invalid_1(true);
   test_invalid_2(true);
   test_invalid_3(true);
   test_invalid_4(true);
   test_invalid_5(true);
   test_invalid_6(true);
   test_invalid_7(true);
   test_invalid_8(true);
   test_invalid_9(true);
   test_invalid_10(true);
   cout << "===== All tests completed! =====" << endl;
   
}

int main(int argc, char **argv) {

   if(argc == 2 && string(argv[1]) == "-help") {
      cout << "Usage: " << argv[0] << " [options]" << endl;
      cout << "Options:" << endl;
      cout << "  -help          Display this help message" << endl;
      cout << "  -t             Enable verbose mode (trace transitions)" << endl;
      cout << "  -i             Ignore errors and continue parsing" << endl;
      cout << "  -test          Run all tests" << endl;
      cout << "  -exec <expr>   Execute the given arithmetic expression" << endl;
      cout << "                 But <expr> has to be between \"\"" << endl;
      return 0;
   }
   
   bool t = false;
   bool i = false;
   bool runTestsFlag = false;
   bool execFlag = false;
   string chaine = "(1+34)*123"; // Expression par défaut

   if (argc > 1) {
      for (int j = 1; j < argc; j++) {
         string arg = argv[j];

         if (arg == "-t") {
            t = true;
         } else if (arg == "-i") {
            i = true;
         } else if (arg == "-test") {
            runTestsFlag = true;
         } else if (arg == "-exec") {
            if (j + 1 < argc) { // Vérifier qu'une expression suit -exec
               chaine = argv[j + 1];
               execFlag = true;
               j++; // Ignorer l'argument suivant (l'expression)
            } else {
               cout << "ERROR: -exec requires an expression as an argument!" << endl;
               return 1; // Code d'erreur
            }
         } else {
            cout << "UNKNOWN OPTION: " << arg << endl;
            return 1; // Code d'erreur
         }
      }
   }

   // Soit -test, soit -exec, mais pas les deux
   if (runTestsFlag && execFlag) {
      cout << "ERROR: Cannot use both -test and -exec at the same time!" << endl;
      return 1; // Code d'erreur
   }

   // Exécution des tests
   if (runTestsFlag) {
      runTests();
      return 0;
   }

   // Exécution de l'analyse d'expression
   cout << "Processing expression: " << chaine << endl;
   Lexer l(chaine);
   Automate a(&l, t, i);
   a.lecture();

   return 0;
}
