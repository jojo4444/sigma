#include "player.h"
#include <tuple>
#include <vector>
#include <set>

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game(Word* dict);
	~Game();

	bool go(const std::string& word, int step);
	bool finish() const;

private:
	Player a, b; /// Alice, Bob xddd
	std::vector<std::tuple<std::string, int, int>> hints;
	std::set<std::string> used;
};
#endif


// <char[][], color[][]> GetMap() ---> Terminal