#include "dict.hpp"

wordStat::wordStat() {
	add = BAD_STATE.add;
	del = BAD_STATE.del;
}

wordStat::wordStat(int Add, int Del) {
	add = Add;
	del = Del;
}

bool wordStat::correct() const {
	return *this != BAD_STATE;
}

bool wordStat::operator> (const wordStat& T) const {
	return std::tie(del, add) > std::tie(T.del, T.add);
}

bool wordStat::operator!= (const wordStat& T) const {
	return std::tie(del, add) != std::tie(T.del, T.add);
}

Dict::Dict() {
	vector<int> cnt(26);

	std::ifstream file("../words.txt", std::ifstream::in);

	string word;
	vector<string> words;

	while (file >> word) {
		if (word.size() < MIN_LEN_WORD) {
			continue;
		}
		words.push_back(word);
	}
	file.close();

	// убираем повторы
	makeunique(words);

	bool empty = true;
	for (string w : words) {
		for (char c : w) {
			if (c < 'a' || c > 'z') {
				std::cerr << "Bad word: " << w << "\n";
				exit(-1);
			}
			cnt[c - 'a']++;
		}
		empty = false;
		t_.add(w); // инвариант соблюден из-за отсутствия повторов
	}

	if (empty) {
		std::cerr << "empty dictionary\n";
		exit(-1);
	}

	std::random_device rd;
	gen_.seed(rd());
	dist_ = std::discrete_distribution<int>(cnt.begin(), cnt.end());
}

bool Dict::correct(const string& word) const {
	for (char c : word) if (c < 'a' || c > 'z') {
		return false;
	}
	return true;
}

char Dict::getLet() const {
	return dist_(gen_) + 'a';
}

bool Dict::find(const string& word) const {
	return t_.find(word);
}

void Dict::del(const string& word) {
	return t_.del(word);
}

wordStat Dict::getWordStat(const string& word) const {
	if (!find(word)) {
		return BAD_STATE;
	}
	if (word.size() == 0) {
		return BAD_STATE;
	}
	for (char c : word) if (c < 'a' || c > 'z') {
		return BAD_STATE;
	}
	int add = 0, del = word.size();
	for (char c : word) {
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') {
			add++;
		}
	}
	return wordStat(add, del);
}

pair<vectorHints, vectorHints> Dict::getHints(const vector<char>& let) const {
	buffWord_.resize(0);
	buffHints_.resize(0);
	buffLet_ = let;
	generateSubwords();

	makeunique(buffHints_);

	vector<string> inDict;
	for (const string& w : buffHints_) if (find(w)) {
		inDict.push_back(w);
	}

	// чтобы итоговая память была строго O(min(LIM, |inDict|)) снаружи
	vectorHints add, del;

	std::sort(inDict.begin(), inDict.end(), [&](const string& a, const string& b) {
		return getWordStat(a).add > getWordStat(b).add;
	});
	for (int i = 0; i < std::min((int)inDict.size(), LIMIT_HINTS); ++i) {
		add.emplace_back(inDict[i], getWordStat(inDict[i]));
	}

	std::sort(inDict.begin(), inDict.end(), [&](const string& a, const string& b) {
		return getWordStat(a).del > getWordStat(b).del;
	});
	for (int i = 0; i < std::min((int)inDict.size(), LIMIT_HINTS); ++i) {
		del.emplace_back(inDict[i], getWordStat(inDict[i]));
	}

	return make_pair(add, del);
}

void Dict::generateSubwords() const {
	if (buffWord_.size() > 0) {
		buffHints_.push_back(buffWord_);
	}
	if (buffLet_.size() == buffWord_.size()) {
		return;
	}
	for (char& c : buffLet_) if (c) {
		char save_c = c;
		c = 0;
		buffWord_.push_back(save_c);
		generateSubwords();
		buffWord_.pop_back();
		c = save_c;
	}
}