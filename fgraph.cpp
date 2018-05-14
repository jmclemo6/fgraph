#include "fgraph.hpp"

// Prints each node in the graph and it's adjacencies
void fgraph::graph_print(std::map <int, node*> graph) 
{
	for (auto it = graph.begin(); it != graph.end(); it++) {
        std::cout << "NODE: " << it->second->id << ": EDGES {";
		for (int i = 0; i < it->second->adj.size(); i++) {
            std::cout << it->second->adj[i]; 
			if ( i < it->second->adj.size() - 1 ) {
                std::cout << ",";
			}
		}
        std::cout << "}" << std::endl;
	}
}

// Reads from file filename and returns a vector of strings that contains
// the lines of filename
std::vector <std::string> fgraph::file_read(std::string filename) 
{
    std::ifstream file;
    std::string line;
    std::vector <std::string> lines;

	file.open(filename); 
	if ( !file.is_open() ) {
		file.close();
        std::cout << "Could not open file " << filename << std::endl;
		exit(-1);
	}

	while ( getline(file, line) ) {
		lines.push_back(line);	
	}
	file.close();

	return lines;
}

// Parse lines from file and create a node object for each node
std::map <int, node*> fgraph::graph_create(std::vector <std::string> input_lines) 
{
    std::map <int, node*> graph;
	node *new_node;

	for (int i = 0; i < input_lines.size(); i++) {
		new_node = node_create(input_lines[i]);
		graph[new_node->id] = new_node;
	}

	return graph;
}

// Create a new node for each node entry in the file
node * fgraph::node_create(std::string line) 
{
    std::stringstream ss;
	node *new_node = NULL; 
	int id, edge;

	// Node specification: 
	// id adj adj adj
	new_node = new node;
	ss << line;
	ss >> id; 
	new_node->id = id;
	while ( ss >> edge ) {
		new_node->adj.push_back(edge);	
	}
	ss.clear();

	return new_node;
}
