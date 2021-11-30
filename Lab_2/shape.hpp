#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

class Shape
{
public:

	std::string getColour() const;
	virtual float getArea() = 0;

private:
	std::string colour;
};

#endif // !SHAPE_HPP
