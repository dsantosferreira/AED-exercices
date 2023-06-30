// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

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

bool Graph::bipartiteDfs(int v, vector<int> &colors) {
    for (Edge edge: nodes[v].adj) {
        int w = edge.dest;

        if (colors[w] == 0) {
            colors[w] = colors[v] == 1 ? 2 : 1;
            if (!bipartiteDfs(w, colors))
                return false;
        }
        else if (colors[w] == colors[v])
            return false;
    }
    return true;
}

int Graph::countSSCDfs(int v, vector<int> &colors, vector<pair<int, int>> &orderAndLow, int &currOrder) {
    int counter = 0;
    colors[v] = 1; // Paint it grey -> visited
    orderAndLow[v].first = currOrder;
    orderAndLow[v].second = currOrder;
    currOrder++;

    for (Edge edge: nodes[v].adj) {
        int w = edge.dest;
        if (colors[w] == 1) {
            orderAndLow[v].second = min(orderAndLow[v].second, orderAndLow[w].first);
        }
        else if (colors[w] == 0) {
            counter += countSSCDfs(w, colors, orderAndLow, currOrder);
            orderAndLow[v].second = min(orderAndLow[v].second, orderAndLow[w].second);
        }
    }

    colors[v] = 2;

    if (orderAndLow[v].first == orderAndLow[v].second)
        return counter + 1;
    else
        return counter;
}

void Graph::sscListDfs(int v, stack<int> &visited, list<list<int>> &ssc, int &idx) {
    nodes[v].visited = true;
    nodes[v].order = nodes[v].low = idx;
    idx++;
    visited.push(v);
    nodes[v].isInStack = true;

    for (Edge edge: nodes[v].adj) {
        int w = edge.dest;

        if (!nodes[w].visited) {
            sscListDfs(w, visited, ssc, idx);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].isInStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].order);
        }
    }

    if (nodes[v].order == nodes[v].low) {
        list<int> aux;
        while (visited.top() != v) {
            nodes[visited.top()].isInStack = false;
            aux.insert(aux.begin(), visited.top());
            visited.pop();
        }
        nodes[visited.top()].isInStack = false;
        aux.insert(aux.begin(), visited.top());
        visited.pop();
        ssc.push_back(aux);
    }
}

void Graph::articulationDfs(int v, int &idx, stack<int> &beingVisited, list<int> &answer) {
    beingVisited.push(v);
    nodes[v].order = nodes[v].low = idx++;
    nodes[v].isInStack = true;

    int count = 0;
    bool isArticulation = false;

    for (Edge edge: nodes[v].adj) {
        int w = edge.dest;

        if (nodes[w].order == 0) {
            count++;
            articulationDfs(w, idx, beingVisited, answer);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
            if (nodes[v].order <= nodes[w].low)
                isArticulation = true;
        }
        else if (nodes[w].isInStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].order);
        }
    }

    nodes[v].isInStack = false;
    beingVisited.pop();

    if ((isArticulation && !beingVisited.empty()) || (beingVisited.empty() && count > 1))
        answer.push_front(v);
}

// ----------------------------------------------------------
// Exercicio 1: DFS e grafos bipartidos
// ----------------------------------------------------------
// TODO
bool Graph::bipartite() {
    vector<int> colors(nodes.size());

    for (int i = 1; i < nodes.size(); i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            if (bipartiteDfs(i, colors))
                return true;
        }
    }

    return false;
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes fortemente conexos.
// ----------------------------------------------------------
// TODO
int Graph::countSCCs() {
    int counter = 0;
    int currOrder = 1;

    vector<int> colors(nodes.size());
    vector<pair<int, int>> orderAndLow(nodes.size());

    for (int i = 1; i < nodes.size(); i++) {
        if (colors[i] == 0) {
            counter += countSSCDfs(i, colors, orderAndLow, currOrder);
        }
    }

    return counter;
}

// ----------------------------------------------------------
// Exercicio 2.b: Listando componentes fortemente conexos
// ----------------------------------------------------------
// TODO
list<list<int>> Graph::listSCCs() {
    stack<int> visited;
    list<list<int>> answer;
    int idx = 1;

    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].visited = false;
        nodes[i].isInStack = false;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            sscListDfs(i, visited, answer, idx);
        }
    }
    return answer;
}

// ----------------------------------------------------------
// Exercicio 3: Pontos de articulação
// ----------------------------------------------------------
// TODO
list<int> Graph::articulationPoints() {
    list<int> answer;
    stack<int> beingVisited;
    for (int i = 1; i <= n; i++) {
        nodes[i].order = 0;
        nodes[i].low = 0;
        nodes[i].isInStack = false;
    }

    int order = 1;

    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i].order == 0)
            articulationDfs(i, order, beingVisited, answer);
    }

    return answer;
}
