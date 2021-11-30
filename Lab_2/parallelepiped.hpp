#ifndef PARALLELEPIPED_HPP
#define PARALLELEPIPED_HPP
#include "rectangle.hpp"

class Parallelepiped: public Rectangle
{
public:
	Parallelepiped(double width, double height, double length, const char* colour = "transparant");

	double getArea() override;
	double getVolume();

	double length;
};

#endif // !PARALLELEPIPED_HPP
