// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------
// TODO
int FunWithSearch::search(const vector<int> & v, int key) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // found key
    }
    return -1; // not found
}

// ----------------------------------------------------------
// Exercicio 2: Limite Inferior
// ----------------------------------------------------------
// TODO
int FunWithSearch::lowerBound(const vector<int> &v, int key) {
    int low = 0, high = (int)v.size() - 1;
    int middle;
    while (low != high) {
        middle = low + (high - low)/2;
        if (v[middle] >= key) {
            high = middle;
        }
        else {
            low = middle + 1;
        }
    }
    if (v[low] >= key)
        return low;
    else
        return -1;
}

// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
// TODO
int FunWithSearch::countRange(const vector<int> & v, int a, int b) {
    int low = lowerBound(v, a);
    int high = (int)v.size() - 1;
    int middle;
    int count = 0;
    if (low == -1) return 0;
    while (low <= high) {
        middle = low + (high - low)/2;
        if (v[middle] <= b) {
            count += middle - low + 1;
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
// TODO
bool FunWithSearch::isPossible(const vector<int> & v, int x, int k) {
    int curr = 0;
    int parts = 1;
    unsigned len = v.size();
    for (unsigned i = 0; i < len; i++) {
        if (v[i] > x)
            return false;

        if (curr + v[i] > x) {
            curr = v[i];
            parts++;
        }
        else {
            curr += v[i];
        }

        if (parts > k)
            return false;
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------
// TODO
int FunWithSearch::partitions(const vector<int> & v, int k) {
    unsigned len = v.size();
    int low = 1;
    int high = 0;
    int middle;
    for (unsigned i = 0; i < len; i++) {
        high += v[i];
    }
    while (low != high) {
        middle = low + (high - low)/2;
        if (isPossible(v, middle, k)) {
            high = middle;
        }
        else {
            low = middle + 1;
        }
    }
    return low;
}

// ----------------------------------------------------------
// Exercicio 5: Somas mais próximas
// ----------------------------------------------------------
// TODO
vector<int> FunWithSearch::closestSums(const vector<int> & v, const vector<int> & p) {
    vector<int> ans;
    vector<int> sums;
    int high, low, mid, lenV = v.size(), lenP = p.size(), diff1, diff2;
    for (int i = 0; i < lenV - 1; i++) {
        for (int j = i+1; j < lenV; j++) {
            sums.push_back(v[i] + v[j]);
        }
    }
    sort(sums.begin(), sums.end());
    for (int i = 0; i < lenP; i++) {
        low = 0; high = sums.size() - 1;
        while (low != high) {
            mid = low + (high-low)/2;
            if (p[i] > sums[mid]) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        if (low == 0)
            ans.push_back(sums[low]);
        else if (p[i] - sums[low - 1] <= sums[low] - p[i])
            ans.push_back(sums[low-1]);
        else
            ans.push_back(sums[low]);
    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Jogo de strings
// ----------------------------------------------------------
// TODO

bool removeK(const string & a, const string & b, int k, const vector<int> &p) {
    int lenB = b.size(), lenP = p.size(), idxA, idxB = 0;
    vector<int> aux = p;
    sort(aux.begin() + k, aux.end());
    for (int i = k; i < lenP; i++) {
        idxA = aux[i] - 1;
        if (a[idxA] == b[idxB])
            idxB++;
        if (idxB == lenB)
            return true;
    }
    return false;

}

int FunWithSearch::stringGame(const string & a, const string & b, const vector<int> & p) {
    int low, high, mid;
    low = 0; high = p.size();
    while (low != high) {
        mid = low + (high-low)/2;
        if (removeK(a, b, mid, p)) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if (removeK(a, b, low, p))
        return low;
    else
        return low - 1;
}

// ----------------------------------------------------------
// Exercicio 7: Regras Quadriculadas
// ----------------------------------------------------------
// TODO
long long FunWithSearch::rules(int k, long long a, long long b) {
    return 0;
}