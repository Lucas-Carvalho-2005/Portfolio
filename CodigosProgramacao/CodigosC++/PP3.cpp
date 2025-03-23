#include <iostream>
#include <list>
#include <limits>

typedef unsigned int uint;
typedef uint Vertex;
typedef double Weight;

class VertexWeightPair {
public:
    Vertex vertex;
    Weight weight;

    VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {}
};

class Edge {
public:
    Vertex source, destination;
    Weight weight;

    Edge(Vertex s, Vertex d, Weight w) : source(s), destination(d), weight(w) {}
};

class WeightedGraphAL {
private:
    int num_vertices;
    std::list<VertexWeightPair>* adj;

public:
    WeightedGraphAL(int num_vertices);
    ~WeightedGraphAL();
    void add_edge(Vertex u, Vertex v, Weight weight);
    std::list<VertexWeightPair> get_adj(Vertex v) const { return adj[v]; }
    uint get_num_vertices() { return num_vertices; }
    int* dijkstra(Vertex source);
};

WeightedGraphAL::WeightedGraphAL(int num_vertices) : num_vertices(num_vertices) {
    adj = new std::list<VertexWeightPair>[num_vertices];
}

WeightedGraphAL::~WeightedGraphAL() {
    delete[] adj;
}

void WeightedGraphAL::add_edge(Vertex u, Vertex v, Weight weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
}

// Min-Heap based Priority Queue without <vector>
class MinHeap {
private:
    std::pair<int, Weight>* heap;
    int* pos;
    int heap_size;

    void min_heapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    MinHeap(int n);
    ~MinHeap();
    bool empty() const { return heap_size == 0; }
    bool contains(int v) const { return pos[v] != -1; }
    void insert(int v, Weight weight);
    std::pair<int, Weight> extract_min();
    void decrease_key(int v, Weight weight);
};

MinHeap::MinHeap(int n) {
    heap = new std::pair<int, Weight>[n];
    pos = new int[n];
    heap_size = 0;
    for (int i = 0; i < n; ++i) pos[i] = -1;
}

MinHeap::~MinHeap() {
    delete[] heap;
    delete[] pos;
}

void MinHeap::min_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && heap[l].second < heap[smallest].second)
        smallest = l;
    if (r < heap_size && heap[r].second < heap[smallest].second)
        smallest = r;

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        pos[heap[i].first] = i;
        pos[heap[smallest].first] = smallest;
        min_heapify(smallest);
    }
}

void MinHeap::insert(int v, Weight weight) {
    heap[heap_size] = {v, weight};
    int i = heap_size;
    pos[v] = i;
    heap_size++;

    while (i > 0 && heap[parent(i)].second > heap[i].second) {
        std::swap(heap[i], heap[parent(i)]);
        pos[heap[i].first] = i;
        pos[heap[parent(i)].first] = parent(i);
        i = parent(i);
    }
}

std::pair<int, Weight> MinHeap::extract_min() {
    if (heap_size == 0)
        return {-1, -1};

    auto min = heap[0];
    pos[min.first] = -1;
    heap[0] = heap[--heap_size];

    if (heap_size > 0) {
        pos[heap[0].first] = 0;
        min_heapify(0);
    }

    return min;
}

void MinHeap::decrease_key(int v, Weight weight) {
    int i = pos[v];
    heap[i].second = weight;

    while (i > 0 && heap[parent(i)].second > heap[i].second) {
        std::swap(heap[i], heap[parent(i)]);
        pos[heap[i].first] = i;
        pos[heap[parent(i)].first] = parent(i);
        i = parent(i);
    }
}

int* WeightedGraphAL::dijkstra(Vertex source) {
    Weight* dist = new Weight[num_vertices];
    int* previous = new int[num_vertices];
    MinHeap minHeap(num_vertices);

    for (int i = 0; i < num_vertices; ++i) {
        dist[i] = std::numeric_limits<Weight>::infinity();
        previous[i] = -1;
    }

    dist[source] = 0;
    minHeap.insert(source, 0);

    while (!minHeap.empty()) {
        int u = minHeap.extract_min().first;

        for (auto& neighbor : get_adj(u)) {
            Vertex v = neighbor.vertex;
            Weight weight = neighbor.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                previous[v] = u;
                if (!minHeap.contains(v))
                    minHeap.insert(v, dist[v]);
                else
                    minHeap.decrease_key(v, dist[v]);
            }
        }
    }

    delete[] dist;
    return previous;
}

class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int n);
    ~UnionFind();
    int find(int u);
    void unite(int u, int v);
};

UnionFind::UnionFind(int n) : size(n) {
    parent = new int[n];
    rank = new int[n]();
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

int UnionFind::find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);  // Path compression
    }
    return parent[u];
}

void UnionFind::unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

class Kruskal {
public:
    Weight calculate_mst(int V, const std::list<Edge>& edges);
};

Weight Kruskal::calculate_mst(int V, const std::list<Edge>& edges) {
    UnionFind uf(V);

    std::list<Edge> sorted_edges(edges);
    sorted_edges.sort([](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    Weight mst_weight = 0.0;
    for (const auto& edge : sorted_edges) {
        Vertex u = edge.source;
        Vertex v = edge.destination;
        if (uf.find(u) != uf.find(v)) {
            mst_weight += edge.weight;
            uf.unite(u, v);
        }
    }
    return mst_weight;
}

int main() {
    int num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    WeightedGraphAL brain_graph(num_vertices);

    for (int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        Weight weight;
        std::cin >> u >> v >> weight;
        brain_graph.add_edge(u - 1, v - 1, weight);
    }

    int entry_block, exit_block;
    std::cin >> entry_block >> exit_block;
    entry_block--; exit_block--;

    int* previous = brain_graph.dijkstra(entry_block);

    std::list<int> path;
    for (int v = exit_block; v != -1; v = previous[v]) {
        path.push_front(v);
    }
    delete[] previous;

    Weight total_mst_weight = 0.0;
    Kruskal kruskal;

    for (int i = 0; i < num_vertices; ++i) {
        int block_order, block_size, num_sick_neurons;
        std::cin >> block_order >> block_size >> num_sick_neurons;

        std::list<Vertex> sick_neurons;
        for (int j = 0; j < num_sick_neurons; j++) {
            Vertex neuron;
            std::cin >> neuron;
            sick_neurons.push_back(neuron);
        }

        std::list<Edge> block_edges;
        for (int j = 0; j < block_size; ++j) {
            Vertex u, v;
            Weight weight;
            std::cin >> u >> v >> weight;
            block_edges.emplace_back(u - 1, v - 1, weight);
        }

        bool block_in_path = false;
        for (int block : path) {
            if (block == i) {
                block_in_path = true;
                break;
            }
        }

        if (block_in_path && !sick_neurons.empty()) {
            total_mst_weight += kruskal.calculate_mst(block_order, block_edges);
        }
    }

    std::cout << total_mst_weight << std::endl;

    return 0;
}