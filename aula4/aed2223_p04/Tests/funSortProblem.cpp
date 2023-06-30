#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

bool compareProd(const Product p1, const Product p2) {
    if (p1.getPrice() < p2.getPrice())
        return true;
    else if (p1.getPrice() == p2.getPrice() && p1.getWeight() < p2.getWeight())
        return true;
    return false;
}

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end(), compareProd);
    for (auto itr = products.begin() + k; itr < products.end();) {
        itr = products.erase(itr);
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    int len = values.size();
    if (nc > len)
        return -1;
    int ans = INT_MAX, thisSub;
    vector<unsigned> aux = values;
    sort(aux.begin(), aux.end());

    for (int i = 0; i < len - nc + 1; i++) {
        thisSub = aux[i + nc - 1] - aux[i];
        if (thisSub < ans)
            ans = thisSub;
    }
    return ans;
}


// TODO
bool sortDeparture(pair<float, float> d1, pair<float, float> d2) {
    if (d1.second < d2.second)
        return true;
    return false;
}

unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    unsigned ans = 1, currTrains = 1, arrivalPtr = 1, departurePtr = 0;
    vector<float> departureAux = departure;
    vector<float> arrivalAux = arrival;
    sort(arrivalAux.begin(), arrivalAux.end());
    sort(departureAux.begin(), departureAux.end());
    while (arrivalPtr <= arrival.size() - 1) {
        if (arrivalAux[arrivalPtr] <= departureAux[departurePtr]) {
            currTrains++;
            arrivalPtr++;
        }
        else {
            currTrains--;
            departurePtr++;
        }
        if (currTrains > ans)
            ans = currTrains;
    }
    if (currTrains > ans)
        ans = currTrains;
    return ans;
}

//TODO
void Merge(vector<int> &v, vector<int> &aux, unsigned &ans, int leftFirst, int leftSecond, int right) {
    int auxIdx = leftFirst;
    int auxLeftFirst = leftFirst;
    int auxLeftSecond = leftSecond;

    while(auxLeftFirst < leftSecond && auxLeftSecond <= right) {
        if (v[auxLeftFirst] <= v[auxLeftSecond]) {
            aux[auxIdx++] = v[auxLeftFirst++];
        }
        else {
            aux[auxIdx++] = v[auxLeftSecond++];
            ans += leftSecond - auxLeftFirst;
        }
    }

    while (auxLeftFirst < leftSecond) {
        aux[auxIdx++] = v[auxLeftFirst++];
    }

    while (auxLeftSecond <= right) {
        aux[auxIdx++] = v[auxLeftSecond++];
    }

    for (int i = leftFirst; i <= right; i++) {
        v[i] = aux[i];
    }
}

void MergeSort(vector<int> &v, vector<int> &aux, unsigned &ans, int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        MergeSort(v, aux, ans, left, mid);
        MergeSort(v, aux, ans, mid+1, right);
        Merge(v, aux, ans, left, mid + 1, right);
    }
}

unsigned FunSortProblem::numInversions(vector <int> v) {
    unsigned ans = 0;
    vector<int> aux(v.size());
    MergeSort(v, aux, ans, 0, v.size() - 1);
    return ans;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

