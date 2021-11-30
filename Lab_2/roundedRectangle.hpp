#ifndef ROUNDEDRECANGLE_HPP
#define ROUNDEDRECANGLE_HPP
#include "rectangle.hpp"
#include "circle.hpp"
class RoundedRectangle: public Rectangle
{
public:
	RoundedRectangle(float width, float height, float radius);

	float getArea() override;

	Circle corner;
};

#endif // !ROUNDEDRECANGLE_HPP
