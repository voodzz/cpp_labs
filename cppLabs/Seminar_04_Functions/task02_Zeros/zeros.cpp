/**
*Task 2: ��� ������ (vector) �� n �����. ����������� ���, ������ ������� ��������.
*/

#include <iostream>
#include <vector>

size_t readUnsignedIntegerFromConsole(std::string);
void removingZeros(std::vector<int>& numbers);
void readElementsOfVector(std::vector<int>& numbers);
void output(std::vector<int>& numbers);

int main() {
    size_t n;
    n = readUnsignedIntegerFromConsole("Enter the number of elements: ");
    std::vector<int> numbers(n);
    readElementsOfVector(numbers); // ������ �������� �������.
    removingZeros(numbers);
    output(numbers);
    return 0;
}

size_t readUnsignedIntegerFromConsole(std::string label) {
    std::cout << label;
    size_t n;
    std::cin >> n;
    return n;
}

void readElementsOfVector(std::vector<int>& numbers) {
    for (auto& number : numbers) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> number;
    }
}

void removingZeros(std::vector<int>& numbers) {
    for (size_t i = 0; i != numbers.size(); ++i) {
        
        //��������� ����� �� ������� ���� �, ���� ��, ������� ���:
        if (numbers[i] == 0) {
            numbers.erase(numbers.begin() + i);
            --i;
        }
    }
}

void output(std::vector<int>& numbers) {
    for (auto& number : numbers) {
        std::cout << number << ' ';
    }
}