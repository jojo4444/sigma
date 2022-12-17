#include <iostream>

// #include player, game, ..

int main() {
	Terminal; 

	Word dict;
	Game(dict);

	int step = 1;

	Terminal.Paint(step, Game);

	while (true) {
		std::string word = Terminal.GetToken();
		if (word == "!q") {
			break;
		}
		if (Game.Go(word, step)) {
			step = 3 - step;
			Terminal.Paint(step, Game);
		}
		if (Game.Finish()) {
			break;
		}
	}

	return 0;
}
