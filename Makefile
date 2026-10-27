TARGET=algraph.mol
CXX=g++
DEBUG=-g
OPT=-O0
CXXFLAGS=$(DEBUG) $(OPT) $(WARN) -pipe
LD=g++
OBJS= main.o algoritmos_grafo.o grafo.o fila.o pilha.o fila_prioridade.o union_find.o interface.o algraph.mol.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
	@rm -rf *.o

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

algoritmos_grafo.o: src/algoritmos_grafo.cpp
	$(CXX) -c $(CXXFLAGS) src/algoritmos_grafo.cpp -o algoritmos_grafo.o

grafo.o: src/estrutura_dados/grafo.cpp
	$(CXX) -c $(CXXFLAGS) src/estrutura_dados/grafo.cpp -o grafo.o

fila.o: src/estrutura_dados/fila.cpp
	$(CXX) -c $(CXXFLAGS) src/estrutura_dados/fila.cpp -o fila.o

pilha.o: src/estrutura_dados/pilha.cpp
	$(CXX) -c $(CXXFLAGS) src/estrutura_dados/pilha.cpp -o pilha.o

fila_prioridade.o: src/estrutura_dados/fila_prioridade.cpp
	$(CXX) -c $(CXXFLAGS) src/estrutura_dados/fila_prioridade.cpp -o fila_prioridade.o

union_find.o: src/estrutura_dados/union_find.cpp
	$(CXX) -c $(CXXFLAGS) src/estrutura_dados/union_find.cpp -o union_find.o

interface.o: src/interface.cpp
	$(CXX) -c $(CXXFLAGS) src/interface.cpp -o interface.o

algraph.mol.o: src/algraph.mol.cpp
	$(CXX) -c $(CXXFLAGS) src/algraph.mol.cpp -o algraph.mol.o
