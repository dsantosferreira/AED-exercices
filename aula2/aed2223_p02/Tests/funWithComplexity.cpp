// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> & v) {
    unsigned n = v.size();
    int maxSoFar = v[0]; // porque é esta uma boa escolha para a melhor soma inicial?
    int curr_best = maxSoFar;
    for (unsigned i = 1; i < n; i++) {
        if(curr_best >= 0) {
            curr_best += v[i];
        }
        else {
            curr_best = v[i];
        }
        if (curr_best > maxSoFar) maxSoFar = curr_best;
    }
    return maxSoFar;
}


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    unsigned n = v.size();
    unsigned answer = 0;
    float toBeSatisfactory = k/2.0;
    unsigned currSatisfactory = 0;
    for (unsigned i = 0; i < k; i++) {
        if (v[i] >= t) currSatisfactory++;
    }
    if (currSatisfactory > toBeSatisfactory) answer++;
    for (unsigned j = 1; j <= n-k; j++) {
        if (v[j-1] >= t) currSatisfactory--;
        if (v[j+k-1] >= t) currSatisfactory++;
        if (currSatisfactory >= toBeSatisfactory) answer++;
    }
    return answer;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
#include <math.h>

pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    int i = 1;
    while (n > i*i) {
        i += 2;
    }
    ans = {(i-1)/2, (i-1)/2};
    int top_right = i*i;
    while (ans.first > -(i-1)/2 && top_right != n) {
        ans.first--;
        top_right--;
    }
    while (ans.second > -(i-1)/2 && top_right != n) {
        ans.second--;
        top_right--;
    }
    while (ans.first < (i-1)/2 && top_right != n) {
        ans.first++;
        top_right--;
    }
    while (ans.second < (i-1)/2 && top_right != n) {
        ans.second++;
        top_right--;
    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
void findCoord(pair<long long, long long> &p, int n) {
    int aux = 1;
    int step = 2;
    while (aux < n) {
        aux += step;
        step++;
        p.first++;
    }
    while (aux != n) {
        p.first--;
        p.second++;
        aux--;
    }
}


long long FunWithComplexity::gridSum(int a, int b) {
    long long ans = 0;
    long long curr = a;
    long long n;
    pair<long long, long long> p1 = {0, 0}, p2 = {0, 0};
    findCoord(p1, a);
    findCoord(p2, b);
    long long step = p1.first + p1.second + 1;
    long long higherBound = p1.second;

    while (p1.second != p2.second) {
        if (p2.first - p1.first + 1 < p1.second - higherBound + 1) {
            n = p2.first - p1.first + 1;
            ans += (2*curr + n - 1) * n/2;
        }
        else {
            n = p1.second - higherBound + 1;
            ans += (2*curr + n - 1) * n/2;
        }
        curr += step;
        step++;
        p1.second++;
    }

    step++;

    while (p1.first != p2.first) {
        if (p2.first - p1.first + 1 < p1.second - higherBound + 1) {
            n = p2.first - p1.first + 1;
            ans += (2*curr + n - 1) * n/2;
        }
        else {
            n = p1.second - higherBound + 1;
            ans += (2*curr + n - 1) * n/2;
        }
        curr += step;
        step++;
        p1.first++;
    }
    ans += b;

    return ans;
}