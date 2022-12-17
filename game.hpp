#include Player

class Game {
public:
	Game();
	~Game();
	bool Go(word, step);
	<char[][], color[][]> GetMap();

private:
	Player a_, b_; /// Alice, Bob xddd
	<string, hp-, hp+>[] hints_;
	string[] used_;
};