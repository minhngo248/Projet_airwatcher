CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g
VUEPATH = %.o ../vue
EXE = main
OBJETS = main.cpp

$(EXE) : $(OBJETS) $(EXE).cpp
	@echo "Édition des liens de main"
	g++ -o $@ $^

clean:
	@echo "Suppresion des fichiers compilés"
	rm main

memoryCheck:
	make clean
	@echo "Vérification de la gestion de mémoire"
	make CPPFLAGS='$(CPPFLAGS) -DMAP -g'
	valgrind ./main --track-origins=yes
