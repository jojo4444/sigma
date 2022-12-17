#include Player

class Game {
public:
	Game(dict);
	~Game();

	bool Go(word, step);
	bool Finish() const;

private:
	Player a_, b_; /// Alice, Bob xddd
	<string, hp-, hp+>[] hints_;
	set<string> used_;
};

// <char[][], color[][]> GetMap() ---> Terminal