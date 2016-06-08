CC=g++
CPPFLAGS=-std=c++11 -Wall
OBJECTS=gitversion.o wheel.o arrangement.o
TARGET=enigma

enigma: main.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) -O2 $< $(OBJECTS) -o $@

debug: main.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) -g $< $(OBJECTS) -o $(TARGET)_debug

all: debug enigma

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $<

gitversion.cpp: .git/HEAD .git/index
	echo "#include <string>" > $@
	echo "std::string gitversion = \"$(shell git rev-parse HEAD)\";" >> $@

clean: 
	rm $(TARGET)_debug $(TARGET) gitversion.cpp $(OBJECTS)
