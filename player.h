#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>

using std::vector;
using std::tuple;
using std::string;


class Player {
public:
	Player(int hp_);
	~Player();

	int getHp() const;
	vector<char> getLet() const;
	void addLetter(char);
	bool go(const string&);
	void updHp(int dh);

private:
	int hp;
	vector<char> let;
	void erraseLetters(const string&);
	bool checkWordLetters(const string&) const;
};
#endif
