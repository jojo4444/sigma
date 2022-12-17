#include <words.hpp>
#include <vector>
#include <tuple>

class Player {
public:
	Player(Word* dict_);
	~Player();

	int getHp() const;
	vector<char> getLet() const;
	tuple<bool, int, int> go(std::string word);
	void updHp(int dh);
	vector<string> getHints();

private:
	const Word* dict;
	int hp;
	vector<char> let;
};