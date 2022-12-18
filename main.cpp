#include "dict.hpp"
#include "game.hpp"
#include "painter.hpp"

int main() {
	Dict d;

	cell c;
	for (int i = 0; i < 100; ++i) {
		c.sym = d.getLet();
		c.fg = Color(255 - i, 0, 255 - i);
		c.bg = Color(i, i, 0);
		c.paint();
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
