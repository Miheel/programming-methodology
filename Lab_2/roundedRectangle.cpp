#include "roundedRectangle.hpp"

RoundedRectangle::RoundedRectangle( double width, double height, double radius, const char* colour)
	:Rectangle(width, height, colour), round_corner(radius)
{
}

double RoundedRectangle::getArea()
{
	Rectangle rect_corner(round_corner.radius, round_corner.radius);
	return Rectangle::getArea() - 4 * rect_corner.getArea() + round_corner.getArea();
}
