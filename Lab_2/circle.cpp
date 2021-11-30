#include "circle.hpp"
#include <cmath>

Circle::Circle(double radius, const char* colour)
	:Shape(colour), radius(radius)
{
}

double Circle::getArea()
{
	return PI * radius * radius;
}
