#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle: public Shape
{
public:
	Circle(double radius, const char* colour = "transparant");

	double getArea() override;

	double radius;

	static constexpr long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481;
};

#endif // !CIRCLE_HPP
