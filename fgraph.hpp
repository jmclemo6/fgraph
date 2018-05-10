#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

struct node {
	int id;
	int degree; 
    std::vector <int> adj; // indicates edge from id -> adj[i]
};

class fgraph {
	public:
        std::vector <std::string> file_read(std::string filename);
        void graph_print(std::map <int, node*> graph); 
        node *node_create(std::string line);
        std::map <int, node*> graph_create(std::vector <std::string> input_lines);
};
