//Дано натуральное число. Разложить его на простые множители.

/*number			  result
	5					5
	4					2*2
	9					3*3
	12					2*2*3
	15					3*5
	126					2*3*3*7
	99					3*3*11
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> factors;
	int number;
	std::cout << "Input the number: ";
	std::cin >> number;
	int tmp = number;

	while (tmp != 1) {
		for (int i = 2; tmp != 1; ++i) {
			while ((tmp % i) == 0) {
				tmp = tmp / i;
				factors.push_back(i);
			}
		}
	}

	std::cout << "The result of decomposition into prime factors:\n" << number << " = ";
	for (size_t i = 0; i != factors.size() - 1; ++i) {
		std::cout << factors[i] << '*';
	}
	std::cout << factors[factors.size() - 1];
	
	std::cout << std::endl;
	return 0;
}