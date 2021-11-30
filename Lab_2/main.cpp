#include <iostream>
#include "parallelepiped.hpp"
#include "roundedRectangle.hpp"
#include "cylinder.hpp"
int main()
{
	RoundedRectangle rrec(10, 4, 3);

	std::cout << "Area: " << rrec.getArea() << "\n";

	return 0;
}
