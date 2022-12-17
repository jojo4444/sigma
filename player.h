#ifndef PLAYER_H
#define PLAYER_H

#include "dict.hpp"
#include <vector>
#include <tuple>
#include <map>

using std::vector;
using std::tuple;
using std::string;


class Player {
public:
	Player(Dict* dict_);
	~Player();

	int getHp() const;
	vector<char> getLet() const;
	void addLetter(char);
	tuple<bool, int, int> go(const string&);
	void updHp(int dh);
	vector<string> getHints() const;

private:
	const Dict* dict;
	int hp;
	vector<char> let;
	void erraseLetters(const string&);
	bool checkWordLetters(const string&) const;
};
#endif
