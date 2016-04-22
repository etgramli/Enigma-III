CC=g++
CPPFLAGS=-std=c++11 -Wall
OBJECTS=gitversion.o
TARGET=enigma

debug: main.cpp gitversion.o
	$(CC) $(CPPFLAGS) -g $< $(OBJECTS) -o $(TARGET)_debug

enigma: main.cpp gitversion.o
	$(CC) $(CPPFLAGS) -O2 $< $(OBJECTS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $<

gitversion.c: .git/HEAD .git/index
	echo "const char *gitversion = \"$(shell git rev-parse HEAD)\";" > $@

clean: 
	rm $(TARGET)_debug $(TARGET) gitversion.c $(OBJECTS)
