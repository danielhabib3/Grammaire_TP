# Nom de l'exécutable
EXEC = mon_programme

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Liste des fichiers sources
SRC = main.cpp Automate.cpp Etat.cpp lexer.cpp symbole.cpp

# Objets générés (.o)
OBJ = $(SRC:.cpp=.o)

# Règle principale : compilation de l'exécutable
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Compilation des fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC)

# Nettoyage complet
mrproper: clean
	rm -f *~
