//Вывести все делители числа n.

/*number			result
	6				1 2 3 6
	107				1 107
	31				1 31
	1				1
	9				1 3 9
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> dividers;
	int n;
	std::cout << "Input the value of n: ";
	std::cin >> n;
	
	if (n <= 0) {
		std::cout << "Wrong input: n <=0.";
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		if ((n % i) == 0) {
			dividers.push_back(i);
		}
	}

	std::cout << "The dividers of n are: ";
	for (size_t i = 0; i != dividers.size(); ++i) {
		std::cout << dividers[i] << ' ';
	}

	std::cout << std::endl;
	return 0;
}