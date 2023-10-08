#include <iostream>
#include <vector>

size_t readUnsignedIntFromConsole(std::string);
void readVectorFromConsole(std::vector<double>& vector);
int rearrangeTheArrayElementsInReverseOrder(std::vector<double>& vector);

int main() {
    int n = readUnsignedIntFromConsole("Enter the number of elements in the vector: ");
    std::vector<double> vector(n);
    readVectorFromConsole(vector);
    rearrangeTheArrayElementsInReverseOrder(vector);
    return 0;
}

size_t readUnsignedIntFromConsole(std::string label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void readVectorFromConsole(std::vector<double>& vector) {
    for (size_t i = 0; i != vector.size(); ++i) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> vector[i];
    }
}

int rearrangeTheArrayElementsInReverseOrder(std::vector<double>& vector) {
    for (size_t i = 0; i <= (vector.size() - 1)/2; ++i) {
        std::swap(vector[i], vector [vector.size() - 1 - i]);
    }
    std::cout << "The rearranged vector: ";
    for (const auto& element : vector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    return 0;
}