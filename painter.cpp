#include "painter.hpp"

Color::Color() : r(-1), g(-1), b(-1) {}

Color::Color(int R, int G, int B) : r(R), g(G), b(B) {}

void Color::reset() {
	r = g = b = -1;
}

void Color::set(int R, int G, int B) {
	r = R;
	g = G;
	b = B;
}

string Color::colorForeground() const {
	if (r == -1) {
		return "\033[0m"; // "\033[39m";
	}
    std::stringstream ss;
    ss << "\033[38;2;" << r << ";" << g << ";" << b << "m";
    return ss.str();
}

string Color::colorBackground() const {
	if (r == -1) {
		return "\033[0m"; // "\033[49m";
	}
    std::stringstream ss;
    ss << "\033[48;2;" << r << ";" << g << ";" << b << "m";
    return ss.str();
}

void cell::paint() const {
	std::cout << fg.colorForeground() << bg.colorBackground() << sym << "\033[0m" << std::flush;
}

void shiftRow(int r) {
	if (r > 0) {
        std::cout << "\033[" + std::to_string(r) + "A" << std::flush;
    } else if (r < 0) {
        std::cout << "\033[" + std::to_string(-r) + "B" << std::flush;
    }
}

void shiftCol(int c) {
	if (c > 0) {
        std::cout << "\033[" + std::to_string(c) + "C" << std::flush;
    } else if (c < 0) {
        std::cout << "\033[" + std::to_string(-c) + "D" << std::flush;
    }
}

void toBeginCol() {
    std::cout << "\033[" << std::numeric_limits<short>::max() << "D" << std::flush;
}

string convert(char c) {
	return string(1, c);
}

int hgetch() {
    int ch;
    termios old_termios{}, new_termios{};
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    return ch;
}