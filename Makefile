CC=g++
CPPFLAGS=-std=c++11 -Wall
TARGET=enigma

debug: main.cpp
	$(CC) $(CPPFLAGS) -g $< -o $(TARGET)_debug

enigma: main.cpp
	$(CC) $(CPPFLAGS) -O2 $< -o $@

clean: $(TARGET)_debug $(TARGET)
	rm $<
