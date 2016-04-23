CC=g++
CPPFLAGS=-std=c++11 -Wall
OBJECTS=gitversion.o wheel.o
TARGET=enigma

debug: main.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) -g $< $(OBJECTS) -o $(TARGET)_debug

enigma: main.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) -O2 $< $(OBJECTS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $<

gitversion.c: .git/HEAD .git/index
	echo "const char *gitversion = \"$(shell git rev-parse HEAD)\";" > $@

clean: 
	rm $(TARGET)_debug $(TARGET) gitversion.c $(OBJECTS)
