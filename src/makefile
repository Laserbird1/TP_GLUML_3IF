#
#__Makefile générique__Edouard de Brye
#

EXEC = test #nom executableA
DEBUG =yes #mettre "yes" pour mode developpeur, autre chose pour mode realease


.PHONY: clean 
REAL = $(wildcard *.cpp)
OBJ = $(REAL:.cpp=.o)
CXX = g++
CXXFLAGS1= -Wall  -W -Wextra -pedantic -ansi -Wconversion 

ifeq ($(DEBUG),"yes")

CXXFLAGS = -g $(CXXFLAGS1)
LDFLAGS =-g

else

CXXFLAGS =$(CXXFLAGS1) -O2
LDFLAGS = -O2

endif

 
all : $(EXEC)

#regle à recopier pour chaque nouveau cpp, remplacer % par le nom, ajouter tous les .h utiles
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(EXEC):$(OBJ)
	$(CXX) $(LDFLAGS) -o $(EXEC) $^

clean :
	rm -f *.o core $(EXEC)