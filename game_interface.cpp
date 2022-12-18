#include "game_interface.hpp"

void GameInterface::drawLettersBar(const vector<char>& letters, int player){
    int rowNum = player == 1? 13 : 3;
    shiftCol(-85);
    shiftRow(rowNum - 1);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        shiftCol(i - 1);
        cells[rowNum - 1][i - 1].sym = '╔';
        cells[rowNum - 1][i - 1].paint();
        shiftCol(i);
        cells[rowNum - 1][i].sym = '═';
        cells[rowNum - 1][i].paint()
        shiftCol(i + 1);
        cells[rowNum - 1][i + 1].sym = '╗';
        cells[rowNum - 1][i + 1].paint()
    }
    shiftToBeginCol();
    shiftRow(rowNum + 1);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        shiftCol(i - 1);
        cells[rowNum + 1][i - 1].sym = '╚';
        cells[rowNum + 1][i - 1].paint()
        shiftCol(i);
        cells[rowNum + 1][i].sym = '═';
        cells[rowNum + 1][i].paint()
        shiftCol(i + 1);
        cells[rowNum + 1][i + 1].sym = '╝';
        cells[rowNum + 1][i + 1].paint()
    }
    shiftToBeginCol();
    shiftRow(rowNum);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        
        shiftCol(i - 1);
        cells[rowNum][i - 1].sym = '║';
        cells[rowNum][i - 1].paint();

        shiftCol(i);
        cells[rowNum][i].sym = letters[j];
        cells[rowNum][i].paint();

        shiftCol(i + 1);
        cells[rowNum][i - 1].sym = '║';
        cells[rowNum][i - 1].paint();
    }
    shiftToBeginCol();
    shiftRow(-rowNum);
    shiftCol(85);
}

void GameInterface::drawHpBar(int hp, int player){
  auto str = std::to_string(hp);
  int rowNum = player == 1? 18 : 10
  shiftCol(-85);
  shiftRow(rowNum);
  const int mcol = 6;
  for (int i = (str.size() >> 1), j = mcol; i >= 0; --i, --j){
    cells[rowNum][j].sym = str[i];
    cells[rowNum][j].paint();
  }
  for (int i = (str.size() >> 1) + 1, j = mcol + 1; i < str.size(); ++i, ++j){
    cells[rowNum][j].sym = str[i];
    cells[rowNum][j].paint();
  }
  shiftToBeginCol();
  shiftRow(-rowNum);
  shiftCol(85);
}
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
}