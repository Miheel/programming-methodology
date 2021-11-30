#include "roundedRectangle.hpp"

RoundedRectangle::RoundedRectangle(float width, float height, float radius)
	:Rectangle(width, height), corner(radius)
{
}

float RoundedRectangle::getArea()
{
	return Rectangle::getArea() - corner.radius * corner.radius * (4 - corner.PI);
}
