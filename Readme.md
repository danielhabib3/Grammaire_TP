# Projet : Analyseur Syntaxique d'Expressions Arithmétiques

## Description

Ce projet implémente un analyseur syntaxique permettant de traiter et d’évaluer des expressions arithmétiques simples comportant les opérateurs `+` et `*`, ainsi que les parenthèses pour gérer la priorité des opérations.

## Fonctionnalités

- Analyse lexicale et syntaxique des expressions mathématiques.
- Gestion des erreurs de syntaxe avec affichage des erreurs détectées.
- Prise en charge des expressions avec des nombres entiers et des parenthèses.
- Mode de test avec plusieurs cas d’utilisation.
- Option d’affichage détaillé du traitement de l’expression (`-t`).

## Structure du projet

- `main.cpp` : Point d’entrée du programme, permet l’exécution et les tests.
- `lexer.h/.cpp` : Analyseur lexical qui découpe l’entrée en tokens.
- `symbole.h/.cpp` : Définition des symboles utilisés dans l’analyseur.
- `etat.h/.cpp` : Définition des états de l’automate syntaxique.
- `automate.h/.cpp` : Automate chargé de l’analyse syntaxique et de l’évaluation.
- `Makefile` : Fichier pour compiler le projet.

## Compilation et Exécution

### Compilation

Utilisez la commande suivante pour compiler le projet :

```sh
make
```

### Exécution

#### Mode standard :
```sh
./mon_programme
```

#### Analyse d’une expression spécifique (Il faut mettre l'expression entre guillemets) :
```sh
./mon_programme -exec "(1+2)*3"
```

#### Exécution des tests :
```sh
./mon_programme -test
```

#### Mode verbose (trace des transitions) :
```sh
./mon_programme -t -exec "(4+5)*6"
```

#### Mode ignorer les erreurs, reprise eventuelle d'analyse si erreur syntaxique trouvée (trace des transitions) :
```sh
./mon_programme -i -exec "(4++5)*6"
```

## Exemples d'entrées invalides

Dans ce cas là "(4++5)*6" si on ne met pas l'option -i, le programme s'arrete à la première erreur syntaxique rencontrée. Si on met l'option -i, le programme continue l'analyse de l'expression jusqu'à la fin en ignorant le deuxième +. Le programme affiche les erreurs rencontrées ainsi que l'expression qui a été évaluée.

## Exemples d'entrées valides

- `(5+3)*2`
- `1+2*3`
- `10+20*30`
- `(8*3)+4`
- `7*(6+5)`

## Gestion des erreurs

Si une expression incorrecte est détectée, l’analyseur affiche la position et le type d’erreur rencontrée.

Exemple :
```
Erreur à la position 2 : ')' trouvé alors que 'INT' attendu.
```

## Auteur

Projet réalisé par LEVRARD Thomas, SOW Amadou et HABIB Danial.

