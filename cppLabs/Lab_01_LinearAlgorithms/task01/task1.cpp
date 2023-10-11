#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "What's your name?\n";
	std::getline(std::cin, name);

	std::cout << "Nice to meet you, " << name << '\n';

	return 0;
}