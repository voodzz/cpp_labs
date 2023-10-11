#include <iostream>

int main()
{
	double a;
	std::cout << "Enter the value of a: ";
	std::cin >> a;
	
	//points à), á), â):
	double a2 = a * a;
	double a4 = a2 * a2;
	double a6 = a4 * a2;
	double a7 = a6 * a;
	
	//point ã), ä):
	/* 
	1) double a2 = a * a;
	2) double a4 = a2 * a2;*/
	double a8 = a4 * a4;
	double a9 = a8 * a;
	
	//point å):
	/* 
	1) double a2 = a * a;
	2) double a4 = a2 * a2;*/
	double a5 = a4 * a;
	double a10 = a5 * a5;
	
	//point æ):
	/*
	1) double a2 = a * a;
	2) double a4 = a2 * a2;
	3) double a6 = a4 * a2;*/
	double a12 = a6 * a6;
	double a13 = a12 * a;
	
	//point ç):
	/*
	1) double a2 = a * a;
	2) double a4 = a2 * a2;
	3) double a5 = a4 * a;
	4) double a10 = a5 * a5;*/
	double a15 = a10 * a5;
	
	//point è):
	/*
	1) double a2 = a * a;
	2) double a4 = a2 * a2;
	3) double a6 = a4 * a2;
	4) double a7 = a6 * a;*/
	double a14 = a7 * a7;
	double a21 = a14 * a7;
	
	//point ê):
	/*
	1) double a2 = a * a;
	2) double a4 = a2 * a2;
	3) double a8 = a4 * a4;*/
	double a16 = a8 * a8;
	double a24 = a16 * a8;
	double a28 = a24 * a4;
	
	//point ë):
	/*
	1) double a2 = a * a;
	2) double a4 = a2 * a2;
	3) double a8 = a4 * a4;
	4) double a16 = a8 * a8;*/
	double a32 = a16 * a16;
	double a64 = a32 * a32;

	std::cout << "The value of a^4: " << a4 << '\n';
	std::cout << "The value of a^6: " << a6 << '\n';
	std::cout << "The value of a^7: " << a7 << '\n';
	std::cout << "The value of a^8: " << a8 << '\n';
	std::cout << "The value of a^9: " << a9 << '\n';
	std::cout << "The value of a^10: " << a10 << '\n';
	std::cout << "The value of a^13: " << a13 << '\n';
	std::cout << "The value of a^15: " << a15 << '\n';
	std::cout << "The value of a^21: " << a21 << '\n';
	std::cout << "The value of a^28: " << a28 << '\n';
	std::cout << "The value of a^64: " << a64 << '\n';
	return 0;
}