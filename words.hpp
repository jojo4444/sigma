class Word {
public:
	Word();
	~Word();

	char GetLet() const;
	string[] FindWords(string word); /// and other +-
	<hp+, hp- > WordStat(string word);

private:
	random_;	
	string[] words_;
};