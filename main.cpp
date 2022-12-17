#include "dict.hpp"
#include "game.hpp"

int main() {
	Dict d;

	for (int i = 0; i < 100; ++i) {
		std::cout << d.getLet();
	}
	std::cout << "\n";

	vector<char> let = {'a', 'a', 'b', 'o', 'd', 't', 'c', 'c'};
	vector<pair<string, wordStat> > hints = d.getHints(let);

	std::cout << hints.size() << "\n";

	for (auto [w, s] : hints) {
		std::cout << w << " " << s.add << " " << s.del << "\n"; 
	}
	std::cout << "\n";

	Game g(&d);
	
	return 0;
}
