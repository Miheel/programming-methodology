#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, const char* colour)
	:Shape(colour), width(width), height(height)
{
}

double Rectangle::getArea()
{
	return width * height;
}
