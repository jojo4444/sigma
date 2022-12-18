#ifndef GAME_HEADER
#define GAME_HEADER

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

	pair<vectorHints, vectorHints> getHints() const;
	Player getPlayer(int player) const;

	bool checkGo(const string& word, int player) const;
	void go(const string& word, int player);
	bool finish() const;

private:
	Dict* dict_;
	Player alice_, bob_;
	pair<vectorHints, vectorHints> hints_;

	vector<char> generateLetters(int cnt);
};

#endif