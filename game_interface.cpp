#include "game_interface.hpp"

GameInterface::GameInterface(const Game& g) {
	for (int i = 0; i < DEFAULT_H; ++i) {
		std::cout << string(DEFAULT_W, ' ');
		if (i + 1 < DEFAULT_H) {
			std::cout << "\n";
		} 
	}
	initTab();
	paint(g);
}

void GameInterface::paint(const Game& g) const {
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

void GameInterface::initTab() {
	int n = DEFAULT_H;
	int m = DEFAULT_W;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			tab[i][j].sym = " "; 
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
			tab[r][c + i].sym = string(1, msg[i]);
		}
	};

	write(20, 4, " hp ");
	write(20, 19, " enter word ");
	write(20, 47, " hint hp+ ");
	write(20, 68, " hint hp- ");
}

void GameInterface::clearHpBar(int player) {
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
    shiftCol(85);

}

void GameInterface::clearEnterWordBar(int player) {
    int r = player == 1 ? 18 : 8, c = 12;
    toBeginCol();
    shiftRow(r);
    shiftCol(c);
    for (int i = c; i < 42; ++i){
        tab[r][i].sym = " ";
        tab[r][i].paint();
    }
    toBeginCol();
    shiftRow(-r);
    shiftCol(85);
}

void GameInterface::clearHints() {
    toBeginCol();
    for (int r = 1; r < 20; ++r){
        shiftRow(1);
        shiftCol(43);
        for (int c = 43; c < 84; c++) if (c != 63){
            tab[r][c].sym = " ";
            tab[r][c].paint();
        } else {
            shiftCol(1);
        }
        toBeginCol();
    }
    shiftRow(-20);
    shiftCol(85);
}

void GameInterface::drawLettersBar(const vector<char>& letters, int player) {
    int r = player == 1 ? 12 : 2;
    toBeginCol();
    shiftRow(r);

    for (int i = 0; i < letters.size(); ++i) {
    	int c = 4 + i*4;
    	shiftCol(c);

    	tab[r][c].sym = "╚";
    	tab[r][c + 1].sym = "═";
    	tab[r][c + 2].sym = "╝";

    	tab[r + 1][c].sym = "║";
    	tab[r + 1][c + 1].sym = string(1, letters[i]);
    	tab[r + 1][c + 2].sym = "║";

    	tab[r + 2][c].sym = "╔";
    	tab[r + 2][c + 1].sym = "═";
    	tab[r + 2][c + 2].sym = "╗";

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
    shiftCol(85);
}

void GameInterface::drawHpBar(int hp, int player) {
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
    shiftCol(85);
}