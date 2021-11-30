#include "parallelepiped.hpp"

Parallelepiped::Parallelepiped(double width, double height, double length, const char* colour)
	:Rectangle(width, height, colour), length(length)
{
}


double Parallelepiped::getArea()
{
	return 2 * (length * Rectangle::width + length * Rectangle::height + Rectangle::getArea());
}

double Parallelepiped::getVolume()
{
	return length * Rectangle::getArea();
}
