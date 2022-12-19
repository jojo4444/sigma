#include "dict.hpp"
#include "game.hpp"
#include "painter.hpp"
#include "game_interface.hpp"

int main() {
	Dict d;

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
			if (!g.getPlayer(player).checkTurn(token)){
				token.pop_back();
			}
			cli.drawInput(g, token, d.getWordStat(token), player);
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
		cli.draw(g, player);
	}

	return 0;
}
