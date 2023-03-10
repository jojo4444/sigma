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

const int LIMIT_HINTS = 19;
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

	bool correct() const;

	bool operator> (const wordStat& T) const;
	bool operator!= (const wordStat& T) const;
};

const wordStat BAD_STATE = (wordStat){-1, -1};

using vectorHints = vector<pair<string, wordStat> >;

class Dict {
public:
	Dict();

	// word --> [a..z]
	bool correct(const string& word) const;

	char getLet() const;
	bool find(const string& word) const;
	void del(const string& word);

	wordStat getWordStat(const string& word) const;
	pair<vectorHints, vectorHints> getHints(const vector<char>& let) const;

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