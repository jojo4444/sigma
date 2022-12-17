#ifndef PLAYER_H
#define PLAYER_H

#include "words.hpp"
#include <vector>
#include <tuple>

class Player {
public:
	Player(Word* dict_);
	~Player();

	int getHp() const;
	std::vector<char>& getLet() const;
	std::tuple<bool, int, int> go(const std::string&);
	void updHp(int dh);
	std::vector<std::string> getHints();

private:
	const Word* dict;
	int hp;
	std::vector<char> let;
};
#endif
