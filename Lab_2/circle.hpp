#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape
{
public:
	Circle(double radius, const char* colour = "transparant");

	double getArea() override;

	double radius;

	static constexpr double PI = 3.1415926535897932384626433832795028841971693993751058209749445;
};

#endif // !CIRCLE_HPP
