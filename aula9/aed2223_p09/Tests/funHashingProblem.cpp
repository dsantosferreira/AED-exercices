#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> seenValues;

    if (k >= values.size()) {
        for (int value : values) {
            if (seenValues.find(value) != seenValues.end())
                res.push_back(value);
            else
                seenValues.insert(value);
        }
    }
    else {
        for (int i = 0; i <= values.size() - k + 1; i++) {
            seenValues.clear();
            for (int j = i; j <= k+i; j++) {
                if (seenValues.find(values[j]) != seenValues.end())
                    res.push_back(values[j]);
                else
                    seenValues.insert(values[j]);
            }
        }
    }
    return res;
}