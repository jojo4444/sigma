#ifndef DICT_HEADER
#define DICT_HEADER

#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

#include "trie.hpp"

using std::vector;
using std::pair;

const int LIMIT_HINTS = 44;
const int MIN_LEN_WORD = 5;

/*
инварианты:
1. add >= 0
2. del >= 0
*/
struct wordStat {
	int add, del;

	wordStat();
	wordStat(int Add, int Del);

	bool operator> (const wordStat& T) const;
};

class Dict {
public:
	Dict();

	char getLet() const;
	bool find(const string& word) const;
	void del(const string& word);

	wordStat getWordStat(const string& word) const;
	vector<pair<string, wordStat> > getHints(const vector<char>& let) const;

private:
	mutable string buffWord_;
	mutable vector<char> buffLet_;
	mutable vector<string> buffHints_;
	void generateSubwords() const;

    mutable std::mt19937 gen_;
    mutable std::discrete_distribution<int> dist_;    
    Trie t_;
};

template <typename T>
void makeunique(vector<T>& v) {
	std::sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

#endif