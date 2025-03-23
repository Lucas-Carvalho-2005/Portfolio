#include <iostream>
#include <list>

typedef unsigned int uint;
typedef unsigned int Vertex;

class DigraphAL
{
	private:
		uint num_vertices;
		uint num_edges;
		std::list<Vertex> *adj; // vetor de listas

	public:
		DigraphAL(uint num_vertices);
		~DigraphAL();
		void add_edge(Vertex u, Vertex v);
		void remove_edge(Vertex u, Vertex v);
		uint get_num_vertices() { return num_vertices; };
		uint get_num_edges() { return num_edges; };
		std::list<Vertex> get_adj(Vertex v) { return adj[v]; };
		void print_adj(std::list<Vertex> adj);
		void print_graph();
};

DigraphAL::DigraphAL(uint _num_vertices): num_vertices(_num_vertices) 
{
	adj = new std::list<Vertex>[num_vertices];
	num_edges = 0;
}

DigraphAL::~DigraphAL() 
{
	for (uint i = 0; i < num_vertices; ++i) {
		adj[i].clear();
	}
	delete[] adj;
	adj = nullptr;
	num_vertices = num_edges = 0;
}

void DigraphAL::add_edge(Vertex u, Vertex v) 
{
    for (auto added_vertex: adj[u]) {
        if (v == added_vertex || v == u)
            return;
    }

    adj[u].push_back(v);
	num_edges++;
}

void DigraphAL::remove_edge(Vertex u, Vertex v) 
{
	adj[u].remove(v);
	num_edges--;
}

void DigraphAL::print_adj(std::list<Vertex> adj) 
{
	for (auto v: adj) {
		std::cout << v << ", ";
	}	
}

void DigraphAL::print_graph() 
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

	DigraphAL graph(num_vertices);
	for (uint i = 0; i < num_edges; ++i)
	{
		Vertex u, v;
		std::cin >> u >> v;
		graph.add_edge(u, v);
	}

	graph.print_graph();

	return 0;
}