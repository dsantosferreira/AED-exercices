#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);
    vector<int> getNumbers() const;
    string getPlayer() const;
};

//---------------------------------

struct betHash
{
    // TODO
	int operator() (const Bet& b) const {
        int v = 0;
        for (int number : b.getNumbers()) {
            v = 37*v + number;
        }
        return v;
	}

    // TODO
	bool operator() (const Bet& b1, const Bet& b2) const {
        if (b1.getPlayer() == b2.getPlayer() && b1.getNumbers() == b2.getNumbers())
            return true;
        return false;
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot
{
	tabHBet bets;
public:
	Jackpot();
	void addBet(const Bet& ap);
	unsigned betsInNumber(unsigned num) const;
	vector<string> drawnBets(vector<int> draw) const;
    unsigned getNumBets() const;
};

#endif 
