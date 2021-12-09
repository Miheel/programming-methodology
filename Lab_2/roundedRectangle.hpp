#ifndef ROUNDEDRECANGLE_HPP
#define ROUNDEDRECANGLE_HPP
#include "rectangle.hpp"
#include "circle.hpp"
class RoundedRectangle: public Rectangle
{
public:
	RoundedRectangle(double width, double height, double radius, const char* colour = "transparant");

	double getArea() override;

	Circle round_corner;

};

#endif // !ROUNDEDRECANGLE_HPP
