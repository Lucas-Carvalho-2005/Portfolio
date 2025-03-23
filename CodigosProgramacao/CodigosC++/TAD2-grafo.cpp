#include <iostream>
#include <list>

typedef unsigned int uint; //Basicamente uint abrevia "typedef unsigned int"
typedef unsigned int Vertex; //Idem

class ItemVertex 
{
    public:
        Vertex value;
        ItemVertex(Vertex value): value(value) {}
        ItemVertex(): value(0) {}
};


template <typename T>
class Graph 
{
    private:
        uint num_vertices;
        uint num_edges;
        std::list<T> *adj;

    public:
        Graph(uint num_vertices);
        ~Graph();
        void add_edge(Vertex u, Vertex v);
        // remove_edge(u: Vertex, v: Vertex)
        std::list<Vertex> get_adj(Vertex v) { return adj[v]; };
        uint get_num_vertices(){ return num_vertices; };
        uint get_num_edges(){ return num_edges; };
};


template <typename T>
void Graph<T>::add_edge(Vertex u, Vertex v) 
{
    ItemVertex uu(u);
    ItemVertex vv(v);
	adj[u].push_back(vv);
	adj[v].push_back(uu);
	num_edges++;
}

template <typename T>
void display_list(std::list<T> adj) {
	for (auto v: adj) {
		std::cout << v << ", ";
	}	
}

template <typename T>
void display_graph(Graph<T>& g) {
	for (Vertex v = 1; v <= g.get_num_vertices(); ++v) {
		std::cout << v << ": ";
		std::list<Vertex> adj = g.get_adj(v);
		print_list(adj);
		std::cout << "\n";
	}
}

template <typename T>
void input_graph(Graph<T>& g) {
	g.add_edge(1, 2);
	g.add_edge(1, 5);
	g.add_edge(2, 3);
	g.add_edge(2, 4);
	g.add_edge(2, 5);
	g.add_edge(3, 4);
	g.add_edge(4, 5);
}

int main() {
	uint num_vertices = 5;
	Graph<ItemVertex> g(num_vertices);
	input_graph(g);
	display_graph(g);
	return 0;
}