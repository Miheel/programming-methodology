#include "shape.hpp"

Shape::Shape(const char * colour)
	:colour(colour)
{
}

const char* Shape::getColour() const
{
	return this->colour;
}
