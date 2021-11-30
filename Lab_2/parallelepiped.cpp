#include "parallelepiped.hpp"

Parallelepiped::Parallelepiped(float width, float height, float length)
	:Rectangle(width, height), length(length)
{
}

float Parallelepiped::getArea()
{
	return 2 * (length * Rectangle::width + length * Rectangle::height + Rectangle::getArea());
}

float Parallelepiped::getVolume()
{
	return length * Rectangle::getArea();
}
