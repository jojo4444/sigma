#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::string;

class Player {
public:
	Player(int hp);

	void turn(const string& word);
	bool checkTurn(const string& word) const;

	void addNewLetters(const vector<char>& nlet);
	void updateLetters(const vector<char>& nlet);

	int getHp() const;
	void updHp(int dh);

	vector<char> getLets() const;

private:
	int hp_;
	vector<char> let_;
};

#endif
