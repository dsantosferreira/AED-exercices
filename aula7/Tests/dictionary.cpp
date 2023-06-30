#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}

// ---------------------------------------------

//TODO
bool WordMean::operator<(const WordMean& wm2) const {
    return word < wm2.word;
}


//TODO
void Dictionary::readFile(ifstream &f) {
    string aWord, aMeaning, dummy;
    while (getline(f, aWord, '\r')) {
        getline(f, dummy, '\n');
        getline(f, aMeaning, '\r');
        getline(f, dummy, '\n');
        words.insert(WordMean(aWord, aMeaning));
    }
}

//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    auto start = words.begin();
    auto end = words.end();
    for (auto itr = start; itr != end; itr++) {
        if (itr->getWord() == w1) {
            return itr->getMeaning();
        }
        else if(w1 < itr->getWord()) {
            next = *itr;
            if (itr != start) {
                itr--;
                previous = *itr;
            }
            return "word not found";
        }
    }
    if (!words.empty()) {
        end--;
        previous = *end;
    }
    return "word not found";
}

//TODO
bool Dictionary::update(string w1, string m1) {
    WordMean toAdd(w1, m1);
    if (words.find(toAdd) == words.end()) {
        words.insert(toAdd);
        return false;
    }
    else {
        words.erase(toAdd);
        words.insert(toAdd);
        return true;
    }
}

//TODO
void Dictionary::print() const {
    for (auto itr = words.begin(); itr != words.end(); itr++) {
        cout << itr->getWord() << endl << itr->getMeaning() << endl;
    }
}
