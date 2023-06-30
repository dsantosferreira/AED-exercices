// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

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

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

int Graph::distanceBfs(int a, int b) {
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }

    queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    nodes[a].distance = 0;

    while (!q.empty()) {
        if (q.front() == b)
            return nodes[b].distance;

        int v = q.front();

        for (Edge edge: nodes[v].adj) {
            int w = edge.dest;

            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[v].distance + 1;
            }
        }

        q.pop();
    }

    return -1;
}

pair<int, bool> Graph::maxDistanceBfs(int v) {
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }

    int distance = 0;
    int nNodes = 0;
    queue<int> q;
    q.push(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;

    while (!q.empty()) {
        v = q.front();

        for (Edge edge: nodes[v].adj) {
            int w = edge.dest;

            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                distance = nodes[w].distance = nodes[v].distance + 1;
            }
        }
        nNodes++;
        q.pop();
    }
    return {distance, nNodes == nodes.size() - 1};
}

// ----------------------------------------------------------
// Exercicio 1a: Distáncia entre dois nós
// ----------------------------------------------------------
// TODO
int Graph::distance(int a, int b) {
    return distanceBfs(a, b);
}

// ----------------------------------------------------------
// Exercicio 1.b: Diâmetro
// ----------------------------------------------------------
// TODO
int Graph::diameter() {
    int max = -1;
    pair<int, bool> curr;

    for (int i = 1; i < nodes.size(); i++) {
        curr = maxDistanceBfs(i);
        if (!curr.second)
            return -1;
        else {
            if (max < curr.first)
                max = curr.first;
        }
    }
    return max;
}
