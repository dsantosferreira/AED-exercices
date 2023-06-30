// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Depth-First Search: implementation that returns number of nodes of component
int Graph::myDfs1(int v) {
    int counter = 0;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            counter += myDfs1(w);
    }
    return counter + 1;
}

// Depth-First Search: implementation that returns order of nodes visited
void Graph::myDfs2(int v, list<int>& order) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            myDfs2(w, order);
    }
    order.insert(order.begin(), v);
}

// Depth-First Search: implementation to find cycles. 0 -> white; 1 -> grey; 2 -> black
bool Graph::myDfs3(int v, vector<int>& colors) {
    colors[v] = 1;

    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (colors[w] == 0) {
            if (myDfs3(w, colors))
                return true;
        }
        else if (colors[w] == 1)
            return true;
    }

    colors[v] = 2;
    return false;
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if (v < 1 || v >= nodes.size())
        return -1;

    return nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    int counter = 0;

    if (v < 1 || v >= nodes.size())
        return -1;

    for (Edge edge: nodes[v].adj) {
        counter += edge.weight;
    }
    return counter;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int counter = 0;

    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            dfs(i);
            counter++;
        }
    }

    return counter;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int max = 0;

    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            int compCount = myDfs1(i);
            if (max < compCount)
                max = compCount;
        }
    }

    return max;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    list<int> aux;

    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            myDfs2(i, order);
        }
    }

    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    vector<int> colors(nodes.size());
    bool ans;

    for (int i = 1; i < nodes.size(); i++) {
        ans = myDfs3(i, colors);
        if (ans)
            return ans;
    }

    return false;
}
