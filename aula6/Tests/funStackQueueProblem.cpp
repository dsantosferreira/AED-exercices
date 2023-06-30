#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

// TODO
vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    queue<string> nextBinaries;
    nextBinaries.push("1");
    vector<string> res;
    string aBinary;
    while(res.size() != n) {
        aBinary = nextBinaries.front();
        nextBinaries.push(aBinary + "0");
        nextBinaries.push(aBinary + "1");
        nextBinaries.pop();
        res.push_back(aBinary);
    }
    return res;
}


//TODO
vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    stack<int> s;
    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[s.top()] <= prices[i])
            s.pop();
        res.push_back(s.empty() ? i+1 : i-s.top());
        s.push(i);
    }
    return res;
}


//TODO
int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}






