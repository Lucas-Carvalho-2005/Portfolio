#include <iostream>
#include <list>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef float Weight;

class VertexWeightPair
{
    public:
        Vertex vertex;
        Weight weight;
        
        VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {} //uso de lista de inicializacao
};

class WeightedDigraphAL
{
    private:
        uint num_vertices;
        uint num_edges;
        std::list<VertexWeightPair> *adj;

    public:
        WeightedDigraphAL(uint num_vertices);
        ~WeightedDigraphAL();
        void add_edge(Vertex u, Vertex v, Weight w);
        void remove_edge(Vertex u, Vertex v);
        uint get_num_vertices() { return num_vertices; };
        uint get_num_edges() { return num_edges; };
        std::list<VertexWeightPair> get_adj(Vertex v) { return adj[v]; };
        void print_graph();
};

WeightedDigraphAL::WeightedDigraphAL(uint _num_vertices): num_vertices(_num_vertices)
{
    adj = new std::list<VertexWeightPair>[num_vertices];
    num_edges = 0;
}

WeightedDigraphAL::~WeightedDigraphAL()
{
    for (uint i = 0; i < num_vertices; i++)
        adj[i].clear();

    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;
}

void WeightedDigraphAL::add_edge(Vertex u, Vertex v, Weight w)
{
    adj[u].emplace_back(v, w);
    num_edges++;
}

void WeightedDigraphAL::remove_edge(Vertex u, Vertex v)
{
    // Funcao lambda para remocao de arestas
    adj[u].remove_if( [v](const VertexWeightPair& pair) { return pair.vertex == v; } );
    num_edges--;
}

void WeightedDigraphAL::print_graph()
{
    std::cout << "num_vertices: " << get_num_vertices() << std::endl;
    std::cout << "num_edges: " << get_num_edges() << std::endl;
    
    for (Vertex v = 0; v < get_num_vertices(); v++) {
        std::cout << v << ": ";
        for (const auto& pair : get_adj(v)) {
            std::cout << "(" << pair.vertex << ", " << pair.weight << "), ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    uint num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    WeightedDigraphAL graph(num_vertices);
    for (uint i = 0; i < num_edges; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

    graph.print_graph();

    return 0;
}