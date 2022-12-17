#include <random>

class Word {
public:
	Word();
	~Word();

	char GetLet() const;
	string[] FindWords(string word) const; /// and other +-
	<hp+, hp- > WordStat(string word) const;
	string[] GetHints(let[]) const;

private:
	mutable std::random_device rd_;
    mutable std::mt19937 gen_;
    mutable std::discrete_distribution<int> d;
    
	string[] words_;
};

GetLet() {
	DISTIBUTION<vector<int> > eng({cnt_a, cnt_b, ..., cnt_z});
}