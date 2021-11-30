#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

class Shape
{
public:
	explicit Shape(const char* colour);
	const char* getColour() const;
	virtual double getArea() = 0;

private:
	const char* colour;
};

#endif // !SHAPE_HPP
