#include "rectangle.hpp"

Rectangle::Rectangle(float width, float height)
	:width(width), height(height)
{
}

float Rectangle::getArea()
{
	return width * height;
}
