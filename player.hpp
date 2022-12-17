#include Words

class Player {
public:
	Player();
	~Player();
	<bool, hp-, hp+> Go(word);
	int GetHp() const;
	char[] GetLet() const;
	void updHp(dh);

private:
	int hp_;
	char[] let_;
};