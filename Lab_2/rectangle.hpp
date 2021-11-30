#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
	Rectangle(float width, float height);

	float getArea() override;

	float width;
	float height;
};

#endif // !RECTANGLE_HPP
