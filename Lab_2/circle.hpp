#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape
{
public:
	Circle(float radius);

	float getArea() override;

	float radius;

	static constexpr float PI = 3.14159265359;
};

#endif // !CIRCLE_HPP
