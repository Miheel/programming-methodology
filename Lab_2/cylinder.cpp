#include "cylinder.hpp"

Cylinder::Cylinder(double radius, double height, const char* colour)
	:Circle(radius, colour), height(height)
{
}

double Cylinder::getArea()
{
	return (2 * Circle::getArea()) + (2 * Circle::PI * Circle::radius * height);
}

double Cylinder::getVolume()
{
	return PI * Circle::radius * Circle::radius * height;
}
