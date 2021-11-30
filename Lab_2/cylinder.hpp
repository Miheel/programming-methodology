#ifndef CYLINDER_HPP
#define CYLINDER_HPP
#include "circle.hpp"

class Cylinder:public Circle
{
public:
	Cylinder(float radius, float height);

	float getArea() override;
	float getVolume();

	float height;
};

#endif // !CYLINDER_HPP
