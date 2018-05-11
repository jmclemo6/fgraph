#include "fgraph.hpp"

// Driver program for fgraph
int main(int argc, char **argv) 
{
	fgraph f;
    std::string filename;
    std::map <int, node*> graph;

	if (argc < 2) { 
        std::cout << "Usage: fgraph <filename>" << std::endl;
		return 1;
	}
	filename = argv[1];

	graph = f.graph_create( f.file_read(filename) );
	f.graph_print(graph);

	return 0;
}
