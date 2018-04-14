#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct node {
	int id;
	int degree; 
	vector <int> adj; // indicates edge from id -> adj[i]
};

vector <string> file_read(string filename);
void graph_print(map <int, node*> graph);
node *node_create(string line);
map <int, node*> graph_create(vector <string> input_lines);
