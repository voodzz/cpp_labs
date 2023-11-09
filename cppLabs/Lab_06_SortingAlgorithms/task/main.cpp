#include <iostream>
#include <vector>
//#define _CRT_SECURE_NO_WARNINGS
#include "sorting_algorithms.h"
#include "iodata.h"
#include "data_generation.h"
int main()
{
	//std::vector <int> list = {0, 1, 2, 4 , 5, 2}; 
	
	//std::vector <int> list = generateDataAscending(42); 
	//std::vector <int> list = generateDataDescending(42);
	std::vector <int> list = generateDataRandom(10000, 100);
	writeData(list, "data/input.txt");
	std::vector <int> list1 = readData("data/input.txt");
	//outToConsole(list1, ", ");
	bubbleSort<int>(list1);
	//outToConsole(list, ", ");
	writeData(list, "data/output.txt");

}