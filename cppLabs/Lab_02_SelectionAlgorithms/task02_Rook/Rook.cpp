#include <iostream>

int main()
{
	int x1, y1;
	int x2, y2;

	std::cout << "Input x1 and y1: ";
	std::cin >> x1 >> y1;
	std::cout << "Input x2 and y2: ";
	std::cin >> x2 >> y2;

	if (y1 > 8 || y2 > 8 || x1 > 8 || x2 > 8 || y1 < 1 || y2 < 1 || x1 < 1 || x2 < 1) {
		std::cout << "Wrong input.\n";
		return 0;
	}
	
	if (y1 == y2 || x1 == x2) {
		std::cout << "The rook can move to this square.\n";
	} else {
		std::cout << "The rook can not move to this square.\n";
	}

	return 0;
}