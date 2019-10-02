CC=g++
CXXFLAGS=-g -std=c++17
ODIR=src
BUILD=build

_OBJ=$(BUILD)/Analiza.o $(BUILD)/analisis.o $(BUILD)/funciones.o
OBJ=$(patsubst %,%,$(_OBJ))

all:Analiza
$(BUILD)/Analiza.o: $(ODIR)/Analiza.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/analisis.o: $(ODIR)/analisis.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/funciones.o: $(ODIR)/funciones.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

Analiza: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* Analiza

