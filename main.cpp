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

	string token;
	int player = 1;

	auto step = [&]() {
		while (true) {
			int c = hgetch();
			if (c == '\n') {
				break;
			}
			if (c == 127) {
				if (!token.empty()) {
					token.pop_back();
				}
			}
			if (c >= 'a' && c <= 'z' && token.size() < DEFAULT_PLAYER_LETTERS_COUNT) { 
				token.push_back(c);
			}
			//cli.drawEntry(token, player);
		}	
	};

	while (!g.finish()) {
		step();
		if (!g.checkGo(token, player)) {
			//cli.writeError(player, "kek bro");
			continue;
		}
		g.go(token, player);
		token = "";
		player = 3 - player;
		cli.draw(g);
	}

	return 0;
}
