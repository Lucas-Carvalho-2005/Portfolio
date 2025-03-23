#include <iostream>
#include <list>
typedef unsigned int uint;
typedef unsigned int Vertex;

template <typename T>
class Graph {
private:
    uint num_vertices;
    uint num_edges;

    std::list<T> *adj; // Vetor sendo criado dinamicamente utilizando biblioteca nativa do C++

public:
    Graph();
    ~Graph();
    void add_edge(Vertex u, Vertex v);
    // remove_edge(u: Vertex, v: Vertex);
    std::list<Vertex> get_adj(Vertex v) { return adj[v]; };
    uint get_num_vertices() { return num_vertices; };
    uint get_num_edges() { return num_edges; };
};

Graph<T>::Graph (uint num_vertices):
    num_vertices(num_vertices),
    num_edges(0) {
        adj = new std::list<T>[num_vertices + 1];
    }

Graph<T>::~Graph () {
    for (int i = 0; i <= num_vertices; ++i) {
        adj[i].clear();
    }

    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;

}


template <typename T>
void Graph<T>::add_edge(Vertex u, Vertex v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    num_edges++;
}
    

void input_graph (Graph& g) {
    g.add_edge(1, 2);
    g.add_edge(1, 5)
    g.add_edge(2, 3)
    g.add_edge(2, 4)
    g.add_edge(2, 5)
    g.add_edge(3, 4)
    g.add_edge(4, 5)
}


void print_list (std:list<Vertex> adj) {
    for (auto v: adj) {
        cout << v << ", ";
    } //*ver se o "auto" funciona
}


template <typename T>
void display_graph(Graph<T>& g) {
    for (Vertex v = 1; v <= num_vertices; ++v) {
        std::cout << v << ": ";
        std::list<Vertex> adj = g.get_adj(v);
        print_list(adj);
        cout << "\n";
    }
}

int main() {
    uint num_vertices = 5;
    Graph g(num_vertices);
    input_graph(g);
    display_graph(g);
    return 0;
}