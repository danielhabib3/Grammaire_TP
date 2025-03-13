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

#### Mode standard : exécution de l'expression arithmétique par défaut du TP : (1+34)*123
```sh
./mon_programme
```
#### Affichage de toutes les options disponibles :
```sh
./mon_programme -help
```

#### Analyse d’une expression spécifique (Il faut mettre l'expression entre guillemets) :
```sh
./mon_programme -exec "(1+2)*3"
```
#### Mode verbose (trace des transitions) :
```sh
./mon_programme -t -exec "(4+5)*6"
```

#### Mode ignorer les erreurs, reprise eventuelle d'analyse si erreur syntaxique trouvée (avec trace des erreurs trouvées) :
```sh
./mon_programme -i -exec "(4++5)*6"
```
#### Exécution des tests (38 tests) :
```sh
./mon_programme -test
```
**remarques** Les tests sont executés automatiquement avec l'option '-i', même si vous ne la choisissez pas```

#### Remarques

Vous pouvez également combiner les options `-t` et `-i` pour afficher les traces et ignorer les erreurs.

Mais vous ne pouvez pas combiner les options `-test` et `-exec`.

De plus, les tests sont toujours executés sans l'option '-t' (car sinon cela générerait trop de texte (38 tests)) et avec l'option '-i'. 

## Choix dans le traitement des expressions arithmétiques avec erreur(s) de syntaxe (-i)

### Sans l'option -i

Si l'expression arithmétique est syntaxiquement incorrecte alors le programme arrête l'analyse à la première erreur et affiche une erreur

**Exemples :** "(4++5)*6" est syntaxiquement incorrecte car il y a deux '+' qui se suivent

### Avec l'option -i

Si on met l'option -i, le programme continue l'analyse de l'expression jusqu'à la fin en ignorant les potentielles erreurs (que l'on a traitées) rencontrées. Le programme affiche les erreurs rencontrées ainsi que l'expression qui a été évaluée. Pour chaque erreur, l’analyseur affiche la position et le type d’erreur rencontrée.

**Exemples :** "(4++5)*6" :

Processing expression: (4++5)*6 <br/>
Accepté <br/>
Valeur de l'expression: 54  <br/>
Expression evaluée: (4+5)*6 <br/>
1 Erreur(s) de syntaxe trouvée(s) : <br/>
Erreur à la position 4, PLUS trouvé alors que INT OU OPENPAR attendus. 

#### Erreurs syntaxiques traitées et choix (cf : Tests)

| Description erreur traitée                                       | Choix réalisé pour continuer l'analyse        | Exemple entrée        | Résultat attendu            |
|----------------------------------------------------------------|----------------------------------------|----------------|--------------------|
| Double opérateur `**`                                          | Ignorer le second opérateur : Remplacer `**` par `*`                | `1**2`         | `(1*2) = 2`        |
| Double opérateur `++`                                          | Ignorer le second opérateur : Remplacer `++` par `+`                | `1++2`         | `1 + 2 = 3`        |
| Double opérateur `**` et `++`                                  | Ignorer le second opérateur : Remplacer `**` par `*` et `++` par `+` | `(1**2)++3`   | `(1*2) + 3 = 5`   |
| Parenthèse ouverte après expression                                 | Ignorer la parenthèse ouverte         | `1+2(`         | `1 + 2 = 3`        |
| Parenthèse ouverte au milieu de l'expression       | Ignorer la parenthèse ouverte         | `(1+2()`      | `(1 + 2) = 3`     |
| Caractère invalide                                             | Ignorer le caractère invalide `y`     | `(1+2y)`      | `(1 + 2) = 3`     |
| Parenthèse(s) non fermée(s)                               | Fermer la/les parenthèse(s) ouverte(s) non fermée(s)| `((1+2`        | `((1 + 2)) = 3`   |
| Parenthèse ouverte non fermée dans une expression imbriquée  | Fermer la/les parenthèse(s) ouverte(s) non fermée | `(1+(2*3`     | `(1+(2*3)) = 7`   |
| Opérateur en début d'expression et parenthèse fermante en trop et double opérateur | Ignorer l'opérateur en début d'expression  et la parenthèse fermante en trop | `+()1**2)`     | `(1*2) = 2`        |


#### Exemples d'erreurs non traitées (même avec -i)

| Description erreur non traitée                              | Exemple entrée| Résultat attendu         |
|----------------------------------------------------|----------|--------------------|
| Expression vide                                       | `""`        | Erreur à la position 1 |
| Parenthèses vides                                   | `()`       | Erreur à la position 2 |
| Parenthèse ouvrante non fermée               | `(`         | Erreur à la position 2 |
| Parenthèse fermante sans ouverture           | `)`         | Erreur à la position 1 |
| Opérateur en fin d'expression  (sans opérande après)       | `1+`       | Erreur à la position 3 |
| Opérateur `-` non supporté                           | `1-2`      | Erreur à la position 2 et 3 |
| Opérateur `^` non supporté                           | `1^2`      | Erreur à la position 2 et 3 |
| Opérateur `+` après une multiplication             | `1*2+`    | Erreur à la position 5 |

## Auteurs
Groupe 3 H4231
Projet réalisé par LEVRARD Thomas, SOW Amadou et HABIB Danial.

