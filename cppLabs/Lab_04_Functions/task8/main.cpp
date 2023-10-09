#include <iostream>
#include <vector>

size_t readUnsignedIntFromConsole (const std::string& label);
void readSequencesFromConsole (std::vector<std::vector<int>>& sequences, size_t& k);
void findTheNumberOfElementsInSequences(const std::vector<std::vector<int>>& sequences);

int main () {
    size_t k = readUnsignedIntFromConsole("Enter the the number of sequences (k): ");
    if (0 == k) {
        std::cout << "Wrong input: there are no sequences (k = 0).\n";
        return 0;
    }
    std::cout << '\n';
    std::vector<std::vector<int>> sequences(k);
    readSequencesFromConsole(sequences, k);
    findTheNumberOfElementsInSequences(sequences);
    return 0;
}

size_t readUnsignedIntFromConsole (const std::string& label) {
    std::cout << label;
    size_t k;
    std::cin >> k;
    return k;
}

void readSequencesFromConsole (std::vector<std::vector<int>>& sequences, size_t& k) {
    std::cout << "Enter the first sequence:\n";
    for (size_t i = 0; i != k; ++i) {
        int tmp = 1;
        while (tmp) {
            std::cout << "Enter the element of the sequence: ";
            std::cin >> tmp;
            if (tmp != 0) {
                sequences[i].push_back(tmp);
            }
        }
        if (i != k - 1) {
            std::cout << '\n' << "Enter the next sequence:\n";
        } else {
            std::cout << '\n';
        }
    }
}

void findTheNumberOfElementsInSequences(const std::vector<std::vector<int>>& sequences) {
    unsigned long long numberOfElementsInGeneral = 0;
    for (size_t i = 0; i != sequences.size(); ++i) {
        if (!sequences[i].empty()) {
            std::cout << "The number of elements in sequence №" << i + 1 << ": "
            << sequences[i].size() << '.';
        } else {
            std::cout << "There are no elements in sequence №" << i + 1 << '.';
        }
        std::cout << '\n';
        numberOfElementsInGeneral += sequences[i].size();
    }
    std::cout << "The overall number of elements in all of the given sequences: "
    << numberOfElementsInGeneral << ".\n";
}
