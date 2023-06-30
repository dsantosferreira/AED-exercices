#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//-----------------------------------------------------------------

// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> alreadySeen;
    for (int value : values) {
        auto aTry = alreadySeen.find(sum - value);
        if (aTry != alreadySeen.end()) {
            return make_pair(*aTry, value);
        }
        alreadySeen.insert(value);
    }
    return make_pair(0,0);
}
