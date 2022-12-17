#include Words

class Player {
public:
	Player(dict);
	~Player();

	int GetHp() const;
	char[] GetLet() const;

	<bool, hp-, hp+> Go(word);
	void UpdHp(int dh); /// hp_ += dh
	string[] GetHints();

private:
	const Word* dict_;
	int hp_;
	char[] let_;
};