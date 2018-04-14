#include "fgraph.hpp"

void graph_print(map <int, node*> graph) 
{
	for (auto it = graph.begin(); it != graph.end(); it++) {
		cout << "NODE: " << it->second->id << ": EDGES {";
		for (int i = 0; i < it->second->adj.size(); i++) {
			cout << it->second->adj[i]; 
			if ( i < it->second->adj.size() - 1 ) {
				cout << ",";
			}
		}
		cout << "}" << endl;
	}
}

vector <string> file_read(string filename) 
{
	ifstream file;
	string line;
	vector <string> lines;

	file.open(filename); 
	if ( !file.is_open() ) {
		file.close();
		cout << "Could not open file " << filename << endl;
		exit(-1);
	}

	while ( getline(file, line) ) {
		lines.push_back(line);	
	}
	file.close();

	return lines;
}

node *node_create(string line) 
{
	stringstream ss;
	node *new_node = NULL; 
	int id, edge;

	new_node = new node;
	ss << line;
	ss >> id; 
	new_node->id = id;
	while (ss >> edge) {
		new_node->adj.push_back(edge);	
	}
	ss.clear();

	return new_node;
}

map <int, node*> graph_create(vector <string> input_lines) 
{
	int i;
	map <int, node*> graph;
	node *new_node;

	for (i = 0; i < input_lines.size(); i++) {
		new_node = node_create(input_lines[i]);
		graph[new_node->id] = new_node;
	}

	return graph;
}

int main(int argc, char **argv) 
{
	string filename;
	map <int, node*> graph;

	if (argc < 2) { 
		cout << "Usage: fgraph <filename>" << endl;
		return 1;
	}
	filename = argv[1];

	graph = graph_create( file_read(filename) );
	graph_print(graph);

	return 0;
}
