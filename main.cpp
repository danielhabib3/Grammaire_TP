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

void test_invalid_1(bool ignoreError) {
   string testInput = "";
   cout << "==== Running test_invalid_1 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur" << endl;
   cout << "==== Test_invalid_1 finished ====" << endl << endl;
}

void test_invalid_2(bool ignoreError) {
   string testInput = "()";
   cout << "==== Running test_invalid_2 : ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur" << endl;
   cout << "==== Test_invalid_2 finished ====" << endl << endl;
}

void test_invalid_3(bool ignoreError) {
   string testInput = "(";
   cout << "==== Running test_invalid_3: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur" << endl;
   cout << "==== Test_invalid_3 finished ====" << endl << endl;
}

void test_invalid_4(bool ignoreError) {
   string testInput = ")";
   cout << "==== Running test_invalid_4: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur" << endl;
   cout << "==== Test_invalid_4 finished ====" << endl << endl;
}

void test_invalid_5(bool ignoreError) {
   string testInput = ")";
   cout << "==== Running test_invalid_4: ====" << endl;

   Lexer l(testInput);
   Automate automate(&l, false, ignoreError);

   cout << "Processing expression: " << testInput << endl;
   automate.lecture();

   cout << "Attendu : Erreur" << endl;
   cout << "==== Test_invalid_4 finished ====" << endl << endl;
}





// Fonction pour exécuter tous les tests
void runTests(bool ignoreError) {
    cout << "===== Running All Tests =====" << endl;
    test_valid_1(ignoreError);
    test_valid_2(ignoreError);
    test_valid_3(ignoreError);
    test_valid_4(ignoreError);
    test_valid_5(ignoreError);
    test_valid_6(ignoreError);
    test_valid_8(ignoreError);
    test_valid_9(ignoreError);
    test_valid_10(ignoreError);
    cout << "===== All tests completed! =====" << endl;
}

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
        runTests(i);
        return 0;
    }

    // Exécution de l'analyse d'expression
    cout << "Processing expression: " << chaine << endl;
    Lexer l(chaine);
    Automate a(&l, t, i);
    a.lecture();

    return 0;
}
