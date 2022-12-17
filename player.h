#include <words.hpp>
#include <vector>
#include <tuple>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player(Word* dict_);
	~Player();

	int getHp() const;
	std::vector<char> getLet() const;
	std::tuple<bool, int, int> go(std::string word);
	void updHp(int dh);
	std::vector<std::string> getHints();

private:
	const Word* dict;
	int hp;
	vector<char> let;
};
#endif
