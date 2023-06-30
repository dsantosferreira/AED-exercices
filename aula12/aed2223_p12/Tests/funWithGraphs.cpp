// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#include "funWithGraphs.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(12, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,8);
    g.addEdge(2,8);
    g.addEdge(3,8);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(10,11);
    g.addEdge(11,12);
    g.addEdge(11,5);
    g.addEdge(11,6);
    g.addEdge(12,5);
    g.addEdge(12,6);
    g.addEdge(5,6);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(10, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,6);
    g.addEdge(5,10);
    g.addEdge(2,6);
    g.addEdge(4,10);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(9,10);
    return g;
}

// ----------------------------------------------------------
// Exercicio 2: Um labirinto 2D
// ----------------------------------------------------------
// TODO
struct point {
    int x;
    int y;
    int distance;
};

int mazeBfs(point player, string m[]) {
    int xs[4] = {-1, 0, 0, 1};
    int ys[4] = {0, -1, 1, 0};

    queue<point> q;
    q.push(player);

    while (!q.empty()) {
        point curr = q.front();

        for (int i = 0; i < 4; i++) {
            point nextPoint = {curr.x + xs[i], curr.y + ys[i], curr.distance + 1};

            if (m[nextPoint.x][nextPoint.y] == '.') {
                m[curr.x][curr.y] = '#';
                q.push(nextPoint);
            }
            else if (m[nextPoint.x][nextPoint.y] == 'T')
                return nextPoint.distance;
        }
        q.pop();
    }
}

int FunWithGraphs::maze(int rows, int cols, string m[]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (m[row][col] == 'P') {
                return mazeBfs({row, col, 0}, m);
            }
        }
    }
    return 0;
}

// ----------------------------------------------------------
// Exercicio 3: Nuvem de Cinzas
// ----------------------------------------------------------
// TODO
bool checkValidPoint(point p, int rows, int cols) {
    return p.x >= 0 && p.x < rows && p.y >= 0&& p.y < cols;
}

pair<int, int> FunWithGraphs::volcano(int rows, int cols, string m[]) {
    int min = 0, max = 0;
    bool reachedFirst = false;
    int xs[4] = {-1, 0, 0, 1};
    int ys[4] = {0, -1, 1, 0};
    queue<point> q;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (m[row][col] == '#')
                q.push({row, col, 0});
        }
    }

    while (!q.empty()) {
        point curr = q.front();

        if (m[curr.x][curr.y] == 'A') {
            if (!reachedFirst) {
                reachedFirst = true;
                min = curr.distance;
            }
            max = curr.distance;
        }

        for (int i = 0; i < 4; i++) {
            point nextPoint = {curr.x + xs[i], curr.y + ys[i], curr.distance + 1};

            if (checkValidPoint(nextPoint, rows, cols) && m[nextPoint.x][nextPoint.y] == '.' || checkValidPoint(nextPoint, rows, cols) && m[nextPoint.x][nextPoint.y] == 'A') {
                m[curr.x][curr.y] = '#';
                q.push(nextPoint);
            }
        }
        q.pop();
    }
    return {min, max};
}

// ----------------------------------------------------------
// Exercicio 4: Quadrados Mágicos
// ----------------------------------------------------------
// TODO
pair<int, string> FunWithGraphs::game(const vector<int> & target) {
    return {0, ""};
}
