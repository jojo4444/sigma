#ifndef TRIE_HEADER
#define TRIE_HEADER

#include <string>
#include <string.h>
#include <vector>

using std::string;

const int NODES_MAX = 4000000;

struct Node {
	int to[26];
	int cnt;
	bool term;

	Node();
};

/*
инварианты:
1. lower case [a..z]
2. повторы не добавляются
3. удаляется всегда существующее слово
*/
class Trie {
public:
	Trie();

	bool find(const string& word) const;
	void add(const string& word);
	void del(const string& word);

private:
	int it;
	std::vector<Node> nodes;
};

#endif