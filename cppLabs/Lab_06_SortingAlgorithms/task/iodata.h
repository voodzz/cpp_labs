#ifndef IODATA_H_
#define IODATA_H_

#include <array>
#include <ctime>
#include <chrono>
#include <vector>

void writeInputAscendingDataToFile(const std::vector<int>& list);
void writeInputDescendingDataToFile(const std::vector<int>& list);
void writeInputRandomDataToFile(const std::vector<int>& list);
void chronoOutToFile(std::chrono::time_point<std::chrono::system_clock>& start,
                     std::chrono::time_point<std::chrono::system_clock>& end,
                     const std::string& filePath, const std::string& sort, size_t& size);

#endif // IODATA_H_