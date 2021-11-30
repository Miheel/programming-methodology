#include "roundedRectangle.hpp"

RoundedRectangle::RoundedRectangle( double width, double height, double radius, const char* colour)
	:Rectangle(width, height, colour), corner(radius)
{
}

double RoundedRectangle::getArea()
{
	return Rectangle::getArea() - corner.radius * corner.radius * (4 - corner.PI);
}
