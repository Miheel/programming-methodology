#ifndef CYLINDER_HPP
#define CYLINDER_HPP
#include "circle.hpp"

class Cylinder:public Circle
{
public:
	Cylinder(double radius, double height, const char* colour = "transparant");

	double getArea() override;
	double getVolume();

	double height;
};

#endif // !CYLINDER_HPP
