#ifndef PAINTER_HEADER
#define PAINTER_HEADER

#include <iostream>
#include <sstream>
#include <limits>

using std::string;

class Color {
public:
	Color();
	Color(int R, int G, int B);

	void reset();
	void set(int R, int G, int B);

	string colorForeground() const;
	string colorBackground() const;

private:
	int r, g, b;
};

struct cell {
	string sym;
	Color fg, bg;

	void paint() const;
};

void shiftRow(int r);
void shiftCol(int c);
void toBeginCol();

#endif