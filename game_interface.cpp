#include "game_interface.hpp"

GameInterface::GameInterface(const Game& g) {
	for (int i = 0; i < DEFAULT_H; ++i) {
		std::cout << string(DEFAULT_W, ' ');
		if (i + 1 < DEFAULT_H) {
			std::cout << "\n";
		} 
	}
	initTab();
	draw(g, 1);
}

void GameInterface::draw(const Game& g, int player) {
	for (int p = 1; p <= 2; ++p) {
		clearInput(p);
		clearHp(p);
	} 
	clearHints();

	setActive(player);
	
	Player alice = g.getPlayer(1);
	Player bob = g.getPlayer(2);

	drawHp(alice.getHp(), 1);
	drawHp(bob.getHp(), 2);
	drawLetters(alice.getLets(), 1);
	drawLetters(bob.getLets(), 2);

	drawHints(g.getHints());

	toBeginCol();
	shiftRow(DEFAULT_H - 1);
	for (int i = DEFAULT_H - 1; i >= 0; --i) {
		for (int j = 0; j < DEFAULT_W; ++j) {
			tab[i][j].paint();
		}
		if (i) {
			std::cout << "\n";
		}
	}
	std::cout << std::flush;
}

void GameInterface::drawInput(const Game& g, const string& word, wordStat s, int player) {
	int r = player == 1 ? 18 : 8;
	int c = 12;

	drawLetters(g.getPlayer(player).getLets(), player, word);
	clearInput(player);
	for (int j = 0; j < word.size(); ++j) {
		tab[r][c + 1 + j].sym = convert(word[j]);
	}
	if (s.correct()) {
		string add = std::to_string(s.add);
		string del = std::to_string(s.del);
		for (int j = 0; j < add.size(); ++j) {
			tab[r][c + 16 + j].sym = convert(add[j]);
			tab[r][c + 16 + j].fg = HP_ADD_COLOR;
		}
		for (int j = 0; j < del.size(); ++j) {
			tab[r][c + 24 + j].sym = convert(del[j]);
			tab[r][c + 24 + j].fg = HP_DEL_COLOR;
		}
	} 

	toBeginCol();
	shiftRow(r);
	shiftCol(c);
	for (int i = 0; i < 30; ++i) {
		tab[r][c + i].paint();
	}
	toBeginCol();
	shiftRow(-r);
	shiftCol(DEFAULT_W);
}

void GameInterface::initTab() {
	int n = DEFAULT_H;
	int m = DEFAULT_W;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			tab[i][j].sym = " "; 
			tab[i][j].bg = BG_COLOR;
			tab[i][j].fg = FG_COLOR;
		}
	}

	// corners
	tab[0][0].sym = "└";
	tab[0][m - 1].sym = "┘";
	tab[n - 1][0].sym = "┌";
	tab[n - 1][m - 1].sym = "┐";
	
	// up/down board
	for (int j = 1; j < m - 1; ++j) {
		tab[0][j].sym = tab[n - 1][j].sym = "─";
	}

	// col board
	for (int i = 1; i < n - 1; ++i) {
		tab[i][0].sym = tab[i][42].sym = tab[i][63].sym = tab[i][84].sym = "│";
	}
	tab[0][42].sym = tab[0][63].sym = "┴";
	tab[n - 1][42].sym = tab[n - 1][63].sym = "┬";

	// game lines
	for (int j = 1; j < 42; ++j) {
		tab[6][j].sym = tab[10][j].sym = tab[16][j].sym = "─";
	}
	tab[6][0].sym = tab[10][0].sym = tab[16][0].sym = "├";
	tab[6][42].sym = tab[10][42].sym = tab[16][42].sym = "┤";

	// hp bar
	for (int i = 0; i < 3; ++i) {
		tab[7 + i][11].sym = tab[17 + i][11].sym = "│";
	}
	tab[6][11].sym = tab[16][11].sym = "┴";
	tab[10][11].sym = tab[20][11].sym = "┬";

	auto write = [&](int r, int c, const string& msg) -> void {
		for (int i = 0; i < msg.size(); ++i) {
			if (c + i >= DEFAULT_W) {
				break;
			}
			tab[r][c + i].sym = convert(msg[i]);
		}
	};

	write(20, 4, " hp ");
	write(20, 19, " enter word ");
	write(20, 47, " hint hp- ");
	write(20, 68, " hint hp+ ");
}

void GameInterface::clearHp(int player) {
    int r = player == 1 ? 18 : 8, c = 1;
    toBeginCol();
    shiftRow(r);
    shiftCol(c);
    for (int i = c; i < 11; ++i){
        tab[r][i].sym = " ";
        tab[r][i].paint();
    }
    toBeginCol();
    shiftRow(-r);
    shiftCol(DEFAULT_W);
}

void GameInterface::clearInput(int player) {
    int r = player == 1 ? 18 : 8, c = 12;
    toBeginCol();
    shiftRow(r);
    shiftCol(c);
    for (int i = 0; i < 30; ++i){
        tab[r][c + i].sym = " ";
        tab[r][c + i].paint();
    }
    toBeginCol();
    shiftRow(-r);
    shiftCol(DEFAULT_W);
}

void GameInterface::clearHints() {
    toBeginCol();
    for (int r = 1; r < 20; ++r) {
        shiftRow(1);
        shiftCol(43);
        for (int c = 43; c < 84; c++) if (c != 63) {
            tab[r][c].sym = " ";
            tab[r][c].paint();
        } else {
            shiftCol(1);
        }
        toBeginCol();
    }
    shiftRow(-19);
    shiftCol(DEFAULT_W);
}

void GameInterface::drawLetters(const vector<char>& letters, int player, const string& token) {
	std::map<char, int> cnt;
	for (char c : token) {
		cnt[c]++;
	}
	
	int r = player == 1 ? 12 : 2;
    toBeginCol();
    shiftRow(r);

    string board[3][3] = {
    	{"└", "─", "┘"},
    	{"│", " ", "│"},
    	{"┌", "─", "┐"},
    };

    for (int i = 0; i < letters.size(); ++i) {
    	int c = 4 + i*4;
    	shiftCol(c);

		bool isActive = cnt[letters[i]]-- > 0;
		Color bg = isActive ? BG_COLOR_ACTIVE : BG_COLOR;
		Color fg = isActive ? FG_COLOR_ACTIVE : FG_COLOR;

    	for (int dr = 0; dr < 3; ++dr) {
    		for (int dc = 0; dc < 3; ++dc) {
    			tab[r + dr][c + dc].sym = board[dr][dc];
    			tab[r + dr][c + dc].fg = fg;
				tab[r + dr][c + dc].bg = bg;
    		}
    	}
    	tab[r + 1][c + 1].sym = convert(letters[i]);
		tab[r + 1][c + 1].fg = fg;
		tab[r + 1][c + 1].bg = bg;

    	for (int j = 0; j < 3; ++j) {
	    	tab[r + j][c].paint();
	    	tab[r + j][c + 1].paint();
	    	tab[r + j][c + 2].paint();
	    	shiftRow(1);
	    	shiftCol(-3);
	    }

   		toBeginCol();
   		shiftRow(-3);
    }

    shiftRow(-r);
    shiftCol(DEFAULT_W);
}

void GameInterface::drawLetters(const vector<char>& letters, int player) {
	drawLetters(letters, player, "");
}

void GameInterface::drawHp(int hp, int player) {
    string shp = std::to_string(hp);
    int r = player == 1 ? 18 : 8;
    int c = 5 - shp.size()/2;
    toBeginCol();
    shiftRow(r);
    shiftCol(c);
    for (char sym : shp){
        tab[r][c].sym = sym;
        tab[r][c].paint();
        c++;
    }
    toBeginCol();
    shiftRow(-r);
    shiftCol(DEFAULT_W);
}

void GameInterface::drawHints(const pair<vectorHints, vectorHints>& hints) {
	auto makeHint = [&](int r, int c, string word, wordStat s) -> void {
		for (int j = 0; j < word.size(); ++j) {
			tab[r][c + j + 1].sym = convert(word[j]);
		} 
		string add = std::to_string(s.add);
		string del = std::to_string(s.del);
		for (int j = 0; j < add.size(); ++j) {
			tab[r][c + 12].sym = convert(add[j]);
			tab[r][c + 12].fg = HP_ADD_COLOR;
		}
		for (int j = 0; j < del.size(); ++j) {
			tab[r][c + 16].sym = convert(del[j]);
			tab[r][c + 16].fg = HP_DEL_COLOR;
		}
	};

	toBeginCol();
	vector<vectorHints> h = {hints.second, hints.first};
	for (int i = 0; i < 2; ++i) {
		if (h[i].size() > 19) {
			h[i].resize(19);
		}
		int c = 43 + i*(64 - 43), r = 19;
		shiftCol(c);
		shiftRow(r);
		for (auto [word, stat] : h[i]) {
			makeHint(r, c, word, stat);
			for (int j = 0; j < 20; ++j) {
				tab[r][c + j].paint();
			}
			shiftRow(-1);
			shiftCol(-20);
			r--;
		}
		shiftRow(-r);
		toBeginCol();
	}

	shiftCol(DEFAULT_W);
}

void GameInterface::setActive(int player) {
	int dw = 10;
	int dh = 3;
	int c = 1;

	int r = player == 1 ? 7 : 17;
	for (int i = 0; i < dh; ++i) {
		for (int j = 0; j < dw; ++j) {
			tab[r + i][c + j].bg = BG_COLOR;
			tab[r + i][c + j].fg = FG_COLOR;
		}
	}

	r = player == 1 ? 17 : 7;
	for (int i = 0; i < dh; ++i) {
		for (int j = 0; j < dw; ++j) {
			tab[r + i][c + j].bg = BG_COLOR_ACTIVE;
			tab[r + i][c + j].fg = FG_COLOR_ACTIVE;
		}
	}
}