TARGET=grafo
CXX=g++
DEBUG=-g
OPT=-O0
CXXFLAGS=$(DEBUG) $(OPT) $(WARN) -pipe
LD=g++
OBJS= main.o algoritmos_grafo.o grafo.o fila.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
	@rm -rf *.o

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

algoritmos_grafo.o: src/algoritmos_grafo.cpp
	$(CXX) -c $(CXXFLAGS) src/algoritmos_grafo.cpp -o algoritmos_grafo.o

grafo.o: src/grafo.cpp
	$(CXX) -c $(CXXFLAGS) src/grafo.cpp -o grafo.o

fila.o: src/fila.cpp
	$(CXX) -c $(CXXFLAGS) src/fila.cpp -o fila.o
