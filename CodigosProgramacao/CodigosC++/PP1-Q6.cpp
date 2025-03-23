#include <iostream>
#include <list>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef unsigned int Weight;

class DigraphAM
{
    private:
        uint num_vertices;
        uint num_edges;
        Weight **adj;

    public:
        DigraphAM(uint num_vertices);
        ~DigraphAM();
        void add_edge(Vertex u, Vertex v);
        void remove_edge(Vertex u, Vertex v);
        uint get_num_vertices() const { return num_vertices; };
        uint get_num_edges() const { return num_edges; };
        std::list<Vertex> get_adj(Vertex v);
        Weight get_weight_edge(Vertex u, Vertex v);
        void print_matrix();
};

DigraphAM::DigraphAM(uint _num_vertices): num_vertices(_num_vertices),
                                          num_edges(0) {
    const uint LINHAS = num_vertices;
    const uint COLUNAS = num_vertices;
    adj = new Weight*[LINHAS];

    for (uint u = 0; u < LINHAS; ++u) {
        adj[u] = new Weight[COLUNAS];        
        for (uint v = 0; v < COLUNAS; ++v) {
            adj[u][v] = 0;
        }
    }
}

DigraphAM::~DigraphAM() {
    for (uint i = 0; i < num_vertices; ++i)
        delete[] adj[i];
    
    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;
}

void DigraphAM::add_edge(Vertex u, Vertex v) 
{
    if (adj[u][v] == 0) 
    {
        adj[u][v] = 1;
        num_edges++;
    }
}

void DigraphAM::remove_edge(Vertex u, Vertex v) 
{
    adj[u][v] = 0;
    num_edges--;
}

// Procurar entender isso
std::list<Vertex> DigraphAM::get_adj(Vertex v) 
{
    std::list<Vertex> adj_list;
    for (uint u = 0; u < num_vertices; ++u) {
        if (adj[v][u] != 0) {
            adj_list.push_back(u);
        }
    }
    return adj_list;
}

Weight DigraphAM::get_weight_edge(Vertex u, Vertex v) {
    return adj[u][v];
}

void DigraphAM::print_matrix() 
{
    std::cout << "num_vertices: " << get_num_vertices() << std::endl;
    std::cout << "num_edges: " << get_num_edges() << std::endl;

    for (uint u = 0; u < get_num_vertices(); ++u) {
        for (uint v = 0; v < get_num_vertices(); ++v) {
            std::cout << get_weight_edge(u, v) << " ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    uint num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    DigraphAM graph(num_vertices);
    for (uint i = 0; i < num_edges; i++) 
    {
        Vertex u, v;
        std::cin >> u >> v;
        graph.add_edge(u, v);
    }

    graph.print_matrix();

    return 0;
}