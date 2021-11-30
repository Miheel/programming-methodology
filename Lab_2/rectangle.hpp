#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
	Rectangle(double width, double height, const char* colour = "transparant");

	double getArea() override;

	double width;
	double height;
};

#endif // !RECTANGLE_HPP
