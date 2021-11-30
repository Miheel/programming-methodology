#ifndef PARALLELEPIPED_HPP
#define PARALLELEPIPED_HPP
#include "rectangle.hpp"

class Parallelepiped: public Rectangle
{
public:
	Parallelepiped(float width, float height, float length);

	float getArea() override;
	float getVolume();

	float length;
};

#endif // !PARALLELEPIPED_HPP
