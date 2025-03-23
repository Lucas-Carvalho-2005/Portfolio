#include <iostream>
#include <list>
#include <limits>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef double Weight;

class WeightedDigraphAM
{
    private:
        uint num_vertices;
        uint num_edges;
        Weight **adj;

    public:
        double inf = std::numeric_limits<double>::infinity();
        WeightedDigraphAM(uint num_vertices);
        ~WeightedDigraphAM();
        void add_edge(Vertex u, Vertex v, Weight w);
        void remove_edge(Vertex u, Vertex v);
        uint get_num_vertices() { return num_vertices; };
        uint get_num_edges() { return num_edges; };
        std::list<Vertex> get_adj(Vertex v);
        Weight get_weight_edge(Vertex u, Vertex v) { return adj[u][v]; };
        void print_matrix();
};

WeightedDigraphAM::WeightedDigraphAM(uint _num_vertices): num_vertices(_num_vertices), 
                                                      num_edges(0)
{
    const uint LINHAS = num_vertices;
    const uint COLUNAS = num_vertices;
    adj = new Weight*[LINHAS];

    for (uint u = 0; u < LINHAS; ++u){
        adj[u] = new Weight[COLUNAS];
        for (uint v = 0; v < COLUNAS; ++v) {
             adj[u][v] = inf;
        }
    }
}

WeightedDigraphAM::~WeightedDigraphAM()
{
    for (uint i = 0; i < num_vertices; ++i)
        delete[] adj[i];

    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;
}

void WeightedDigraphAM::add_edge(Vertex u, Vertex v, Weight w)
{
    if (adj[u][v] == inf)
    {
        adj[u][v] = w;
        num_edges++;
    }

}

void WeightedDigraphAM::remove_edge(Vertex u, Vertex v)
{
    adj[u][v] = inf;
    num_edges--;
}

std::list<Vertex> WeightedDigraphAM::get_adj(Vertex v)
{
    std::list<Vertex> adj_vertices;

    for (Vertex u = 0; u < get_num_vertices(); ++u) {
        if (adj[v][u] != inf) {
            adj_vertices.push_back(u);
        }
    }

    return adj_vertices;
}

void WeightedDigraphAM::print_matrix()
{
    std::cout << "num_vertices: " << get_num_vertices() << std::endl;
    std::cout << "num_edges: " << get_num_edges() << std::endl;

    for (Vertex u = 0; u < get_num_vertices(); ++u) {
        for (Vertex v = 0; v < get_num_vertices(); ++v) {
            std::cout << get_weight_edge(u, v) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    uint num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    WeightedDigraphAM graph(num_vertices);
    for (uint i = 0; i < num_edges; ++i)
    {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

    graph.print_matrix();
    return 0;
}