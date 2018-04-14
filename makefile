all: fgraph

fgraph: fgraph.cpp
	g++ -std=c++11 fgraph.cpp -o fgraph

clean: 
	rm fgraph
