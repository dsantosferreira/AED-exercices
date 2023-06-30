#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() {}


//-----------------------------------------------------------------

// TODO
list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    auto itrEnd = values.end();
    for (auto itr = values.begin(); itr != itrEnd; itr++) {
        int el = *itr;
        if (el > x) {
            l1.push_back(el);
            itr = values.erase(itr);
            itr--;
        }
    }
    return l1;
}



//TODO
list<pair<int,int>> FunListProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;

    if (values.size() == 0)
        return res;

    auto itrEnd = values.end();
    pair<int, int> el, elRes;

    values.sort();
    res.push_back(*values.begin());
    auto itrRes = res.begin();

    for (auto itr = values.begin(); itr != itrEnd; itr++) {
        el = *itr;
        elRes = *itrRes ;
        if (el.first <= elRes.second) {
            if (el.second > elRes.second) {
                itrRes->second = el.second;
            }
        }
        else {
            res.push_back(el);
            itrRes++;
        }
    }
    return res;
}
