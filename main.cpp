#include <iostream>

// #include player, game, ..

int main() {
	Game, Terminal; 
	int step = 1;
	
	Terminal.Paint(step, Game.GetMap());

	while (true) {
		std::string word = Terminal.GetToken();
		if (word == "end game") {
			break;
		}
		if (Game.Go(word, step)) {
			step = 3 - step;
			Terminal.Paint(step, Game.GetMap());
		}
	}

	return 0;
}
