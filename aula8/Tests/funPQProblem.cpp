#include <functional>
#include "funPQProblem.h"

FunPQProblem::FunPQProblem() {}


//-----------------------------------------------------------------

bool minHeap(int &m, int &n) {
    return m > n;
}

// TODO
int FunPQProblem::minCost(const vector<int> &ropes) {
    priority_queue<int, vector<int>, std::function<bool(int&, int&)>> pq(minHeap);
    return 0;
}

