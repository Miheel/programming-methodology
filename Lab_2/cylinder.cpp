#include "cylinder.hpp"

Cylinder::Cylinder(float radius, float height)
	:Circle(radius), height(height)
{
}

float Cylinder::getArea()
{
	return (2 * Circle::getArea()) + (2 * Circle::PI * Circle::radius * height);
}

float Cylinder::getVolume()
{
	return PI * Circle::radius * Circle::radius * height;
}
