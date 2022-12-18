#ifndef GAME_INTERFACE_HEADER
#define GAME_INTERFACE_HEADER

#include <iostream>

#include "game.hpp"
#include "painter.hpp"

const int DEFAULT_W = 85;
const int DEFAULT_H = 21;

class GameInterface {
public:
	GameInterface(const Game& g);

	void paint(const Game& g) const;

	string getToken() const; 

private:
	void initTab();

	cell tab[DEFAULT_H][DEFAULT_W];
};

#endif

/*
ширина 85
высота 21

20  +--- hp ---+------- enter word -----------+---- hint hp+ ------+---- hint hp- ------+
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


а) каркас, cell, shift/row/col/cursor/color
б) paint, используя shift/color... [hp, lets]
*/