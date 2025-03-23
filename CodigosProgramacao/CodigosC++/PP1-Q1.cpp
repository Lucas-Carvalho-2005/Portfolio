#include <iostream>
#include <list>

typedef unsigned int uint;
typedef unsigned int Vertex;

class GraphAL 
{
	private:
		uint num_vertices;
		uint num_edges;
		std::list<Vertex> *adj; // vetor de listas

	public:
		GraphAL(uint num_vertices);
		~GraphAL();
		void add_edge(Vertex u, Vertex v);
		void remove_edge(Vertex u, Vertex v);
		uint get_num_vertices() { return num_vertices; };
		uint get_num_edges() { return num_edges; };
		std::list<Vertex> get_adj(Vertex v) { return adj[v]; };
		void print_adj(std::list<Vertex> adj);
		void print_graph();
};

GraphAL::GraphAL(uint _num_vertices): num_vertices(_num_vertices) 
{
	adj = new std::list<Vertex>[num_vertices];
	num_edges = 0;
}

GraphAL::~GraphAL() 
{
	for (uint i = 0; i < num_vertices; ++i) {
		adj[i].clear();
	}
	delete[] adj;
	adj = nullptr;
	num_vertices = num_edges = 0;
}

void GraphAL::add_edge(Vertex u, Vertex v) 
{
	adj[u].push_back(v);
	adj[v].push_back(u);
	num_edges++;
}

void GraphAL::remove_edge(Vertex u, Vertex v) 
{
	adj[u].remove(v);
	adj[v].remove(u);
	num_edges--;
}

void GraphAL::print_adj(std::list<Vertex> adj) 
{
	for (auto v: adj) {
		std::cout << v << ", ";
	}	
}

void GraphAL::print_graph() 
{
	std::cout << "num_vertices: " << get_num_vertices() << std::endl;
	std::cout << "num_edges: " << get_num_edges() << std::endl;

	for (Vertex v = 0; v < get_num_vertices(); ++v) 
	{
		std::cout << v << ": ";
		print_adj(get_adj(v));
		std::cout << std::endl;
	}
}

int main() 
{
	uint num_vertices, num_edges;
	std::cin >> num_vertices >> num_edges;

	GraphAL graph(num_vertices);
	for (uint i = 0; i < num_edges; ++i)
	{
		Vertex u, v;
		std::cin >> u >> v;
		graph.add_edge(u, v);
	}

	graph.print_graph();

	return 0;
}