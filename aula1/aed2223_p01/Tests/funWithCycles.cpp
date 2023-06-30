// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"
#include <set>

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for (unsigned i = 0; i < length/2; i++) {
        if (s[i] != s[length-i-1])
            return false;
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string aux;
    for (const char c : s) {
        if (isalpha(c)) {
            aux += tolower(c);
        }
    }
    return palindrome(aux);
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    int aux_sum;
    while (true) {
        aux_sum = digitSum(++n);
        if (aux_sum == sum)
            return n;
    }
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    int max = 0;
    int aux = 0;
    size_t len = v.size();
    for (size_t i = 0; i < len; i++) {
        if (v[i] < v[i-1]) {
            aux++;
        }
        else {
            if (max < aux) {
                max = aux;
            }
            aux = 0;
        }
    }
    if (max < aux) {
        max = aux;
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int answer = 0;
    size_t len = v.size();
    for (size_t i = 0; i < len; i++) {
        if (v[i] == n)
            answer++;
    }
    return answer;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    set<int> appeared;
    size_t len = v.size();
    for (size_t i = 0; i < len; i++) {
        int el = v[i];
        if (appeared.find(el) != appeared.end())
            return true;
        else {
            appeared.insert(el);
        }
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    set<int> appeared;
    size_t len = v.size();
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        int el = *itr;
        if (appeared.find(el) != appeared.end()) {
            itr = v.erase(itr);
            itr--;
        }
        else {
            appeared.insert(el);
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    size_t i = 0;
    size_t j = 0;
    size_t len1 = v1.size();
    size_t len2 = v2.size();
    int el1, el2;

    while(i < len1 && j < len2) {
        el1 = v1[i];
        el2 = v2[j];
        if(el1 < el2) {
            ans.push_back(el1);
            i++;
        }
        else {
            ans.push_back(el2);
            j++;
        }
    }

    while(i < len1) {
        ans.push_back(v1[i]);
        i++;
    }

    while(j < len2) {
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            while (n % i == 0) {
                n /= i;
                ans.push_back(i);
            }
        }
        if (n == 1)
            break;
    }
    if (ans.empty())
        ans.push_back(n);
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    vector<bool> aux;
    for (size_t i = 2; i <= n; i++) {
        aux.push_back(true);
    }
    for (size_t i = 2; i <= sqrt(n); i++) {
        if (aux[i-2] == true) {
            for (size_t j = i*i; j <= n; j+=i) {
                aux[j-2] = false;
            }
        }
    }
    for (size_t i = 2; i <= n; i++) {
        if (aux[i-2] == true)
            ans.push_back(i);
    }
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO

int digitSum2(long long n) {
    int the_sum = 0;
    while (n != 0) {
        the_sum += n % 10;
        n /= 10;
    }
    return the_sum;
}

long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    long long start = digitSum2(n); // Soma dos digitos inicias de n
    long long diff = sum - start;   // Diferença entre a soma pretendida e a soma de n inicial
    long long power = 1;            // Serve como um "apontador" para o dígito de n a que queremos somar/subrair
    long long aux = n;              // Serve para percorrer n sem o perder
    int a_digit;
    /* Caso a soma dos dígitos de n seja superior:
     * 1 - Começando no algarismo das unidades, metemos cada algarismo a 0, até que a soma dos algarismos
     * do nº auxiliar seja inferior ao valor de sum;
     * 2 - Soma-se 1 ao dígito a que power está a "apontar", para garantir que a solução obtida é superior
     * ao nº inicial;
     * 3 - Após isso somamos o que for necessário ao algarismo das unidades para que start == sum;
     *
     * Exemplo: Seja n = 38487 e sum = 6
     * 1ºPasso:
     * start = 30; n = 38487; sum = 6
     *
     * n:       38480       38400       38000       30000
     * start:    23          15          11           3 (3 < 6)
     *
     * 2ºPasso:
     * 30000 => 40000; start = 3 => start = 4;
     *
     * 3ºPasso:
     * Como start = 4 && sum = 6 teremos de somar 2 (6-4) ao algarismo das unidades
     * 40000 => 40002
     */
    if (diff <= 0) {
        while (start >= sum) {
            a_digit = aux % 10;
            start -= a_digit;
            aux /= 10;
            n -= power * a_digit;
            power *= 10;
        }
        n += power;
        start++;
        n += (sum - start);
    }

    start = digitSum2(n);
    diff = sum - start;
    power = 1;
    aux = n;

    // Caso diff > 0 basta somar o necessário ao nº base até obter um n tal que a soma dos seus dígitos sejam iguais a sum
    if (diff > 0) {
        while (diff != 0) {
            if (diff < 10 && 9 - aux % 10 > diff) {
                n += power * diff;
                diff = 0;
            } else {
                diff = diff - (9 - aux % 10);
                n += (9 - aux % 10) * power;
            }
            aux /= 10;
            power *= 10;
        }
    }
    return n;
}
