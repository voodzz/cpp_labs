#include <iostream>
#include <cmath>

int main() {
	double x0, x1;
	double y0, y1;
	double r0, r1;
	double distance;

	std::cout << "Input x0, y0 and r0: ";
	std::cin >> x0 >> y0 >> r0;
	std::cout << "Input x1, y1 and r1: ";
	std::cin >> x1 >> y1 >> r1;

	if (x0 == x1 && y0 == y1 && r0 == r1) {
		std::cout << "The circles are identical.";
		return 0;
	}
	
	distance = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
	if ((distance > (r0 + r1)) || ((r0 + distance) < r1) || ((r1 + distance) < r0)) {
		std::cout << "The circles do not intersect.";
		return 0;
	}
	
	/* a is the distance between the center of the circle with r0 and the point (let's name it P2) where
	the line that connects the intersection points (P3 and P4) crosses the line that connects the centers:*/
	double a = (r0 * r0 - r1 * r1 + distance * distance) / (2 * distance);  
	double h = sqrt(r0 * r0 - a * a); //the height of the OP2P1 triangle
	
	//the coordinates of P2:
	double x2 = x0 + a * (x1 - x0) / distance; 
	double y2 = y0 + a * (y1 - y0) / distance;

	//the coordinates of P3:
	double x3 = x2 + h * (y1 - y0) / distance;
	double y3 = y2 - h * (x1 - x0) / distance;

	//the coordinates of P4:
	double x4 = x2 - h * (y1 - y0) / distance;
	double y4 = y2 + h * (x1 - x0) / distance;

	if (x3 == x4 && y3 == y4) {
		std::cout << "The circles have 1 point of intersection with the coordinates (" << x3 << "; " << y3 << ")\n";
	} else {
		std::cout << "The circles have 2 points of intersection with the coordinates (" << x3 << "; " << y3 << ") and ("
			<< x4 << "; " << y4 << ")\n";
	}
	
	return 0;
}