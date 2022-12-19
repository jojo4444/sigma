#ifndef GAME_INTERFACE_HEADER
#define GAME_INTERFACE_HEADER

#include <iostream>
#include <vector>
#include <map>

#include "game.hpp"
#include "painter.hpp"

using std::vector;

const Color BG_COLOR = Color(43, 174, 102);
const Color FG_COLOR = Color(252, 246, 245);

const Color BG_COLOR_ACTIVE = FG_COLOR;
const Color FG_COLOR_ACTIVE = BG_COLOR;

const Color HP_ADD_COLOR = Color(51, 61, 121);
const Color HP_DEL_COLOR = Color(153, 0, 0);

const int DEFAULT_W = 85;
const int DEFAULT_H = 21;

class GameInterface {
public:
	GameInterface(const Game& g);

 	void draw(const Game& g, int player);
 	void drawInput(const Game& g, const string& word, wordStat s, int player);

private:
	void initTab();
 	
	void clearHp(int player);
	void clearInput(int player);
	void clearHints();

	void drawHp(int hp, int player);
	void drawLetters(const vector<char>& lettters, int player, const string& token);
  	void drawLetters(const vector<char>& lettters, int player);
  	void drawHints(const pair<vectorHints, vectorHints>& h);

  	void setActive(int player);

	cell tab[DEFAULT_H][DEFAULT_W];
};

#endif

/*
ширина 85
высота 21

21
20 ┌─── hp ───┬─────── enter word ───────────┬ hint ⚔ ────❤ ──⚔ ──┬ hint ❤ ────❤ ──⚔ ──┐
19 │          │                              │ condoler   6   6   │ oorie      0   5   │
18 │   100    │ condoler       6       16    │ oceloid    2   7   │ looie      0   5   │
17 │          │                              │ diocoel    2   7   │ oroide     6   6   │
16 ├──────────┴──────────────────────────────┤ eidolon    2   7   │ oecoid     6   6   │
15 │                                         │ oenolic    2   7   │ coorie     6   6   │
14 │   ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐   │ cooried    2   7   │ coolie     6   6   │
13 │   │e│ │i│ │o│ │o│ │c│ │d│ │l│ │n│ │r│   │ coonier    2   7   │ oriole     6   6   │
12 │   └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘   │ loonier    2   7   │ doolie     6   6   │
11 │                                         │ coronel    9   7   │ oldie      5   5   │
10 ├──────────┬──────────────────────────────┤ creolin    9   7   │ coeno      5   5   │
9  │          │                              │ croodle    9   7   │ dione      5   5   │
8  │   100    │                              │ crooned    9   7   │ orion      5   5   │
7  │          │                              │ decolor    9   7   │ ileon      5   5   │
6  ├──────────┴──────────────────────────────┤ dicolon    9   7   │ deloo      5   5   │
5  │                                         │ lionced    9   7   │ deino      5   5   │
4  │   ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐   │ condole    9   7   │ looed      5   5   │
3  │   │i│ │i│ │o│ │u│ │r│ │r│ │s│ │s│ │t│   │ codline    9   7   │ olein      5   5   │
2  │   └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘   │ orcinol    9   7   │ oleic      5   5   │
1  │                                         │ colored    9   7   │ oriel      5   5   │
0  └─────────────────────────────────────────┴────────────────────┴────────────────────┘|cursor = default|
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
 - улучшить систему счета (добавить криты если 8 или 9 символов)
*/

