#include "trie.hpp"

Node::Node() {
	memset(to, -1, sizeof to);
	cnt = 0;
	term = false;
}

Trie::Trie() {
	it = 1;
	nodes.resize(NODES_MAX);
}

bool Trie::find(const string& word) const {
	int u = 0;
	for (char c : word) {
		if (nodes[u].cnt == 0) {
			return false;
		}
		int to = nodes[u].to[c - 'a'];
		if (to == -1) {
			return false;
		}
		u = to;
	}
	return nodes[u].term;
}

void Trie::add(const string& word) {
	int u = 0;
	for (char c : word) {
		nodes[u].cnt++;
		int& to = nodes[u].to[c - 'a'];
		if (to == -1) {
			to = it++;
		}
		u = to;
	}
	nodes[u].cnt++;
	nodes[u].term = true;
}

void Trie::del(const string& word) {
	int u = 0;
	for (char c : word) {
		nodes[u].cnt--;
		u = nodes[u].to[c - 'a'];
	}
	nodes[u].cnt--;
	nodes[u].term = false;
}
