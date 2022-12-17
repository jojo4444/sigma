#include "dict.hpp"

int main() {
	Dict d;

	for (int i = 0; i < 100; ++i) {
		std::cout << d.getLet();
	}
	std::cout << "\n";

	vector<char> let = {'a', 'a', 'b', 'o', 'd', 't', 'c', 'c'};
	vector<string> hints = d.getHints(let);

	std::cout << hints.size() << "\n";

	for (string w : hints) {
		std::cout << w << " ";
	}
	
	return 0;
}
