#include <iostream>

int main()
{
	int m;
	std::cout << "Enter the number of seconds since the beginning of the year: ";
	std::cin >> m;
	int days;
	days = m / (24 * 3600);    //the number of days since the beginning of the year
	m = m - (days * 24 * 3600);    //the number of seconds since the start of the current day
	int dozens_h;
	dozens_h = (m / 3600) / 10;
	int hours;
	hours = (m / 3600) % 10;
	int dozens_m;
	dozens_m = ((m - (dozens_h * 36000 + hours * 3600)) / 60) / 10;
	int minutes;
	minutes = ((m - (dozens_h * 36000 + hours * 3600)) / 60) % 10;
	int dozens_s;
	dozens_s = (m - (dozens_h * 36000 + hours * 3600 + dozens_m * 600 + minutes * 60)) / 10;
	int seconds;
	seconds = (m - (dozens_h * 36000 + hours * 3600 + dozens_m * 600 + minutes * 60)) % 10;
	std::cout << "It's currently " << dozens_h << hours << ":" << dozens_m 
	<< minutes << ":" << dozens_s << seconds << "\n";

	return 0;
}