This is a simple library for creating graphs and operating on them. I plan on expanding this to do fun things 
like creating random graphs, add weights to the edges, and run various algorithms on graphs. 

**Graph Specification**: 
========================
Plaintext files contain graph specification. Each line of the file contains a 
node on the graph. The first entry on the line is an integer id for the node, 
and the following integers are adjacencies from the node to other nodes. 
For example, the line:
```
2 4 9 2  
```
specifies a node with id 2, and edges leading from itself to nodes 4, 9, and an edge to itself. 

**Note**: 
=========

Feel free to roast my code. I'm always looking for a better way to do things.
