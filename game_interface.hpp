#ifndef GAME_INTERFACE_HEADER
#define GAME_INTERFACE_HEADER

#include <iostream>
#include <vector>

#include "game.hpp"
#include "painter.hpp"

using std::vector;

const Color BG_COLOR = Color(43, 174, 102);
const Color FG_COLOR = Color(252, 246, 245);

const Color BG_COLOR_ACTIVE = FG_COLOR;
const Color FG_COLOR_ACTIVE = BG_COLOR;

const Color CARD_COLOR = Color(45, 41, 38);

const Color HP_ADD_COLOR = Color(51, 61, 121);
const Color HP_DEL_COLOR = Color(44, 95, 45);

const int DEFAULT_W = 85;
const int DEFAULT_H = 21;

class GameInterface {
public:
	GameInterface(const Game& g);

 	void draw(const Game& g, int player);
 	void drawInput(const string& word, wordStat s, int player);

private:
	void initTab();
 	
	void clearHp(int player);
	void clearInput(int player);
	void clearHints();

	void drawHp(int hp, int player);
  	void drawLetters(const vector<char>& lettters, int player);
  	void drawHints(const pair<vectorHints, vectorHints>& h);

  	void setActive(int player);

	cell tab[DEFAULT_H][DEFAULT_W];
};

#endif

/*
ширина 85
высота 21

20  +--- hp ---+------- enter word -----------+---- hint hp- ------+---- hint hp+ ------+
19  |          |                              |                    |                    |
18  |   100    |                              |                    |                    |
17  |          |                              |                    |                    |
16  +----------+------------------------------+                    |                    |
15  |                                         |                    |                    |
14  | +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ |                    |                    |
13  | |a| |a| |b| |c| |d| |e| |f| |a| |a| |a| |                    |                    |
12  | +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ |                    |                    |
11  |                                         |                    |                    |
10  +----------+------------------------------+                    |                    |
9   |          |                              |                    |                    |
8   |   100    |                              |                    |                    |
7   |          |                              |                    |                    |
6   +----------+------------------------------+                    |                    |
5   |                                         |                    |                    |
4   | +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ |                    |                    |
3   | |a| |t| |a| |y| |q| |a| |a| |k| |a| |z| |                    |                    |
2   | +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ |                    |                    |
1   |                                         |                    |                    |
0   +-----------------------------------------+--------------------+--------------------+|cursor = default|
    0          |11                            |42                  |63                 84|85
                ..........      .       .      ..........  .   .
                                +16     +24                +12 +16

default - (85, 0)

shiftCol(-85);
shiftRow(18);
 --- paint();
shiftToBeginCol();
shiftRow(-18);
shiftCol(85);

инвариант:
любой метод рисования:
 - при запуске имеет позицию курсора = default
 - на выходе позиция курсора = default

задачи:
 - формула для hp+-
 - разделение hints по +- 
 - hgeth --> enter word
 - enter word --> научиться word stat + find dict + error message
*/

