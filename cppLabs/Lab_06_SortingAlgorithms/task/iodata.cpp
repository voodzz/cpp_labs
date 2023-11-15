#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "iodata.h"

void writeInputAscendingDataToFile(const std::vector<int>& list) {
    std::string filePath;
    if (list.size() == 10) {
        filePath = "CMakeFiles/data/input_10_int_ascending.txt";
    } else if (list.size() == 100) {
        filePath = "CMakeFiles/data/input_100_int_ascending.txt";
    } else if (list.size() == 1000) {
        filePath = "CMakeFiles/data/input_1000_int_ascending.txt";
    } else if (list.size() == 10000) {
        filePath = "CMakeFiles/data/input_10000_int_ascending.txt";
    }
	std::ofstream output(filePath, std::ios::out);
	for (const auto& item : list) {
		output << item << '\n';
	}
	output.close();
}

void writeInputDescendingDataToFile(const std::vector<int>& list) {
    std::string filePath;
    if (list.size() == 10) {
        filePath = "CMakeFiles/data/input_10_int_descending.txt";
    } else if (list.size() == 100) {
        filePath = "CMakeFiles/data/input_100_int_descending.txt";
    } else if (list.size() == 1000) {
        filePath = "CMakeFiles/data/input_1000_int_descending.txt";
    } else if (list.size() == 10000) {
        filePath = "CMakeFiles/data/input_10000_int_descending.txt";
    }
    std::ofstream output(filePath, std::ios::out);
    for (const auto& item : list) {
        output << item << '\n';
    }
    output.close();
}

int inputCounter = 1;
void writeInputRandomDataToFile(const std::vector<int>& list) {
    std::string filePath;
    if (::inputCounter == 1) {
        if (list.size() == 10) {
            filePath = "CMakeFiles/data/input_10_int_random_1.txt";
        } else if (list.size() == 100) {
            filePath = "CMakeFiles/data/input_100_int_random_1.txt";
        } else if (list.size() == 1000) {
            filePath = "CMakeFiles/data/input_1000_int_random_1.txt";
        } else if (list.size() == 10000) {
            filePath = "CMakeFiles/data/input_10000_int_random_1.txt";
        }
        std::ofstream output(filePath, std::ios::out);
        for (const auto& item: list) {
            output << item << '\n';
        }
        output.close();
        ::inputCounter++;
    } else if (::inputCounter == 2) {
        if (list.size() == 10) {
            filePath = "CMakeFiles/data/input_10_int_random_2.txt";
        } else if (list.size() == 100) {
            filePath = "CMakeFiles/data/input_100_int_random_2.txt";
        } else if (list.size() == 1000) {
            filePath = "CMakeFiles/data/input_1000_int_random_2.txt";
        } else if (list.size() == 10000) {
            filePath = "CMakeFiles/data/input_10000_int_random_2.txt";
        }
        std::ofstream output(filePath, std::ios::out);
        for (const auto& item: list) {
            output << item << '\n';
        }
        output.close();
        ::inputCounter++;
    } else if (inputCounter == 3) {
        if (list.size() == 10) {
            filePath = "CMakeFiles/data/input_10_int_random_3.txt";
        } else if (list.size() == 100) {
            filePath = "CMakeFiles/data/input_100_int_random_3.txt";
        } else if (list.size() == 1000) {
            filePath = "CMakeFiles/data/input_1000_int_random_3.txt";
        } else if (list.size() == 10000) {
            filePath = "CMakeFiles/data/input_10000_int_random_3.txt";
        }
        std::ofstream output(filePath, std::ios::out);
        for (const auto& item: list) {
            output << item << '\n';
        }
        output.close();
        ::inputCounter = 1;
    }
}

void chronoOutToFile(std::chrono::time_point<std::chrono::system_clock>& start,
                     std::chrono::time_point<std::chrono::system_clock>& end,
                     const std::string& filePath, const std::string& sort, size_t& size) {
    auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds >(end - start);
    auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::ofstream fout(filePath, std::ios::app);
    fout << sort << '(' << size << "):\n" << "Algorithm execution time: "
         << elapsed_milliseconds.count() << "ms\n" << "Algorithm execution time: "
         << elapsed_microseconds.count() << "mcs\n";
    fout.close();
}
