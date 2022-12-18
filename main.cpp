#include "dict.hpp"
#include "game.hpp"
#include "painter.hpp"
#include "game_interface.hpp"

int main() {
	Dict d;
	
	for (int i = 0; i < 80; ++i) {
		std::cout << d.getLet();
	}

	cell c;
	for (int i = 0; i < 100; ++i) {
		c.sym = d.getLet();
		c.fg = Color(255 - i, 0, 255 - i);
		c.bg = Color(i, i, 0);
		c.paint();
	}
	std::cout << "\n";

	vector<char> let = {'a', 'f', 'b', 'o', 'd', 't', 'c', 'e', 'k'};
	vector<pair<string, wordStat> > hints = d.getHints(let);

	std::cout << hints.size() << "\n";

	for (auto [w, s] : hints) {
		std::cout << w << " " << s.add << " " << s.del << "\n"; 
	}
	std::cout << "\n";

	Game g(&d);

	GameInterface cli(g);

	/*cli.drawHpBar(100, 1);
	cli.drawHpBar(99, 2);
	cli.drawLettersBar(let, 1);
	cli.drawLettersBar(let, 2);

	cli.clearHpBar(1);
	cli.clearHpBar(2);
	cli.clearHints();
	cli.clearEnterWordBar(1);
	cli.clearEnterWordBar(2);*/
	

	return 0;
}
