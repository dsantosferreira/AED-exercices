#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//-----------------------------------------------------------------

// TODO
Kid Game::loseGame(string phrase) {
    list<Kid> aux = this->kids;
    auto itr = aux.begin();
    int words = numberOfWords(phrase);
    while (aux.size() > 1) {
        for (int i = 1; i < words; i++) {
            itr++;
            if (itr == aux.end())
                itr = aux.begin();
        }
        itr = aux.erase(itr);
        if (itr == aux.end())
            itr = aux.begin();
    }
	return *aux.begin();
}


// TODO
list<Kid> Game::rearrange() {
    list<Kid> res;
    list<Kid> aux;
    list<Kid> girls;
    list<Kid> boys;
    bool cond = true;
    int nGirls, nBoys;
    for (Kid kid : kids) {
        if (kid.getSex() == 'f')
            girls.push_back(kid);
        else
            boys.push_back(kid);
    }
    if (girls.size() < boys.size()) {
        nGirls = 1;
        nBoys = boys.size() / girls.size();
    }
    else {
        nGirls = girls.size() / boys.size();
        nBoys = 1;
    }

    while (true) {
        for (int i = 0; i < nGirls; i++) {
            if (!girls.empty()) {
                aux.push_back(*(girls.begin()));
                girls.erase(girls.begin());
            }
            else {
                cond = false;
                break;
            }
        }
        if (cond) {
            for (int j = 0; j < nBoys; j++) {
                if (!boys.empty()) {
                    aux.push_back(*(boys.begin()));
                    boys.erase(boys.begin());
                }
                else {
                    cond = false;
                    break;
                }
            }
        }

        if (!cond)
            break;
    }
    while (!girls.empty()) {
        res.push_back(*(girls.begin()));
        girls.erase(girls.begin());
    }

    while (!boys.empty()) {
        res.push_back(*(boys.begin()));
        boys.erase(boys.begin());
    }
    setKids(aux);

    return res;
}


// TODO
list<Kid> Game::shuffle() const {
	list<Kid> newList;
	return newList;
}
