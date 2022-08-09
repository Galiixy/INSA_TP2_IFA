GCC = g++
CCFLAGS = -c -ansi -pedantic -Wall -std=c++11
OBJETS = TMenu.o TrajetSimple.o Trajet.o CollectionTrajets.o Catalogue.o TrajetCompose.o
EXE = demo
CLEAN = rm *.o $(EXE)

#TRACE = -DMAP

$(EXE) : $(OBJETS)
	$(GCC) -o $(EXE) $(OBJETS) 

%.o:%.cpp
	$(GCC) $(CCFLAGS) $< $(TRACE)

TMenu.o: TMenu.cpp
TrajetSimple.o: TrajetSimple.cpp
Trajet.o: Trajet.cpp
CollectionTrajets.o: CollectionTrajets.cpp
Catalogue.o: Catalogue.cpp
TrajetCompose.o: TrajetCompose.cpp

clean:
	$(CLEAN)