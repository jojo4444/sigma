#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <tuple>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::tuple;
using std::string;

class Game {
public:
	Game(Dict* dict);
	~Game();

	bool go(const string& word, int step);
	bool finish() const;

private:
	const Dict* dict;
	Player a, b;
	vector<tuple<string, int, int>> hints;
	set<string> used;
};
#endif


// <char[][], color[][]> GetMap() ---> Terminal