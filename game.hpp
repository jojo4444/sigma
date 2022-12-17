#ifndef GAME_H
#define GAME_H

#include <utility>
#include <vector>

#include "player.hpp"
#include "dict.hpp"

using std::vector;
using std::pair;
using std::string;

const int DEFAULT_PLAYER_HP = 100;
const int DEFAULT_PLAYER_LETTERS_COUNT = 9;

class Game {
public:
	Game(Dict* dict);

	vector<pair<string, wordStat> > getHints() const;

	bool go(const string& word, int step);
	bool finish() const;

private:
	Dict* dict_;
	Player alice_, bob_;
	vector<pair<string, wordStat> > hints_;

	vector<char> generateLetters(int cnt);
};

#endif