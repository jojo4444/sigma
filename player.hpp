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

	bool makeTurn(const string& word);
	void addNewLetters(const vector<char>& nlet);

	int getHp() const;
	void updHp(int dh);

	vector<char> getLets() const;
	void addLetter(char c);

private:
	int hp_;
	vector<char> let_;

	void erraseLetters(const string& word);
	bool checkWordLetters(const string& word) const;
};

#endif
