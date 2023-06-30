// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

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
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(6,9);
    g.addEdge(6,7);
    g.addEdge(8,7);
    g.addEdge(8,9);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(12, false);
    g.addEdge(8,1);
    g.addEdge(8,2);
    g.addEdge(8,3);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(5,11);
    g.addEdge(5,12);
    g.addEdge(6,11);
    g.addEdge(6,12);
    g.addEdge(12,11);
    g.addEdge(11,10);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(9, true);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(9,6);
    g.addEdge(7,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(4, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(3, true);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(9, false);
    g.addEdge(1,2, 5);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 8);
    g.addEdge(3,4, 7);
    g.addEdge(4,5, 3);
    g.addEdge(5,6, 5);
    g.addEdge(5,7, 9);
    g.addEdge(6,9, 1);
    g.addEdge(7,8, 2);
    g.addEdge(8,9, 42);
    return g;
}

Graph FunWithGraphs::graph9() {
    Graph g(4, false);
    g.addEdge(1,2, 3);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 3);
    g.addEdge(3,4, 4);
    return g;
}

Graph FunWithGraphs::graph10() {
    Graph g(8, true);
    g.addEdge(1,3, 3);
    g.addEdge(2,1, 2);
    g.addEdge(4,2, 1);
    g.addEdge(5,4, 1);
    g.addEdge(5,6, 2);
    g.addEdge(6,8, 1);
    g.addEdge(6,7, 2);
    g.addEdge(8,7, 3);
    return g;
}

Graph FunWithGraphs::graph11() {
    Graph g(3, true);
    g.addEdge(2,1, 2);
    g.addEdge(1,3, 8);
    g.addEdge(3,2, 1);
    return g;
}

// ----------------------------------------------------------
// Exercicio 5: Contagem de Celulas
// ----------------------------------------------------------
// TODO

const pair<int, int> neighbors[] = {
        make_pair(-1, 0),
        make_pair(-1, -1),
        make_pair(0, -1),
        make_pair(1, -1),
        make_pair(1, 0),
        make_pair(1, 1),
        make_pair(0, 1),
        make_pair(-1, 1)
};

bool inTheGrid(int row, int col, int rows, int cols) {
    if (row >= rows || row <= -1 || col <= -1 || col >= cols)
        return false;
    return true;
}

int microbesDfs(int row, int col, int rows, int cols, string m[]) {
    int counter = 0;
    m[row][col] = '.';

    for (pair<int, int> neighbor: neighbors) {
        pair<int, int> nextPos = make_pair(row + neighbor.first, col + neighbor.second);
        if (inTheGrid(nextPos.first, nextPos.second, rows, cols) && m[nextPos.first][nextPos.second] == '#')
            counter += microbesDfs(nextPos.first, nextPos.second, rows, cols, m);
    }

    return counter + 1;
}

int FunWithGraphs::largestMicrobe(int rows, int cols, string m[]) {
    int max = 0;
    int thisDfs;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == '#') {
                thisDfs = microbesDfs(i, j, rows, cols, m);
                if (thisDfs > max)
                    max = thisDfs;
            }
        }
    }

    return max;
}

// ----------------------------------------------------------
// Exercicio 6: Labirinto de Barras
// ----------------------------------------------------------
// TODO
pair<int, int>FunWithGraphs::slashMaze(int rows, int cols, string m[]) {
    pair<int, int> ans = {-1, -1};
    return ans;
}