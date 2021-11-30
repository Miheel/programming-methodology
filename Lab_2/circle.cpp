#include "circle.hpp"

Circle::Circle(float radius)
	:radius(radius)
{
}

float Circle::getArea()
{
	return PI * radius * radius;
}
